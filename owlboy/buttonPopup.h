#pragma once
#include "gameObject.h"


class buttonPopup : public gameObject
{
private:
	gameObject *_target;
	PTINT _maxFrame;
	float _renderTimeSave;
	bool _bSignal;

public:
	virtual HRESULT init(PTFLOAT pos = PTFLOAT(0, 0));
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	//오버라이드
	virtual void changeImage(string imageKey);

	buttonPopup() {}
	virtual ~buttonPopup() {}
};
