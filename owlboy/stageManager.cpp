#include "stdafx.h"
#include "stageManager.h"


HRESULT stageManager::init(void)
{
	_currentStage = NULL;

	return S_OK;
}
void stageManager::release(void)
{

}


void stageManager::insertStage(string name, stage* newStage)
{
	_mStage.insert(make_pair(name, newStage));
	newStage->init();
}
void stageManager::eraseStage(string name)
{
	_mStage.erase(name);
}
void stageManager::changeStage(string name)
{
	if (_currentStage)
	{
		_currentStage->exit();
		_currentStage = NULL;
	}

	if (auto nextStage = _mStage.at(name))
	{
		_currentStage = nextStage;
		nextStage->enter();
	}
}
