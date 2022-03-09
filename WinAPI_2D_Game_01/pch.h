#pragma once
//Object Group
enum class GROUP_GAMEOBJ
{
	DEFAULT,
	TILE,
	PLAYER,
	MONSTER,
	MISSILE_PLAYER,
	MISSILE_MONSTER,


	UI,
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


//GDI
enum class TYPE_BRUSH
{
	HOLLOW,

	SIZE,
};

enum class TYPE_PEN
{
	RED,
	GREEN,
	BLUE,

	SIZE,
};

//�̺�ƮŸ��
enum class TYPE_EVENT
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	CHANGE_SCENE,

	SIZE,
};

//���̺귯��
#pragma comment(lib,"Msimg32.lib")


//STL, ��Ÿ
#include <string>
using std::string;
using std::wstring;
#include <vector>
using std::vector;
using std::make_pair;
#include <map>
using std::map;
#include <list>
using std::list;
#include <chrono>
#include <assert.h>
#include "Logger.h"
#include "framework.h"
#include "struct.h"
//
#include "CSingleton.h"
//
#include "CCore.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CPathManager.h"
#include "CCollisionManager.h"
#include "CEventManager.h"
#include "CResourceManager.h"
#include "CCameraManager.h"
#include "CUIManager.h"


//��ũ��
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
#define MousePos()		CKeyManager::getInst()->GetMousePos()
//
#define CreateObj(pObj, group)	CEventManager::getInst()->EventCreateObject(pObj, group)
#define DeleteObj(pObj)			CEventManager::getInst()->EventDeleteObject(pObj)
#define ChangeScn(scene)		CEventManager::getInst()->EventChangeScene(scene)
//
#define PI 3.1415926535f


//�ڵ� ��������
extern HINSTANCE hInst;
extern HWND hWnd;
