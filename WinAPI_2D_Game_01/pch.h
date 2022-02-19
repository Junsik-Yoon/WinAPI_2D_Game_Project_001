#pragma once
#include "framework.h"
//STL
#include <vector>
#include <list>
#include <chrono>
using std::vector;
//
#include "CSingleton.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
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

//define
#define fDT CTimeManager::GetInst()->getfDT()
#define DT CTimeManager::GetInst()->getDT()