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
		//�浹ü ������Ʈ�� ���� ��� ����
		if (nullptr == vecLeft[i]->GetCollider())
			continue;
		for (int j = 0; j < vecRight.size(); ++j)
		{
			//�浹ü ������Ʈ�� ���� ��� ����
			if (nullptr == vecRight[j]->GetCollider())
				continue;
			//�ڱ� �ڽŰ��� �浹 ����ó��
			if (vecLeft[i] == vecRight[j])
				continue;

			//�� �浹ü�� ID�� �̿��ؼ�, ������ Ű�� �����
			COLLIDER_ID id;
			id.left_id = vecLeft[i]->GetCollider()->GetID();
			id.right_id = vecRight[j]->GetCollider()->GetID();

			map<ULONGLONG, bool>::iterator iter = m_mapColInfo.find(id.ID);
			//�浹 ������ ���� ���(��, ó������ �浹�ϴ� ���) �浹���� ���� ���¸� �־���.
			if (m_mapColInfo.end() == iter)//find�������������
			{
				m_mapColInfo.insert(std::make_pair(id.ID, false));
				iter = m_mapColInfo.find(id.ID);
			}
			

			//�浹ó��
			if (IsCollision(vecLeft[i]->GetCollider(), vecRight[j]->GetCollider()))
			{
				//�浹��
				
				//prev0, cur0
				if (iter->second)
				{
					//�浹��
					//vecLeft[i]���� �浹���̶�� �˷�����ϰ�
					vecLeft[i]->GetCollider()->OnCollision(vecRight[j]->GetCollider());
					//vecRight[j]���� �浹���̶�� �˷�����Ѵ�
					vecRight[j]->GetCollider()->OnCollision(vecLeft[i]->GetCollider());
				}
				//prev x , cur 0
				else
				{
					//�浹�߻�
					vecLeft[i]->GetCollider()->OnCollisionEnter(vecRight[j]->GetCollider());
					vecRight[j]->GetCollider()->OnCollisionEnter(vecLeft[i]->GetCollider());
				}
				iter->second = true;
			}
			else
			{
				
				//�浹����
				//prev o , cur x
				if (iter->second)
				{
					//�浹����
					vecLeft[i]->GetCollider()->OnCollisionExit(vecRight[j]->GetCollider());
					vecRight[j]->GetCollider()->OnCollisionExit(vecLeft[i]->GetCollider());

				}
				iter->second = false;
				//prev x, cur x

					//�浹�̰�Ӿ�����
			}
		}
	}
}

bool CCollisionManager::IsCollision(CCollider* pLeftCol, CCollider* pRightCol)

{
	//�簢�浹
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
				//�浹�� �˻��ؾ� �ϴ� �� �׷�
				CollisionGroupUpdate((GROUP_GAMEOBJ)iRow,(GROUP_GAMEOBJ)iCol);
			}
		}
	}
}

void CCollisionManager::CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight)
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
	m_arrCheck[y] |= (1 << x); 


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
