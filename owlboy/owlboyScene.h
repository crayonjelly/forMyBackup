#pragma once
#include "gameNode.h"


class owlboyScene : public gameNode
{
public:
	HRESULT init();
	void release();
	void update();
	void render();

	owlboyScene() {}
	~owlboyScene() {}
};
