#pragma once
class CKeyManager
{
	SINGLETON(CKeyManager);

private:
	static const int VKEY_SIZE = 0xFF;	

	bool m_arrPrevKey[VKEY_SIZE];	//���� Ű�� �Է»��¸� ������ �迭
	bool m_arrCurKey[VKEY_SIZE];	//���� Ű�� �Է»��¸� ������ �迭
	Vec2 m_fptCurMousePos;			// ���콺 ��ǥ

public:
	void update();
	void init();

	bool GetButton(const int key)		{ return (true == m_arrCurKey[key] && true == m_arrPrevKey[key]); }		//Ű�� ������ ���¶�� true�� ��ȯ
	bool GetButtonDown(const int key)	{ return (true == m_arrCurKey[key] && false == m_arrPrevKey[key]); }	//Ű�� ������ ������ true�� ��ȯ
	bool GetButtonUP(const int key)		{ return (false == m_arrCurKey[key] && true == m_arrPrevKey[key]); }	//Ű�� �ö� ������ true�� ��ȯ
	Vec2 GetMousePos()					{ return m_fptCurMousePos; }											// ���콺 ��ǥ ���

};

