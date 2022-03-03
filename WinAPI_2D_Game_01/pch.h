#pragma once
//Object Group
enum class GROUP_GAMEOBJ
{
	DEFAULT,
	PLAYER,
	MONSTER,
	MISSILE,

	SIZE, //enum의 마지막을 size나 end, length로 해놓으면 배열의 인덱스총개수로 사용하거나 for문을 돌릴 때 좋음
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

//Core DC GDI GROUP
enum class TYPE_PEN
{
	RED,
	GREEN,
	BLUE,

	SIZE,
};
enum class TYPE_BRUSH
{
	HOLLOW,
	

	SIZE,
};

//event group
enum class TYPE_EVENT
{
	CRAETE_OBJECT,
	DELETE_OBJECT,
	CHANGE_SCENE,
	
	SIZE,
};

#pragma comment(lib,"Msimg32.lib")



#include <string>
using std::string;
using std::wstring;
//STL
#include <vector>
using std::vector;

#include <map>
using std::map;
#include <list>
#include <chrono>


#include "Logger.h"
#include "framework.h"
#include <assert.h>
//
#include "CSingleton.h"
#include "CPathManager.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CResourceManager.h"
#include "CSceneManager.h"
#include "CCollisionManager.h"
#include "CEventManager.h"
#include "CCore.h"
#include "struct.h"
#include "SelectGDI.h"






//macro
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

#define EventCreateObj(obj,group) CEventManager::getInst()->EventCreateGameObject(obj,group);
#define EventDeleteObj(obj) CEventManager::getInst()->EventDeleteGameObject(obj);
#define CHANGESCENE(group) CEventManager::getInst()->EventChangeScene(group);

//전역변수
extern HINSTANCE hInst;
extern HWND hWnd;

//1.지역변수 : 함수 내 생성  /스택영역
//2.전역변수 : 함수 외부 전역에서 생성 /데이터영역
//3.정적변수 : 함수 내부에서 만들지만 데이터영역에 존재
//4.외부변수 : 다른곳에서 만들어진다
//5.멤버변수 : 클래스 안에서 선언되고 인스턴스가 생성될 당시에 만들어진다
