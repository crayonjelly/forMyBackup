#pragma once
#include "gameObject.h"


class backRock : public gameObject
{
private:
	PTFLOAT _initPos;
	float _angle;

public:
	virtual HRESULT init(PTFLOAT pos);
	//virtual void release();
	virtual void update();
	//virtual void render(float depthScale = 1.0f);


	backRock() {}
	virtual ~backRock() {}
};
