#include "pch.h"
#include "CCollisionManager.h"
#include "CGameObject.h"
#include "CScene.h"
#include "CCollider.h"

CCollisionManager::CCollisionManager()
{
	m_arrCheck[0] = 0;
}
CCollisionManager::~CCollisionManager()
{

}


void CCollisionManager::CollisionGroupUpdate(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	const vector<CGameObject*>& vecLeft = pCurScene->GetGroupObject(objLeft);
	const vector<CGameObject*>& vecRight = pCurScene->GetGroupObject(objRight);

	for (int i = 0; i < vecLeft.size(); ++i)
	{
		//충돌체 컴포넌트가 없는 경우 무시
		if (nullptr == vecLeft[i]->GetCollider())
			continue;
		for (int j = 0; j < vecRight.size(); ++j)
		{
			//충돌체 컴포넌트가 없는 경우 무시
			if (nullptr == vecRight[j]->GetCollider())
				continue;
			//자기 자신과의 충돌 예외처리
			if (vecLeft[i] == vecRight[j])
				continue;

			//두 충돌체의 ID를 이용해서, 유일한 키를 만들기
			COLLIDER_ID id;
			id.left_id = vecLeft[i]->GetCollider()->GetID();
			id.right_id = vecRight[j]->GetCollider()->GetID();

			map<ULONGLONG, bool>::iterator iter = m_mapColInfo.find(id.ID);
			//충돌 정보가 없는 경우(즉, 처음으로 충돌하는 경우) 충돌하지 않은 상태를 넣어줌.
			if (m_mapColInfo.end() == iter)//find하지못했을경우
			{
				m_mapColInfo.insert(std::make_pair(id.ID, false));
				iter = m_mapColInfo.find(id.ID);
			}
			

			//충돌처리
			if (IsCollision(vecLeft[i]->GetCollider(), vecRight[j]->GetCollider()))
			{
				//충돌함
				
				//prev0, cur0
				if (iter->second)
				{
					//충돌중
					//vecLeft[i]에도 충돌중이라고 알려줘야하고
					vecLeft[i]->GetCollider()->OnCollision(vecRight[j]->GetCollider());
					//vecRight[j]에도 충돌중이라고 알려줘야한다
					vecRight[j]->GetCollider()->OnCollision(vecLeft[i]->GetCollider());
				}
				//prev x , cur 0
				else
				{
					//충돌발생
					vecLeft[i]->GetCollider()->OnCollisionEnter(vecRight[j]->GetCollider());
					vecRight[j]->GetCollider()->OnCollisionEnter(vecLeft[i]->GetCollider());
				}
				iter->second = true;
			}
			else
			{
				
				//충돌안함
				//prev o , cur x
				if (iter->second)
				{
					//충돌해제
					vecLeft[i]->GetCollider()->OnCollisionExit(vecRight[j]->GetCollider());
					vecRight[j]->GetCollider()->OnCollisionExit(vecLeft[i]->GetCollider());

				}
				iter->second = false;
				//prev x, cur x

					//충돌이계속없었음
			}
		}
	}
}

bool CCollisionManager::IsCollision(CCollider* pLeftCol, CCollider* pRightCol)

{
	//사각충돌
	fVec2 fptLeftPos = pLeftCol->GetFinalPose();
	fVec2 fptLeftScale = pLeftCol->GetScale();

	fVec2 fptRightPos = pRightCol->GetFinalPose();
	fVec2 fptRightScale = pRightCol->GetScale();
	if (abs(fptLeftPos.x - fptRightPos.x) < (fptLeftScale.x + fptRightScale.x) / 2.f
		&& abs(fptLeftPos.y - fptRightPos.y) < (fptLeftScale.y + fptRightScale.y) / 2.f)
	{
		return true;
	}
	return false;
}




void CCollisionManager::init()
{
}

void CCollisionManager::update()
{
	for (int iRow = 0; iRow < (UINT)GROUP_GAMEOBJ::SIZE; ++iRow)
	{
		for (int iCol = iRow; iCol < (UINT)GROUP_GAMEOBJ::SIZE; ++iCol)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				//충돌을 검사해야 하는 두 그룹
				CollisionGroupUpdate((GROUP_GAMEOBJ)iRow,(GROUP_GAMEOBJ)iCol);
			}
		}
	}
}

void CCollisionManager::CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	//[행][렬]
	UINT y; //열
	UINT x; //행

	//더 작은 수를 행으로 둔다 -> 절반만 쓰기위해서
	if ((UINT)objLeft > (UINT)objRight)
	{
		y = (UINT)objLeft;
		x = (UINT)objRight;
	}
	else
	{
		y = (UINT)objRight;
		x = (UINT)objLeft;
	}
	m_arrCheck[y] |= (1 << x); 


}

void CCollisionManager::UnCheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	//[행][렬]
	UINT y; //행
	UINT x; //열

	//더 작은 수를 행으로 둔다 -> 절반만 쓰기위해서
	if ((UINT)objLeft > (UINT)objRight)
	{
		y = (UINT)objLeft;
		x = (UINT)objRight;
	}
	else
	{
		y = (UINT)objRight;
		x = (UINT)objLeft;
	}
	m_arrCheck[y] &= ~(1 << x); 
}

void CCollisionManager::Reset()
{
	memset(m_arrCheck,0,sizeof(UINT) * (UINT)GROUP_GAMEOBJ::SIZE);
}
