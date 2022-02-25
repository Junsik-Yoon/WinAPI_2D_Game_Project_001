#include "pch.h"
#include "CPathManager.h"

CPathManager::CPathManager()
{

}
CPathManager::~CPathManager()
{
}

void CPathManager::init()
{
	GetCurrentDirectory(MAXSIZE_PATH,m_szContentPath);//프로그램 경로를 확인하는 함수
	//경로: (게임 솔루션경로) \Output\Debug
	//경로: (게임 솔루션경로) \Output\Release
	//경로의 사이즈 구함
	int size = wcslen(m_szContentPath);
	for (int i = size - 1; i >= 0; --i)
	{
		if ('\\' == m_szContentPath[i])//역슬레시가 나올때까지 문자를 하나씩 뒤로가며 찾는다
		{
			m_szContentPath[i] = '\0'; //null문자가 나오면 
			break;//찾았으니 break;
		}
	}
	//경로:(게임 솔루션 경로)\Output
	//캐릭터배열은 string처럼 +연산을 할수가 없으므로
	wcscat_s(m_szContentPath, MAXSIZE_PATH, L"\\Release\\content\\");//wchar_t문자열뒤에 문자열을 붙여주는 함수

}

