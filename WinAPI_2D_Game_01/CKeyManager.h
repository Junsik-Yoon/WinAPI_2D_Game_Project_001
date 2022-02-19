#pragma once


//1.프레임 동기화
//동일 프레임 내에서 같은 키에 대해 동일한 이벤트를 가져간다
//2.키 입력 이벤트 처리
// tap, hold, away

enum class KEY_STATE
{
	NONE, //눌리지 않음 - 이전프레임도 안눌렸고 지금도 안눌림
	TAP,//막 누른 시점 - 이전프레임은 안눌렸고 지금은 눌림
	HOLD,//누르고 있는 - 이전프레임도 눌렸고 지금도 눌림
	AWAY,//막 뗀 시점 - 이젠프레임은 눌렸고 지금은 안눌림
};
enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,
	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,
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

	KEY_STATE GetKeyState(KEY _eKey){ return m_vecKey[(int)_eKey].eState; }
};

