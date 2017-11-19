#pragma once
#include "gameObject.h"


class terrain : public gameObject
{
private:
	PTINT _maxFrame;
	float _renderTimeSave;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	//오버라이드
	virtual void changeImage(string imageKey);

	//겟셋
	auto getMaxFrame() { return _maxFrame; }

	void setMaxFrame(PTINT max) { _maxFrame = max; }

	terrain() {}
	virtual ~terrain() {}
};
