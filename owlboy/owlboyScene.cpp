#include "stdafx.h"
#include "owlboyScene.h"
#include "otus.h"
#include "cloud.h"


HRESULT owlboyScene::init()
{
	{
		auto temp = new otus;
		temp->init(PTFLOAT(150, 150));
		WORLD->addObject(temp);
	}
	{
		auto temp = new cloud;
		temp->init(PTFLOAT(0, 400));
		temp->changeImage("cloudBack");
		WORLD->addObject(temp);
	}

	return S_OK;
}
void owlboyScene::release()
{

}
void owlboyScene::update()
{
	WORLD->update();

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		CAMERA->moveCamera(-10, 0);
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		CAMERA->moveCamera(10, 0);
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		CAMERA->moveCamera(0, -10);
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		CAMERA->moveCamera(0, 10);
	}
}
void owlboyScene::render()
{
	IMAGEMANAGER->findImage("bomboShop")->render(getMemDC(), -CAMX + 500, -CAMY + 500);
	IMAGEMANAGER->findImage("saunaFront")->render(getMemDC(), -CAMX + 1000, -CAMY + 500);
	
	WORLD->render();

	static int frame = 0;
	++frame;
	static int saveFrame = 0;
	static int frameX = 0;
	if (frame - saveFrame >= 5)
	{
		saveFrame = frame;
		if (frameX < 10) ++frameX;
		else frameX = 0;
	}
	IMAGEMANAGER->findImage("hero")->frameRender(getMemDC(), 500, 300, frameX, 2);
}
