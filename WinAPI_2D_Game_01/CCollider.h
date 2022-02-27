#pragma once

class CObject;

class CCollider
{
private:

	static UINT g_iNextId;

	CObject* m_pOwner;	//collider를 소유하고 있는 오브젝트

	Vec2 m_vOffsetPos;	//기준위치(오브젝트)로부터의 상대적인 차이값
	Vec2 m_vFinalPos;	//충돌위치의 최종위치 매 프레임 finalupdate에서 계산되는 값
	Vec2 m_vScale;		//충돌체의 크기

	UINT m_iId;			//충돌체의 고유한 ID값
	int m_iCol;//충돌카운트

public:
	void SetOffsetPos(Vec2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vec2 _vScale) {m_vScale = _vScale;}
	Vec2 GetOffsetPos() { return m_vOffsetPos; }
	Vec2 GetScale() { return m_vScale; }
	
	UINT GetID() {return m_iId;}

	CObject* GetObj() { return m_pOwner; }

	Vec2 GetFinalPose() { return m_vFinalPos; }
public:
	void finalupdate();
	void render(HDC _dc);

public:
	//충돌 시점 함수
	void OnCollision(CCollider* _pOther); //충돌충인 경우 호출되는 함수
	void OnCollisionEnter(CCollider* _pOther);//방금 충돌한경우 호출되는 함수
	void OnCollisionExit(CCollider* _pOther);//방금 충돌에서 벗어난 경우

	CCollider& operator = (CCollider& _origin) = delete;//대입연산자를 사용할수없게

public:
	CCollider();
	CCollider(const CCollider& _original);//복사생성자
	~CCollider();
	friend class CObject;
};

