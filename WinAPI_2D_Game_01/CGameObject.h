#pragma once

class CCollider;
class CAnimator;

class CGameObject
{
private:
	fVec2 m_fptPos; //물체의좌표
	fVec2 m_fptScale;//물체의크기

	wstring m_strName;//상속받은 물체의 이름

	bool m_bAlive; //생사 확인

	void SetDead() { m_bAlive = false; }//죽은상태로 만들기
	friend class CEventManager;

	CCollider* m_pCollider;//충돌체
	CAnimator* m_pAnimator;//애니메이터 컴포넌트

public:
	CGameObject();
	CGameObject(const CGameObject& other);
	virtual ~CGameObject();
	virtual CGameObject* Clone()=0;

public:
	virtual void update()=0;//TODO: 순수가상함수처리
	virtual void finalupdate() final; //상속받은 클래스가 더이상 오버라이딩 하는 것을 막아주는 키워드 final
	virtual void render(HDC hDC);
	void component_render(HDC hDC);

	void SetPos(fVec2 pos)		{ m_fptPos		= pos; }
	void SetScale(fVec2 scale) { m_fptScale	= scale; }
	fVec2 GetPos()				{ return m_fptPos; }
	fVec2 GetScale()			{ return m_fptScale; }	
	void SetName(wstring str) { m_strName = str; }
	wstring GetName() { return m_strName; }

	bool isDead() { return !m_bAlive; }//dead인지 상태확인

public:
	
	void CreateCollider();
	CCollider* GetCollider() { return m_pCollider; }
	void CreateAnimator();
	CAnimator* GetAnimator() { return m_pAnimator; }

	virtual void OnCollision(CCollider* pOther) {}
	virtual void OnCollisionEnter(CCollider* pOther) {}
	virtual void OnCollisionExit(CCollider* pOther) {}
};

