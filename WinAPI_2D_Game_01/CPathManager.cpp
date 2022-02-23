#include "pch.h"
#include "CPathManager.h"
#include "CCore.h"

CPathManager::CPathManager()
	:m_szContentPath{}
{

}
CPathManager::~CPathManager()
{

}

void CPathManager::init()
{
	//실행된 프로그램의 위치 -> 현재디렉토리를 받아올 수 있음
	GetCurrentDirectory(255, m_szContentPath); //현재 경로가 채워짐
	
	int iLen = wcslen(m_szContentPath);

	//상위폴더로 간 후
	for (int i = iLen - 1/*문자의최대길이-1부터*/; 0<=i; --i)
	{
		if ('\\' == m_szContentPath[i]) // \\구분문자를 발견하면
		{
			m_szContentPath[i] = '\0'; //null문자를 넣어서 끊어준다
			break;
		}
	}

	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");//문자를 이어붙이는 함수

	//+ 해당폴더\\지정해놓은리소스폴더\\
	
	//   abc\\abc\\abc\\abc
	//-> abc\\abd\\abd\0abc

											   
SetWindowText(hWnd, m_szContentPath);//창으로 확인하도록 임시로

}
