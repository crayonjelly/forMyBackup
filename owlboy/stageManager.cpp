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
	string pastStage = "";

	if (_currentStage)
	{
		pastStage = _currentStage->_stageName;
		_currentStage->exit();
		_currentStage = NULL;
	}

	if (auto nextStage = _mStage[name])
	{
		_currentStage = nextStage;
		nextStage->enter(pastStage);
	}
}
