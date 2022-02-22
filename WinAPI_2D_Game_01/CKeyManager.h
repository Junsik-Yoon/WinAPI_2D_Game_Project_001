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
	SPACE,//첫화면에서 스테이지로 들어가기
	ENTER,//처음화면으로 돌아가기
	ESC,//게임종료

	LAST,
};
struct tKeyInfo
{
	KEY_STATE	eState;//키의 상태값
	bool		bPrevPush; //이전 프레임에서 눌렸는지 여부
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
