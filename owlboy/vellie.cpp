#include "stdafx.h"
#include "stages.h"
#include "terrain.h"
#include "backGround.h"
#include "cloud.h"
#include "gawk.h"
#include "door.h"
#include "backRock.h"


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

	WORLD->getOtus()->setPos(PTFLOAT(5000, 3000));
	WORLD->getOtus()->putRectUponPos();
	if (pastStage == "otusHouse")
	{
		WORLD->getOtus()->setPos(PTFLOAT(5212, 4374));
		WORLD->getOtus()->putRectUponPos();
	}

	CAMERA->setTarget(WORLD->getOtus());
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

	//던전
	makePos = PTINT(3850, 4300);
	IMAGEMANAGER->findImage("caveCombined")->render(_mapDC,
		makePos.x, makePos.y);

	makeTerrain = new terrain;
	makeTerrain->init(makePos + PTINT(50, 0));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN2);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(_pixelDC,
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	makeTerrain = new terrain;
	makeTerrain->init(makePos + PTINT(300, 0));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN2);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(_pixelDC,
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	makeTerrain = new terrain;
	makeTerrain->init(makePos + PTINT(170, 344));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN2);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(_pixelDC,
		makeTerrain->getPos().x, makeTerrain->getPos().y);
	{
		auto temp = new door;
		PTINT newPos = makePos + PTINT(210, 210);
		temp->init(newPos);
		temp->setRect(RectMake(newPos.x, newPos.y, 94, 150));
		temp->setMessage(tagMessage("door", 0, 0.0f, "dungeon"));
		WORLD->addObject(temp);
	}
}
void vellie::createObjects()
{
	//뒷배경
	{
		auto temp = new backGround;
		temp->init(PTFLOAT());
		temp->changeImage("cloudBack");
		temp->setPos(PTFLOAT(0, WINSIZEY - temp->getImage()->getHeight()));
		temp->rcResetByImage();
		WORLD->addObject(temp);

		temp = new backGround;
		temp->init(PTFLOAT());
		temp->changeImage("cloudBack");
		temp->setPos(PTFLOAT(temp->getImage()->getWidth(), WINSIZEY - temp->getImage()->getHeight()));
		temp->rcResetByImage();
		WORLD->addObject(temp);

		temp = new backGround;
		temp->init(PTFLOAT());
		temp->changeImage("cloudMiddle");
		temp->setPos(PTFLOAT(0, WINSIZEY - temp->getImage()->getHeight()));
		temp->rcResetByImage();
		WORLD->addObject(temp);

		temp = new backGround;
		temp->init(PTFLOAT());
		temp->changeImage("cloudMiddle");
		temp->setPos(PTFLOAT(temp->getImage()->getWidth(), WINSIZEY - temp->getImage()->getHeight()));
		temp->rcResetByImage();
		WORLD->addObject(temp);

		temp = new backGround;
		temp->init(PTFLOAT());
		temp->changeImage("cloudTop");
		temp->setPos(PTFLOAT(0, WINSIZEY - temp->getImage()->getHeight()));
		temp->rcResetByImage();
		WORLD->addObject(temp);

		temp = new backGround;
		temp->init(PTFLOAT());
		temp->changeImage("cloudTop");
		temp->setPos(PTFLOAT(temp->getImage()->getWidth(), WINSIZEY - temp->getImage()->getHeight()));
		temp->rcResetByImage();
		WORLD->addObject(temp);
	}

	//구름
	for (int i = 0; i < 30; ++i)
	{
		auto temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(1000, 9000), RND->getFromIntTo(0, 8000)));
		temp->changeImage("cloud01");
		temp->rcResetByImage();
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
		temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(1000, 9000), RND->getFromIntTo(0, 8000)));
		temp->changeImage("cloud02");
		temp->rcResetByImage();
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
		temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(1000, 9000), RND->getFromIntTo(0, 8000)));
		temp->changeImage("cloud03");
		temp->rcResetByImage();
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
	}

	//돌
	for (int i = 0; i < 8; ++i)
	{
		auto temp = new backRock;
		temp->init(PTFLOAT(RND->getFromIntTo(2000, 8000), RND->getFromIntTo(1000, 6000)));
		temp->changeImage("backRockFar1");
		temp->rcResetByImage();
		temp->setLayer(LAYER::BACK3);
		WORLD->addObject(temp);

		temp = new backRock;
		temp->init(PTFLOAT(RND->getFromIntTo(2000, 8000), RND->getFromIntTo(1000, 6000)));
		temp->changeImage("backRockFar2");
		temp->rcResetByImage();
		temp->setLayer(LAYER::BACK3);
		WORLD->addObject(temp);

		temp = new backRock;
		temp->init(PTFLOAT(RND->getFromIntTo(2000, 8000), RND->getFromIntTo(1000, 6000)));
		temp->changeImage("backRockFar3");
		temp->rcResetByImage();
		temp->setLayer(LAYER::BACK3);
		WORLD->addObject(temp);

		temp = new backRock;
		temp->init(PTFLOAT(RND->getFromIntTo(2500, 7500), RND->getFromIntTo(1500, 5500)));
		temp->changeImage("backRock1");
		temp->rcResetByImage();
		temp->setLayer(LAYER::BACK2);
		WORLD->addObject(temp);

		temp = new backRock;
		temp->init(PTFLOAT(RND->getFromIntTo(2500, 7500), RND->getFromIntTo(1500, 5500)));
		temp->changeImage("backRock2");
		temp->rcResetByImage();
		temp->setLayer(LAYER::BACK2);
		WORLD->addObject(temp);

		temp = new backRock;
		temp->init(PTFLOAT(RND->getFromIntTo(2500, 7500), RND->getFromIntTo(1500, 5500)));
		temp->changeImage("backRock3");
		temp->rcResetByImage();
		temp->setLayer(LAYER::BACK2);
		WORLD->addObject(temp);
	}

	//{
	//	//for (int i = 0; i < 5; ++i)
	//	//{
	//		auto temp = new cloud;
	//		temp->init(PTFLOAT(5000, 2700));
	//		temp->changeImage("cloud01");
	//		temp->rcResetByImage();
	//		temp->setLayer((LAYER::Enum)3);
	//		WORLD->addObject(temp);
	//	//}
	//		temp = new cloud;
	//		temp->init(PTFLOAT(5000, 2700));
	//		temp->changeImage("cloud01");
	//		temp->rcResetByImage();
	//		temp->setLayer((LAYER::Enum)4);
	//		WORLD->addObject(temp);
	//		temp = new cloud;
	//		temp->init(PTFLOAT(5000, 2700));
	//		temp->changeImage("cloud01");
	//		temp->rcResetByImage();
	//		temp->setLayer((LAYER::Enum)5);
	//		WORLD->addObject(temp);
	//}

	//고크
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
