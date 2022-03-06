#pragma once
#include "CGameObject.h"

class CTexture;
class CFoot;

enum class STATUS
{
	SMALL,
	LARGE,
	FLOWER,
	SIZE,
};



class CMario: public CGameObject
{
private:
	static float sCountTime;
	static float sCountTime2;
	static float sCountTime3;//�״¸�ǿ�
	
public:
	static int slife;
	static int Getlife() { return slife; }

	CFoot* m_foot;//TODO: �� ��ü�� ���� ���� �������� ���͸� ������ �߰� �������浹�̸� ���Ͱ� �װ� �������� ������ �浹�̸� �������� �װ� �ϰ� �;��µ� �߰�ü�� �������� ����ٴϰ� �ϰ�;��µ� �� �ȵǳ׿�..

	CTexture* m_pTex;
	float m_fVelocityUD;
	float m_fVelocityLR;
	STATUS m_type;

	bool isKillJump;
	bool isLittleJump; //���̰��� ������

	float m_fLittleVel;

	bool isBoost;
	float jumpBoost;

	bool is_dead;//����������üũ���

	bool isFacedRight;

	float m_fAcc; //����
	float m_fGrav;//�߷�
	bool isAir;
	bool isUpside;
	bool canJump;

public:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	//virtual void OnCollisionNone(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
	
public:
	void SetAcc(float acc) { m_fAcc = acc; }

	void SetLittleJump(bool isKilled) { isLittleJump = isKilled; isUpside = true; }

	void CreateFoot();
	CFoot* GetFoot() { return m_foot; }

public:
	virtual void update();
	virtual void render(HDC hDC);

public:
	CMario();
	~CMario();
	virtual CMario* Clone(){ return new CMario(*this); }
};

