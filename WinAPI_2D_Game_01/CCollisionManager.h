#pragma once

class CCollider;

//����ü: ���ο� ������ �������� ���� �����ּҸ� ���´�
union COLLIDER_ID
{
	struct
	{
		UINT left_id;		
		UINT right_id;		
	};
	ULONGLONG ID;			//left_id(���ڸ�)+right_id(���ڸ�)
};

class CCollisionManager
{
	SINGLETON(CCollisionManager);
private:
	
	UINT m_arrCheck[(UINT)GROUP_GAMEOBJ::SIZE];//�浹�ؾ��ϴ� �׷���� ���� �迭
	map<ULONGLONG, bool> m_mapColInfo;		//�浹ü ���� ���� �浹 ����

	void CollisionGroupUpdate(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);
	bool IsCollision(CCollider* pLeftCol, CCollider* pRightCol);
public:
	void init();
	void update();
	void CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight); //�׷찣 �浹 ����
	void UnCheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);//�׷찣 �浹 ����
	void Reset(); 



};

