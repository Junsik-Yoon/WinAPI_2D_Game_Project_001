#include "pch.h"
#include "CScene_Start.h"
#include "CObject.h"
#include "CText.h"

CScene_Start::CScene_Start()
{
	
}

CScene_Start::~CScene_Start()
{
}
bool isFirstEnt = true;
void CScene_Start::Enter()
{
	if (true == isFirstEnt)
	{
		CObject* smallText = new CText;
		AddObject(smallText, GROUP_TYPE::DEFAULT);
		isFirstEnt = false;
	}
}

void CScene_Start::Exit()
{
	
}


