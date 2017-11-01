#pragma once
#include "singletonBase.h"


class world : public singletonBase<world>
{
private:
	vector<gameObject*> _vObject;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void addObject(gameObject* obj);

	world() {}
	~world() {}
};
