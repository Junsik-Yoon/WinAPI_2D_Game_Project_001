#pragma once

class CGameObject;

class CCollider
{
public:
	CCollider();
	CCollider(const CCollider& other);
	~CCollider();

	CCollider& operator=(CCollider& other) = delete; //함수를 사용할 수 없게 막음

	friend class CGameObject;
private:
	static UINT s_iID; //데이터 영역에 ID값

	CGameObject* m_pOwner;
	fVec2 m_fptFinalPos;
	fVec2 m_fptOffset;
	fVec2 m_fptScale;

	UINT m_iID; //충돌체의 고유한 ID값

	int iCollCount;
	
public:

	void SetOffset(fVec2 _offset) { m_fptOffset = _offset; }
	fVec2 GetOffset(){ return m_fptOffset; }
	void SetScale(fVec2 _scale) { m_fptScale = _scale; }
	fVec2 GetScale() { return m_fptScale; }
	fVec2 GetFinalPose() { return m_fptFinalPos; }
	UINT GetID() { return m_iID; }
	CGameObject* GetGameObject() { return m_pOwner;  }
public:
	void finalupdate();
	void render(HDC hDC);

public:
	void OnCollision(CCollider* pOther);
	void OnCollisionEnter(CCollider* pOther);
	void OnCollisionExit(CCollider* pOther);

};

