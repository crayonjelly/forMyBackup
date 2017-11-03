#pragma once
#include "gameObject.h"


class otus : public gameObject
{
public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	void move();

	otus() {}
	virtual ~otus() {}
};
