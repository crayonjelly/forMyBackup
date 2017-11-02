#pragma once
#include "gameObject.h"


class cloud : public gameObject
{
public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render();

	cloud() {}
	~cloud() {}
};
