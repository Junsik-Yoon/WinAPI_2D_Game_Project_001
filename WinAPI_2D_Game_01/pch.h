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
#include "CCore.h"
#include "struct.h"







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

//��������
extern HINSTANCE hInst;
extern HWND hWnd;

//1.�������� : �Լ� �� ����  /���ÿ���
//2.�������� : �Լ� �ܺ� �������� ���� /�����Ϳ���
//3.�������� : �Լ� ���ο��� �������� �����Ϳ����� ����
//4.�ܺκ��� : �ٸ������� ���������
//5.������� : Ŭ���� �ȿ��� ����ǰ� �ν��Ͻ��� ������ ��ÿ� ���������
