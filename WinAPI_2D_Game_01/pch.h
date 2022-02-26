#pragma once
//Object Group
enum class GROUP_GAMEOBJ
{
	DEFAULT,
	PLAYER,
	MONSTER,
	MISSILE,

	SIZE,
};
//Scene Group
enum class GROUP_SCENE
{
	DEFAULT,
	START,
	STAGE1,
	STAGE2,
	TOOL,
	SIZE,
};
//라이브러리
#pragma comment(lib,"Msimg32.lib")


//STL, 기타
#include <string>
using std::string;
using std::wstring;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <list>
#include <chrono>
#include <assert.h>
#include "Logger.h"
#include "framework.h"

//
#include "CSingleton.h"
#include "CPathManager.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CResourceManager.h"
#include "CSceneManager.h"
#include "CCore.h"
#include "struct.h"

//매크로
#define WINSTYLE WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU 
#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 1280
#define WINSIZEY 720
//
#define fDT CTimeManager::getInst()->GetfDT()
#define DT CTimeManager::getInst()->GetDT()
#define KEY(vk_key) CKeyManager::getInst()->GetButton(vk_key)
#define KEYDOWN(vk_key) CKeyManager::getInst()->GetButtonDown(vk_key)
#define KEYUP(vk_key) CKeyManager::getInst()->GetButtonUp(vk_key)
//
#define PI 3.1415926535f


//핸들 전역변수
extern HINSTANCE hInst;
extern HWND hWnd;
