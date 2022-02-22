#pragma once

//define
#define fDT CTimeManager::getInst()->getfDT()
#define DT CTimeManager::getInst()->getDT()

#define KEY_CHECK(key, state) CKeyManager::getInst()->GetKeyState(key)==state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)

#define BSPEED 600//���ӵ�
#define SSPEED 300//����ӵ�


enum class GROUP_TYPE
{//���� �����ϴ� ������Ʈ���� �з�
	DEFAULT,//0

	END = 32,
};
enum class SCENE_TYPE
{//�� �з�

	TOOL,
	START,
	STAGE,
	ENDING,
	END,
};
//
#include "framework.h"

#include <string>
//STL
#include <vector>
#include <list>
#include <chrono>
using std::string;
using std::wstring;
using std::vector;
//
#include "CSingleton.h"
#include "CSceneManager.h"
#include "CKeyManager.h"
#include "CTimeManager.h"
#include "Logger.h"
#include "CCore.h"
#include "struct.h"

#include <Windows.h>


//macro
#define WINSTYLE WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU 
#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 1280
#define WINSIZEY 720

//��������
extern HINSTANCE hInst;
extern HWND hWnd;
extern fPoint vLPos;
extern fPoint vRPos;
extern fPoint vLScale;
extern fPoint vRScale;
extern int leftPoint;//���ʽ���
extern int rightPoint;//�����ʽ���