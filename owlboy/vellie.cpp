#include "stdafx.h"
#include "stages.h"
#include "terrain.h"
#include "backGround.h"
#include "cloud.h"
#include "gawk.h"
#include "door.h"


void vellie::init()
{
	setDCs();

	_stageName = "vellie";
}
void vellie::enter(string pastStage)
{
	WORLD->allDieExceptBase();
	mapPixelClear();
	drawMap();
	createObjects();

	if (pastStage == "otusHouse")
	{
		WORLD->getOtus()->setPos(PTFLOAT(5212, 4374));
		WORLD->getOtus()->putRectUponPos();
	}
}

void vellie::drawMap()
{
	//봄보샵
	PTINT makePos(4000, 3200);

	auto makeTerrain = new terrain;
	makeTerrain->init(makePos);
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(_pixelDC,
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	makeTerrain = new terrain;
	makeTerrain->init(makePos + PTINT(360, 0));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(_pixelDC,
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	IMAGEMANAGER->findImage("bomboShop")->render(_mapDC,
		makePos.x + 40, makePos.y + 30);
	IMAGEMANAGER->findImage("bomboShop_pixel")->render(_pixelDC,
		makePos.x + 40, makePos.y + 30);
	IMAGEMANAGER->findImage("bomboHouse")->render(_mapDC,
		makePos.x + 200, makePos.y - 220);

	//만돌린 집
	makePos = PTINT(5100, 2700);

	makeTerrain = new terrain;
	makeTerrain->init(makePos);
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(_pixelDC,
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	makeTerrain = new terrain;
	makeTerrain->init(makePos + PTINT(200, 0));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(_pixelDC,
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	makeTerrain = new terrain;
	makeTerrain->init(makePos + PTINT(400, 0));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(_pixelDC,
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	IMAGEMANAGER->findImage("mandolynHouse")->render(_mapDC,
		makePos.x + 300, makePos.y - 300);

	//사우나
	makePos = PTINT(5800, 3100);
	IMAGEMANAGER->findImage("saunaFront")->render(_mapDC, makePos.x, makePos.y);
	IMAGEMANAGER->findImage("saunaFront_pixel")->render(_pixelDC, makePos.x, makePos.y);

	//그냥 땅 하나
	makeTerrain = new terrain;
	makeTerrain->init(PTFLOAT(4800, 3000));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(_pixelDC,
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	//오투스 집
	makePos = PTINT(4900, 4000);
	IMAGEMANAGER->findImage("otusHouse")->render(_mapDC,
		makePos.x, makePos.y);
	IMAGEMANAGER->findImage("otusHouse_pixel")->render(_pixelDC,
		makePos.x, makePos.y);
	{
		auto temp = new door;
		PTINT newPos = makePos + PTINT(280, 300);
		temp->init(newPos);
		temp->setRect(RectMake(newPos.x, newPos.y, 60, 80));
		temp->setMessage(tagMessage("door", 0, 0.0f, "otusHouse"));
		WORLD->addObject(temp);
	}
}
void vellie::createObjects()
{
	{
		auto temp = new backGround;
		temp->init(PTFLOAT(0, 0));
		temp->changeImage("cloudBack");
		temp->setPos(PTFLOAT(0, WINSIZEY - temp->getImage()->getHeight()));
		temp->rcResetByImage();
		WORLD->addObject(temp);
	}
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
}
