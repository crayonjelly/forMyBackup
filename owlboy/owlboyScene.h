#pragma once
#include "gameNode.h"


class owlboyScene : public gameNode
{
private:


public:
	HRESULT init();
	void release();
	void update();
	void render();

	void terrainInit();

	owlboyScene() {}
	~owlboyScene() {}
};
