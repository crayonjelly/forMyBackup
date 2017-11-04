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
		temp->init(PTFLOAT(800, 600));
		WORLD->addObject(temp);

		CAMERA->setTarget(temp);
	}
	{
		auto temp = new backGround;
		temp->init(PTFLOAT(0, 0));
		temp->changeImage("cloudBack");
		temp->setPos(PTFLOAT(0, WINSIZEY - temp->getImage()->getHeight()));
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
	for (int i = 0; i < 40; ++i)
	{
		auto temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(0, 4000), RND->getFromIntTo(0, 4000)));
		temp->changeImage("cloud01");
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
		temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(0, 4000), RND->getFromIntTo(0, 4000)));
		temp->changeImage("cloud02");
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
		temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(0, 4000), RND->getFromIntTo(0, 4000)));
		temp->changeImage("cloud03");
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
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
