#pragma once

class CGameObject;

class CCollider
{
	friend class CGameObject;

private:
	static UINT s_iID;

	CGameObject* m_pOwner;		// �浹ü�� ������ ���ӿ�����Ʈ�� �ּ�
	Vec2 m_fptOffsetPos;		// �浹ü�� ������(������)
	Vec2 m_fptFinalPos;			// �浹ü�� ���� ��ġ
	Vec2 m_fptScale;			// �浹ü�� ũ��
	int m_iColCount;			// �浹��

	UINT m_iID;					// �浹ü ������ ID ��

public:
	CCollider();
	CCollider(const CCollider& other);
	~CCollider();

	CGameObject* GetObj();
	Vec2 GetOffsetPos();
	Vec2 GetFinalPos();
	Vec2 GetScale();

	void SetOffsetPos(Vec2 offsetPos);
	void SetFinalPos(Vec2 finalPos);
	void SetScale(Vec2 scale);
	UINT GetID();

	CCollider& operator=(CCollider& other) = delete;	

	void finalupdate();
	void render(HDC hDC);

	// �浹 ���� �Լ�
	void OnCollision(CCollider* pOther);
	void OnCollisionEnter(CCollider* pOther);
	void OnCollisionExit(CCollider* pOther);
};

