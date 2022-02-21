#pragma once
class CKeyManager
{
	SINGLETON(CKeyManager);

private:
	static const int VKEY_SIZE = 0xFF;		//VK�� �ִ� ����

	bool m_arrPrevKey[VKEY_SIZE];	//���� Ű�� �Է»��¸� ������ �迭
	bool m_arrCurKey[VKEY_SIZE];	//���� Ű�� �Է»��¸� ������ �迭

public:
	void update();
	void init();

	bool GetButton(const int key);		//Ű�� ������ ���¶�� true�� ��ȯ
	bool GetButtonDown(const int key);	//Ű�� ������ ������ true�� ��ȯ
	bool GetButtonUP(const int key);	//Ű�� �ö� ������ true�� ��ȯ

};

