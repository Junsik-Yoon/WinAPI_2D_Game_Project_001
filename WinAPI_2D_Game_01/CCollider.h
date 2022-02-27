#pragma once

class CObject;

class CCollider
{
private:

	static UINT g_iNextId;

	CObject* m_pOwner;	//collider�� �����ϰ� �ִ� ������Ʈ

	Vec2 m_vOffsetPos;	//������ġ(������Ʈ)�κ����� ������� ���̰�
	Vec2 m_vFinalPos;	//�浹��ġ�� ������ġ �� ������ finalupdate���� ���Ǵ� ��
	Vec2 m_vScale;		//�浹ü�� ũ��

	UINT m_iId;			//�浹ü�� ������ ID��
	int m_iCol;//�浹ī��Ʈ

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
	//�浹 ���� �Լ�
	void OnCollision(CCollider* _pOther); //�浹���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionEnter(CCollider* _pOther);//��� �浹�Ѱ�� ȣ��Ǵ� �Լ�
	void OnCollisionExit(CCollider* _pOther);//��� �浹���� ��� ���

	CCollider& operator = (CCollider& _origin) = delete;//���Կ����ڸ� ����Ҽ�����

public:
	CCollider();
	CCollider(const CCollider& _original);//���������
	~CCollider();
	friend class CObject;
};

