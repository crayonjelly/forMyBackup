#pragma once
#include "gameObject.h"


class maskObject : public gameObject
{
private:
	COLORREF _color;
	int _alpha;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	maskObject() {}
	virtual ~maskObject() {}
};
