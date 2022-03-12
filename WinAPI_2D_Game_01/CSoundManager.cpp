#include "pch.h"
#include "CSoundManager.h"
#include "CSound.h"


CSoundManager::CSoundManager()
{
	m_pSystem = nullptr;
}
CSoundManager::~CSoundManager()
{
	m_pSystem->close();
	m_pSystem->release();
}

void CSoundManager::init()
{
	FMOD_RESULT result;

	System_Create(&m_pSystem);
	result = m_pSystem->init(32, FMOD_INIT_NORMAL, nullptr);//ä���� 32���� �� ���� ä���� Ǯ������� �ƴϸ� �����۵�����
	assert(!result);

}

void CSoundManager::update()
{
	//�����Ӵ� ������Ʈ ������ �ؾ� �Ѵ�
	m_pSystem->update();
}

void CSoundManager::AddSound(wstring keyName, wstring filePath, bool bgm)
{
	CSound* pSound = CResourceManager::getInst()->LoadSound(keyName, filePath);
	pSound->SetLoop(bgm);
	m_mapSound.insert(make_pair(keyName, pSound));

}

void CSoundManager::Play(wstring keyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(keyName);
	if (iter == m_mapSound.end())
		return;
	iter->second->Play();
}

void CSoundManager::Stop(wstring keyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(keyName);
	if (iter == m_mapSound.end())
		return;
	iter->second->Stop();
}

void CSoundManager::Pause(wstring keyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(keyName);
	if (iter == m_mapSound.end())
		return;
	iter->second->Pause();
}

void CSoundManager::Resume(wstring keyName)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(keyName);
	if (iter == m_mapSound.end())
		return;
	iter->second->Resume();
}

bool CSoundManager::IsPlaySound(wstring keyname)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(keyname);
	if (iter == m_mapSound.end())
		assert(nullptr);
	return iter->second->IsPlay();
}

bool CSoundManager::IsPauseSound(wstring keyname)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(keyname);
	if (iter == m_mapSound.end())
		return false;
	return iter->second->IsPause();
}
