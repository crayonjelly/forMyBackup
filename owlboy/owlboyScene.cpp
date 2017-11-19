#include "stdafx.h"
#include "owlboyScene.h"
#include "otus.h"
#include "cloud.h"
#include "terrain.h"
#include "backGround.h"
#include "gawk.h"


HRESULT owlboyScene::init()
{
	{
		auto temp = new otus;
		temp->init(PTFLOAT(5000, 3000));
		WORLD->addObject(temp);

		CAMERA->setTarget(temp);
	}
	{
		auto temp = new backGround;
		temp->init(PTFLOAT(0, 0));
		temp->changeImage("cloudBack");
		temp->setPos(PTFLOAT(0, WINSIZEY - temp->getImage()->getHeight()));
		temp->rcResetByImage();
		WORLD->addObject(temp);
	}
	terrainInit();
	for (int i = 0; i < 40; ++i)
	{
		auto temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(2000, 8000), RND->getFromIntTo(1000, 7000)));
		temp->changeImage("cloud01");
		temp->rcResetByImage();
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
		temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(2000, 8000), RND->getFromIntTo(1000, 7000)));
		temp->changeImage("cloud02");
		temp->rcResetByImage();
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
		temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(2000, 8000), RND->getFromIntTo(1000, 7000)));
		temp->changeImage("cloud03");
		temp->rcResetByImage();
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
	}
	{
		for (int i = 0; i < 10; ++i)
		{
			auto temp = new gawk;
			temp->init(PTFLOAT(RND->getFromIntTo(4000, 6000),
				RND->getFromIntTo(2000, 4000)));
			WORLD->addObject(temp);
		}
	}

	return S_OK;
}
void owlboyScene::release()
{

}
void owlboyScene::update()
{
	WORLD->update();
}
void owlboyScene::render()
{
	WORLD->render();
}
