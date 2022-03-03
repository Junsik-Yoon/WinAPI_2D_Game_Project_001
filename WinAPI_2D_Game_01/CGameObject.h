#pragma once

class CCollider;
class CAnimator;

class CGameObject
{
private:
	fVec2 m_fptPos; //��ü����ǥ
	fVec2 m_fptScale;//��ü��ũ��

	wstring m_strName;//��ӹ��� ��ü�� �̸�

	bool m_bAlive; //���� Ȯ��

	void SetDead() { m_bAlive = false; }//�������·� �����
	friend class CEventManager;

	CCollider* m_pCollider;//�浹ü
	CAnimator* m_pAnimator;//�ִϸ����� ������Ʈ

public:
	CGameObject();
	CGameObject(const CGameObject& other);
	virtual ~CGameObject();
	virtual CGameObject* Clone()=0;

public:
	virtual void update()=0;//TODO: ���������Լ�ó��
	virtual void finalupdate() final; //��ӹ��� Ŭ������ ���̻� �������̵� �ϴ� ���� �����ִ� Ű���� final
	virtual void render(HDC hDC);
	void component_render(HDC hDC);

	void SetPos(fVec2 pos)		{ m_fptPos		= pos; }
	void SetScale(fVec2 scale) { m_fptScale	= scale; }
	fVec2 GetPos()				{ return m_fptPos; }
	fVec2 GetScale()			{ return m_fptScale; }	
	void SetName(wstring str) { m_strName = str; }
	wstring GetName() { return m_strName; }

	bool isDead() { return !m_bAlive; }//dead���� ����Ȯ��

public:
	
	void CreateCollider();
	CCollider* GetCollider() { return m_pCollider; }
	void CreateAnimator();
	CAnimator* GetAnimator() { return m_pAnimator; }

	virtual void OnCollision(CCollider* pOther) {}
	virtual void OnCollisionEnter(CCollider* pOther) {}
	virtual void OnCollisionExit(CCollider* pOther) {}
};

