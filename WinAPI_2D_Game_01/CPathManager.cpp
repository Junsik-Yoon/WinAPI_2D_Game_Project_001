#include "pch.h"
#include "CPathManager.h"

CPathManager::CPathManager()
{

}
CPathManager::~CPathManager()
{
	m_szContentPath[0] = {};
}

void CPathManager::init()
{
	GetCurrentDirectory(MAXSIZE_PATH,m_szContentPath);//프로그램 경로를 확인하는 함수


}
