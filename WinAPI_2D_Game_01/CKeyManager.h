#pragma once


enum class KEY_STATE
{
	NONE,
	TAP,
	HOLD,
	AWAY,
};
enum class KEY
{
	//p2
	UP,
	DOWN,
	//p1
	W,
	S,

	//func
	SPACE,//ùȭ�鿡�� ���������� ����
	ENTER,//ó��ȭ������ ���ư���
	ESC,//��������

	LAST,
};
struct tKeyInfo
{
	KEY_STATE	eState;//Ű�� ���°�
	bool		bPrevPush; //���� �����ӿ��� ���ȴ��� ����
};
class CKeyManager
{
	SINGLETON(CKeyManager);
private:
	vector<tKeyInfo> m_vecKey;
public:
	void init();
	void update();

	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }
};
