#pragma once

class CGameObject;

class CCollider
{
public:
	CCollider();
	CCollider(const CCollider& other);
	~CCollider();

	CCollider& operator=(CCollider& other) = delete; //�Լ��� ����� �� ���� ����

	friend class CGameObject;
private:
	static UINT s_iID; //������ ������ ID��

	CGameObject* m_pOwner;
	fVec2 m_fptFinalPos;
	fVec2 m_fptOffset;
	fVec2 m_fptScale;

	UINT m_iID; //�浹ü�� ������ ID��

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

