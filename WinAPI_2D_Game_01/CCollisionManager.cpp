#include "pch.h"
#include "CCollisionManager.h"

#include "CSceneManager.h"
#include "CScene.h"
#include "CObject.h"
#include "CCollider.h"



CCollisionManager::CCollisionManager()
	:m_arrCheck{}
{

}
CCollisionManager::~CCollisionManager()
{

}
void CCollisionManager::update()
{
	//체크된 그룹끼리 충돌하는지 검사
	for (UINT iRow = 0; iRow < (UINT)GROUP_TYPE::END; ++iRow)
	{
		for (UINT iCol = iRow; iCol < (UINT)GROUP_TYPE::END; ++iCol)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{//걸리면
				CollisionGroupUpdate((GROUP_TYPE)iRow,(GROUP_TYPE)iCol);
			}
		}
	}

}
void CCollisionManager::CollisionGroupUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	CScene* pCurScene = CSceneManager::GetInst()->GetCurScene();
	const vector<CObject*>& vecLeft = pCurScene->GetGroupObject(_eLeft);
	const vector<CObject*>& vecRight = pCurScene->GetGroupObject(_eRight);
	map<ULONGLONG, bool>::iterator iter;
	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		if (nullptr == vecLeft[i]->GetCollider()) //i번째 물체가 충돌체가 없다면
			continue;
		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			if (nullptr == vecRight[j]->GetCollider() //i번째 물체랑 충돌할 j가 충돌체가없다면
				//만약 같은 그룹끼리 충돌을 하게 한다면 꼭 자기자신이 자신과 충돌하는것을 예외처리해야한다
				|| vecLeft[i] == vecRight[j]) //또는 자기자신과 같은경우
			{
				continue;
			}

			CCollider* pLeftCol = vecLeft[i]->GetCollider();
			CCollider* pRightCol = vecRight[j]->GetCollider();

			//두 충돌체 조합 아이디 생성
			COLLIDER_ID ID;
			ID.Left_id = pLeftCol->GetID();
			ID.Right_id = pRightCol->GetID();
			
			iter =m_mapColInfo.find(ID.ID);
			//ID.ID;//두충돌체간의고유조합ID -> 맵의 키값으로

			//충돌정보가 미등록상태인 경우 등록(충돌하지 않았다로)
			if (m_mapColInfo.end() == iter)//이전프레임에 충돌한 적이 없다||아얘 등록조차 된 적이 없다(최초검사)
			{
				m_mapColInfo.insert(std::make_pair(ID.ID, false));
				iter = m_mapColInfo.find(ID.ID);
			}

			if (IsCollision(pLeftCol, pRightCol))
			{//충돌
				//iter->second; //이전프레임정보

				//현재 충돌중이다
				if (true==iter->second) //이전에도 충돌하고 있었다
				{

					if (vecLeft[i]->IsDead() || vecRight[j]->IsDead())
					{
						//근데 둘 중 하나가 삭제예정이라면, 충돌을 해제시켜준다
						pLeftCol->OnCollisionExit(pRightCol);
						pRightCol->OnCollisionExit(pLeftCol);
						iter->second = false;
					}
					else
					{
						pLeftCol->OnCollision(pRightCol);
						pRightCol->OnCollision(pLeftCol);
					}
				}
				else//이전에는 충돌하지 않았다
				{//처음 충돌함 , 딱만남
						//근데 둘 중 하나가 삭제예정이라면, 충돌하지 않은것으로 취급한다
					if (!vecLeft[i]->IsDead() && !vecRight[j]->IsDead())
					{
					
						pLeftCol->OnCollisionEnter(pRightCol);
						pRightCol->OnCollisionEnter(pLeftCol);
						iter->second = true;//충돌함으로 토글
					}
					

				}
			}
			else
			{//비충돌
				//현재 충돌하고 있지 않다
				if (true == iter->second)
				{
					//이전에는 충돌하고 있었다 -> 이번 프레임에 충돌이 벗어나진 시점
					pLeftCol->OnCollisionExit(pRightCol);
					pRightCol->OnCollisionExit(pLeftCol);
					iter->second = false;//충돌안함으로 토글
				}
			}
		}
	}
	
}

bool CCollisionManager::IsCollision(CCollider* _pLeftCol, CCollider* _pRightCol)
{
	Vec2 vLeftPos = _pLeftCol->GetFinalPose();
	Vec2 vLeftScale = _pLeftCol->GetScale();
	Vec2 vRightPos = _pRightCol->GetFinalPose();
	Vec2 vRightScale = _pRightCol->GetScale();
	
	if (abs(vRightPos.x - vLeftPos.x) < (vLeftScale.x + vRightScale.x) / 2.f &&
		abs(vRightPos.y - vLeftPos.y) < (vLeftScale.y + vRightScale.y) / 2.f)
	{
		return true;
	}
	return false;
}

void CCollisionManager::CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	//더 작은 값의 그룹타입을 행으로,
	//큰 값을 열(비트)로 사용
	UINT iRow = (UINT)_eLeft;
	UINT iCol = (UINT)_eRight;
	if (iCol < iRow)
	{
		iRow = (UINT)_eRight;
		iCol = (UINT)_eLeft;
	}
	if (m_arrCheck[iRow] & (1 << iCol))//이미 비트가 채워져있었다면
	{
		m_arrCheck[iRow] &= ~(1 << iCol);//비트를 빼고
	}
	else
	{
		m_arrCheck[iRow] |= (1 << iCol);//아니면 비트를 넣는다
	}

	
}

void CCollisionManager::Reset()
{//배열을 0으로 밈
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);//memset() 지정한 주소를 지정한 값으로 바이트단위로 세팅
}


