#pragma once

class CCollider;

class CObject
{
private:
	wstring m_strName;

	Vec2 m_vPos;
	Vec2 m_vScale;

	CCollider* m_pCollider;

	bool m_bAlive; //자기자신이 활성화인지 비활성화인지 daed 상태값을 체크
public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; };
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; };
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; };

	CCollider* GetCollider() { return m_pCollider; }

	bool IsDead() { return !m_bAlive; }

	void CreateCollider();


	//충돌 시점 함수
	virtual void OnCollision(CCollider* _pOther) {} //충돌충인 경우 호출되는 함수
	virtual void OnCollisionEnter(CCollider* _pOther) {}//방금 충돌한경우 호출되는 함수
	virtual void OnCollisionExit(CCollider* _pOther) {}//방금 충돌에서 벗어난 경우
	//필요하면 자식에서 오버라이딩 해서 쓰도록


public:
	virtual void update()=0;
	virtual void finalupdate()final;
	virtual void render(HDC _dc);

	void component_render(HDC _dc);
public:
	CObject();
	virtual ~CObject();


private:
	void SetDead() { m_bAlive = false; }; //데드로 설정하게
	friend class CEventManager;

};



