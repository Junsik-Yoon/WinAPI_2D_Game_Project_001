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
	GetCurrentDirectory(MAXSIZE_PATH,m_szContentPath);//���α׷� ��θ� Ȯ���ϴ� �Լ�


}
