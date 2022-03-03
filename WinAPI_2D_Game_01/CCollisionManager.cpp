#include "pch.h"
#include "CCollisionManager.h"
#include "CGameObject.h"
#include "CScene.h"
#include "CCollider.h"
#include "CSceneManager.h"

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
			ID.left_id = pLeftCol->GetID();
			ID.right_id = pRightCol->GetID();

			iter = m_mapColInfo.find(ID.ID);
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
				if (true == iter->second) //�������� �浹�ϰ� �־���
				{
					//�浹ü �� �ϳ��� Dead���¶�� �浹 ����
					if (vecLeft[i]->isDead() || vecRight[j]->isDead())
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

					if (vecLeft[i]->isDead() || vecRight[j]->isDead())
					{
					}
					else
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

bool CCollisionManager::IsCollision(CCollider* pLeftCol, CCollider* pRightCol)

{
	fVec2 vLeftPos = pLeftCol->GetFinalPose();
	fVec2 vLeftScale = pLeftCol->GetScale();
	fVec2 vRightPos = pRightCol->GetFinalPose();
	fVec2 vRightScale = pRightCol->GetScale();

	if (abs(vRightPos.x - vLeftPos.x) < (vLeftScale.x + vRightScale.x) / 2.f &&
		abs(vRightPos.y - vLeftPos.y) < (vLeftScale.y + vRightScale.y) / 2.f)
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
	//üũ�� �׷쳢�� �浹�ϴ��� �˻�
	for (UINT iRow = 0; iRow < (UINT)GROUP_GAMEOBJ::SIZE; ++iRow)
	{
		for (UINT iCol = iRow; iCol < (UINT)GROUP_GAMEOBJ::SIZE; ++iCol)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{//�ɸ���
				CollisionGroupUpdate((GROUP_GAMEOBJ)iRow, (GROUP_GAMEOBJ)iCol);
			}
		}
	}
}

void CCollisionManager::CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	UINT iRow = (UINT)objLeft;
	UINT iCol = (UINT)objRight;
	if (iCol < iRow)
	{
		iRow = (UINT)objRight;
		iCol = (UINT)objLeft;
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

void CCollisionManager::UnCheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
{
	//[��][��]
	UINT y; //��
	UINT x; //��

	//�� ���� ���� ������ �д� -> ���ݸ� �������ؼ�
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
