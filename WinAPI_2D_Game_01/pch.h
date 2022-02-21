#pragma once

#include "framework.h"
//
#include "CSingleton.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "Logger.h"
#include "CCore.h"
#include "struct.h"


//Object Group
enum class GROUP_GAMEOBJ
{
	DEFAULT,
	PLAYER,
	MONSTER,
	MISSILE,

	SIZE,
};

#include <string>
using std::string;
using std::wstring;
//STL
#include <vector>
using std::vector;
#include <list>
#include <chrono>


//macro
#define WINSTYLE WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU 
#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 1280
#define WINSIZEY 720

//
#define DT CTimeManager::getInst()->GetDT()
#define KEY(vk_key) CKeyManager::getInst()->GetButton(vk_key)
#define KEYDOWN(vk_key) CKeyManager::getInst()->GetButtonDown(vk_key)
#define KEYUP(vk_key) CKeyManager::getInst()->GetButtonUp(vk_key)

//전역변수
extern HINSTANCE hInst;
extern HWND hWnd;

//1.지역변수 : 함수 내 생성  /스택영역
//2.전역변수 : 함수 외부 전역에서 생성 /데이터영역
//3.정적변수 : 함수 내부에서 만들지만 데이터영역에 존재
//4.외부변수 : 다른곳에서 만들어진다
//5.멤버변수 : 클래스 안에서 선언되고 인스턴스가 생성될 당시에 만들어진다
