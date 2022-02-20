#pragma once

//define
#define fDT CTimeManager::GetInst()->getfDT()
#define DT CTimeManager::GetInst()->getDT()

enum class GROUP_TYPE
{//씬에 존재하는 오브젝트들을 분류
	DEFAULT,//0

	PLAYER,//1
	MISSILE,//2
	MONSTER,//3


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

//전역변수
extern HINSTANCE hInst;
extern HWND hWnd;

//1.지역변수 : 함수 내 생성  /스택영역
//2.전역변수 : 함수 외부 전역에서 생성 /데이터영역
//3.정적변수 : 함수 내부에서 만들지만 데이터영역에 존재
//4.외부변수 : 다른곳에서 만들어진다
//5.멤버변수 : 클래스 안에서 선언되고 인스턴스가 생성될 당시에 만들어진다

