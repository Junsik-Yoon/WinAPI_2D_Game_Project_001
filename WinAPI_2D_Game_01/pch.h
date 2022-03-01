#pragma once

//define
#define fDT CTimeManager::GetInst()->getfDT()
#define DT CTimeManager::GetInst()->getDT()

#define KEY_CHECK(key, state) CKeyManager::GetInst()->GetKeyState(key)==state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)

#define PI 3.1415926535f

enum class GROUP_TYPE
{//씬에 존재하는 오브젝트들을 분류
	DEFAULT,//0
	PLAYER,//1
	MONSTER,//2
	PROJ_PLAYER,//3
	PROJ_MONSTER,//4

	END = 32,
};
enum class SCENE_TYPE
{//씬 분류

	TOOL,
	START,
	STAGE_01,
	STAGE_02,
	END,
};
//
enum class BRUSH_TYPE
{
	HOLLOW,
	END,
};
enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END,
};

enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	
	END,
};

#include "framework.h"

#include <string>
#include <assert.h>
#include <math.h>
#pragma comment (lib, "MSimg32.lib")
//STL
#include <map>
#include <vector>
#include <list>
#include <chrono>
using std::map;
using std::string;
using std::wstring;
using std::vector;
//
#include "CSingleton.h"
#include "Logger.h"
#include "CCore.h"
#include "struct.h"
#include "func.h"

#include <Windows.h>


//macro
#define WINSTYLE WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU 
#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 1280
#define WINSIZEY 720

//전역변수
extern HINSTANCE hInst;
extern HWND hWnd;


