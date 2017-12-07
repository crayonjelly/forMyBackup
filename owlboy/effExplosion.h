#pragma once
#include "gameObject.h"


class effExplosion : public gameObject
{
private:
	float _time1;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	effExplosion() {}
	effExplosion(PTFLOAT pos);
	virtual ~effExplosion() {}
};
