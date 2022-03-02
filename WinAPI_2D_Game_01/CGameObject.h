#pragma once

class CCollider;

class CGameObject
{
private:
	fVec2 m_fptPos; //물체의좌표
	fVec2 m_fptScale;//물체의크기

	CCollider* m_pCollider;//충돌체

public:
	CGameObject();
	virtual ~CGameObject();

public:
	virtual void update()=0;//TODO: 순수가상함수처리
	virtual void finalupdate() final; //상속받은 클래스가 더이상 오버라이딩 하는 것을 막아주는 키워드 final
	virtual void render(HDC hDC);
	void component_render(HDC hDC);

	void SetPos(fVec2 pos)		{ m_fptPos		= pos; }
	void SetScale(fVec2 scale) { m_fptScale	= scale; }
	fVec2 GetPos()				{ return m_fptPos; }
	fVec2 GetScale()			{ return m_fptScale; }
	CCollider* GetCollider() { return m_pCollider; }

public:
	
	void CreateCollider();

	virtual void OnCollision(CCollider* pOther) {}
	virtual void OnCollisionEnter(CCollider* pOther) {}
	virtual void OnCollisionExit(CCollider* pOther) {}
};

