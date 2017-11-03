#include "stdafx.h"
#include "owlboyScene.h"
#include "otus.h"
#include "cloud.h"
#include "terrain.h"
#include "backGround.h"


HRESULT owlboyScene::init()
{
	{
		auto temp = new otus;
		temp->init(PTFLOAT(150, 150));
		WORLD->addObject(temp);

		CAMERA->setTarget(temp);
	}
	{
		auto temp = new backGround;
		temp->init(PTFLOAT(0, 400));
		temp->changeImage("cloudBack");
		WORLD->addObject(temp);
	}
	{
		auto temp = new terrain;
		temp->init(PTFLOAT(500, 500));
		temp->changeImage("bomboShop");
		WORLD->addObject(temp);
	}
	{
		auto temp = new terrain;
		temp->init(PTFLOAT(1000, 500));
		temp->changeImage("saunaFront");
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
	WORLD->render();
}
