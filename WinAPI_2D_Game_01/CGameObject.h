#pragma once

class CCollider;

class CGameObject
{
private:
	fVec2 m_fptPos; //��ü����ǥ
	fVec2 m_fptScale;//��ü��ũ��

	CCollider* m_pCollider;//�浹ü

public:
	CGameObject();
	virtual ~CGameObject();

public:
	virtual void update()=0;//TODO: ���������Լ�ó��
	virtual void finalupdate() final; //��ӹ��� Ŭ������ ���̻� �������̵� �ϴ� ���� �����ִ� Ű���� final
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

