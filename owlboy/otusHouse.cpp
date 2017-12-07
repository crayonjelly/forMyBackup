#include "stdafx.h"
#include "stages.h"
#include "terrain.h"
#include "door.h"
#include "layerObject.h"


void otusHouse::init()
{
	setDCs();

	_stageName = "otusHouse";
}
void otusHouse::enter(string pastStage)
{
	WORLD->allDieExceptBase();
	mapPixelClear();
	drawMap();
	createObjects();
	WORLD->getOtus()->setPos(PTFLOAT(1140, 1461));
	WORLD->getOtus()->putRectUponPos();

	CAMERA->setTarget(NULL);
	CAMERA->setPos(PTINT(700, 880));
}

void otusHouse::drawMap()
{
	PTINT makePos(1000, 1000);
	{
		//뒷배경용 레이어
		auto makeLayer = new layerObject;
		makeLayer->init(PTFLOAT(0, 0));
		makeLayer->setLayer(LAYER::SKY3);

		image* layerImage = new image;
		layerImage->init(10000, 10000, RGB(255, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(layerImage->getMemDC(), CreateSolidBrush(RGB(0, 0, 0)));
		RectangleMake(layerImage->getMemDC(), -10, -10, layerImage->getWidth() + 10, layerImage->getHeight() + 10);
		DeleteObject(SelectObject(layerImage->getMemDC(), oldBrush));

		makeLayer->setLayerImage(layerImage);

		WORLD->addObject(makeLayer);
	}
	{
		auto makeHouse = new terrain;
		makeHouse->init(makePos);
		makeHouse->changeImage("otusHousePart1");
		makeHouse->setKind(OBJKIND::TERRAIN);
		makeHouse->setLayer(LAYER::TERRAIN3);
		WORLD->addObject(makeHouse);
		IMAGEMANAGER->findImage("otusHousePart1_pixel")->render(_pixelDC,
			makeHouse->getPos().x, makeHouse->getPos().y);
	}
	{
		auto makeDoor = new door;
		PTINT newPos = makePos + PTINT(110, 380);
		makeDoor->init(newPos);
		makeDoor->setRect(RectMake(newPos.x, newPos.y, 50, 86));
		makeDoor->setMessage(tagMessage("door", 0, 0.0f, "vellie"));
		WORLD->addObject(makeDoor);
	}
}
void otusHouse::createObjects()
{

}
