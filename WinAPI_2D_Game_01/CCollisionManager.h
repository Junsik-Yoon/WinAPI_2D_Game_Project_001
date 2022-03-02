#pragma once

class CCollider;

//공용체: 내부에 구현된 변수들은 같은 시작주소를 같는다
union COLLIDER_ID
{
	struct
	{
		UINT left_id;		
		UINT right_id;		
	};
	ULONGLONG ID;			//left_id(앞자리)+right_id(뒷자리)
};

class CCollisionManager
{
	SINGLETON(CCollisionManager);
private:
	
	UINT m_arrCheck[(UINT)GROUP_GAMEOBJ::SIZE];//충돌해야하는 그룹들을 가진 배열
	map<ULONGLONG, bool> m_mapColInfo;		//충돌체 간의 이전 충돌 정보

	void CollisionGroupUpdate(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);
	bool IsCollision(CCollider* pLeftCol, CCollider* pRightCol);
public:
	void init();
	void update();
	void CheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight); //그룹간 충돌 설정
	void UnCheckGroup(GROUP_GAMEOBJ objLeft, GROUP_GAMEOBJ objRight);//그룹간 충돌 해제
	void Reset(); 



};

