#include "stdafx.h"
#include "loadingScene.h"


loadingScene::loadingScene()
{
}


loadingScene::~loadingScene()
{

}

HRESULT loadingScene::init()
{
	_loading = new loading;
	_loading->init();

	this->loadingImage();

	
	return S_OK;
}

void loadingScene::release()
{
	SAFE_DELETE(_loading);
}

void loadingScene::update()	
{
	_loading->update();

	if (_loading->loadingDone())
	{
		SCENEMANAGER->changeScene("¼¿·º¾À");
	}

}

void loadingScene::render()	
{
	_loading->render();
}


void loadingScene::loadingImage()
{
	for (int i = 0; i < 30; i++)
	{
		_loading->loadImage("¼¿·ºÆ®¾À", WINSIZEX, WINSIZEY);
	}
}

void loadingScene::loadingSound()
{

}