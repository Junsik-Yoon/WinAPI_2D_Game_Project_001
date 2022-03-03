#pragma once
//Object Group
enum class GROUP_GAMEOBJ
{
	DEFAULT,
	PLAYER,
	MONSTER,
	MISSILE,

	SIZE, //enum�� �������� size�� end, length�� �س����� �迭�� �ε����Ѱ����� ����ϰų� for���� ���� �� ����
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

//��������
extern HINSTANCE hInst;
extern HWND hWnd;

//1.�������� : �Լ� �� ����  /���ÿ���
//2.�������� : �Լ� �ܺ� �������� ���� /�����Ϳ���
//3.�������� : �Լ� ���ο��� �������� �����Ϳ����� ����
//4.�ܺκ��� : �ٸ������� ���������
//5.������� : Ŭ���� �ȿ��� ����ǰ� �ν��Ͻ��� ������ ��ÿ� ���������
