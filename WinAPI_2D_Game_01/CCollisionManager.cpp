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
	//üũ�� �׷쳢�� �浹�ϴ��� �˻�
	for (UINT iRow = 0; iRow < (UINT)GROUP_TYPE::END; ++iRow)
	{
		for (UINT iCol = iRow; iCol < (UINT)GROUP_TYPE::END; ++iCol)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{//�ɸ���
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
		if (nullptr == vecLeft[i]->GetCollider()) //i��° ��ü�� �浹ü�� ���ٸ�
			continue;
		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			if (nullptr == vecRight[j]->GetCollider() //i��° ��ü�� �浹�� j�� �浹ü�����ٸ�
				//���� ���� �׷쳢�� �浹�� �ϰ� �Ѵٸ� �� �ڱ��ڽ��� �ڽŰ� �浹�ϴ°��� ����ó���ؾ��Ѵ�
				|| vecLeft[i] == vecRight[j]) //�Ǵ� �ڱ��ڽŰ� �������
			{
				continue;
			}

			CCollider* pLeftCol = vecLeft[i]->GetCollider();
			CCollider* pRightCol = vecRight[j]->GetCollider();

			//�� �浹ü ���� ���̵� ����
			COLLIDER_ID ID;
			ID.Left_id = pLeftCol->GetID();
			ID.Right_id = pRightCol->GetID();
			
			iter =m_mapColInfo.find(ID.ID);
			//ID.ID;//���浹ü���ǰ�������ID -> ���� Ű������

			//�浹������ �̵�ϻ����� ��� ���(�浹���� �ʾҴٷ�)
			if (m_mapColInfo.end() == iter)//���������ӿ� �浹�� ���� ����||�ƾ� ������� �� ���� ����(���ʰ˻�)
			{
				m_mapColInfo.insert(std::make_pair(ID.ID, false));
				iter = m_mapColInfo.find(ID.ID);
			}

			if (IsCollision(pLeftCol, pRightCol))
			{//�浹
				//iter->second; //��������������

				//���� �浹���̴�
				if (true==iter->second) //�������� �浹�ϰ� �־���
				{

					if (vecLeft[i]->IsDead() || vecRight[j]->IsDead())
					{
						//�ٵ� �� �� �ϳ��� ���������̶��, �浹�� ���������ش�
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
				else//�������� �浹���� �ʾҴ�
				{//ó�� �浹�� , ������
						//�ٵ� �� �� �ϳ��� ���������̶��, �浹���� ���������� ����Ѵ�
					if (!vecLeft[i]->IsDead() && !vecRight[j]->IsDead())
					{
					
						pLeftCol->OnCollisionEnter(pRightCol);
						pRightCol->OnCollisionEnter(pLeftCol);
						iter->second = true;//�浹������ ���
					}
					

				}
			}
			else
			{//���浹
				//���� �浹�ϰ� ���� �ʴ�
				if (true == iter->second)
				{
					//�������� �浹�ϰ� �־��� -> �̹� �����ӿ� �浹�� ����� ����
					pLeftCol->OnCollisionExit(pRightCol);
					pRightCol->OnCollisionExit(pLeftCol);
					iter->second = false;//�浹�������� ���
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
	//�� ���� ���� �׷�Ÿ���� ������,
	//ū ���� ��(��Ʈ)�� ���
	UINT iRow = (UINT)_eLeft;
	UINT iCol = (UINT)_eRight;
	if (iCol < iRow)
	{
		iRow = (UINT)_eRight;
		iCol = (UINT)_eLeft;
	}
	if (m_arrCheck[iRow] & (1 << iCol))//�̹� ��Ʈ�� ä�����־��ٸ�
	{
		m_arrCheck[iRow] &= ~(1 << iCol);//��Ʈ�� ����
	}
	else
	{
		m_arrCheck[iRow] |= (1 << iCol);//�ƴϸ� ��Ʈ�� �ִ´�
	}

	
}

void CCollisionManager::Reset()
{//�迭�� 0���� ��
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);//memset() ������ �ּҸ� ������ ������ ����Ʈ������ ����
}


