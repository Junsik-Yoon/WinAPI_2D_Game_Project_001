#pragma once

//define
#define fDT CTimeManager::GetInst()->getfDT()
#define DT CTimeManager::GetInst()->getDT()

enum class GROUP_TYPE
{//���� �����ϴ� ������Ʈ���� �з�
	DEFAULT,//0

	PLAYER,//1
	MISSILE,//2
	MONSTER,//3


	END = 32,
};
enum class SCENE_TYPE
{//�� �з�

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

//��������
extern HINSTANCE hInst;
extern HWND hWnd;

//1.�������� : �Լ� �� ����  /���ÿ���
//2.�������� : �Լ� �ܺ� �������� ���� /�����Ϳ���
//3.�������� : �Լ� ���ο��� �������� �����Ϳ����� ����
//4.�ܺκ��� : �ٸ������� ���������
//5.������� : Ŭ���� �ȿ��� ����ǰ� �ν��Ͻ��� ������ ��ÿ� ���������

