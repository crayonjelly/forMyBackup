#pragma once
#include "singletonBase.h"
#include "stages.h"


class stageManager : public singletonBase<stageManager>
{
private:
	map<string, stage*> _mStage;
	stage *_currentStage;

public:
	HRESULT init(void);
	void release(void);

	void insertStage(string name, stage* newStage);
	void eraseStage(string name);
	void changeStage(string name);

	//°Ù¼Â
	inline auto getCurrentStage() { return _currentStage; }

	stageManager() {}
	~stageManager() {}
};
