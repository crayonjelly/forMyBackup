#pragma once
#include "gameObject.h"


class otus : public gameObject
{
private:
	PTINT _imageSize;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();

	otus() {}
	virtual ~otus() {}
};
