#include "stdafx.h"
#include "stages.h"
#include "terrain.h"
#include "door.h"
#include "layerObject.h"


void dungeon::init()
{
	setDCs();

	_stageName = "dungeon";
}
void dungeon::enter(string pastStage)
{
	WORLD->allDieExceptBase();
	mapPixelClear();
	drawMap();
	createObjects();
	WORLD->getOtus()->setPos(PTFLOAT(7000, 7000));
	WORLD->getOtus()->putRectUponPos();
}

void dungeon::drawMap()
{
	{
		auto temp = new door;
		PTINT newPos(6900, 6900);
		temp->init(newPos);
		temp->setRect(RectMake(newPos.x, newPos.y, 94, 150));
		temp->setMessage(tagMessage("door", 0, 0.0f, "vellie"));
		WORLD->addObject(temp);
	}
	{
		//뒷배경용 레이어
		auto makeLayer = new layerObject;
		makeLayer->init(PTFLOAT(0, 0));
		makeLayer->setLayer(LAYER::TERRAIN3);

		image* layerImage = new image;
		layerImage->init(10000, 10000, RGB(255, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(layerImage->getMemDC(), CreateSolidBrush(RGB(255, 0, 255)));
		RectangleMake(layerImage->getMemDC(), -10, -10, layerImage->getWidth() + 10, layerImage->getHeight() + 10);
		DeleteObject(SelectObject(layerImage->getMemDC(), oldBrush));

		makeLayer->setLayerImage(layerImage);

		auto backWallBig = IMAGEMANAGER->findImage("backWallBig");
		for (int j = 0; j < 12; ++j)
		{
			for (int i = 0; i < 30; ++i)
			{
				backWallBig->render(makeLayer->getLayerDC(),
					3000 + (i * 268),
					3000 + (j * 588));
			}
		}

		WORLD->addObject(makeLayer);
	}
	{
		//맵 그리기
		auto tileFloor = IMAGEMANAGER->findImage("tileFloor");
		auto tileFloorPixel = IMAGEMANAGER->findImage("tileFloor_pixel");
		auto tileWall = IMAGEMANAGER->findImage("tileWall");
		auto tileWallPixel = IMAGEMANAGER->findImage("tileWall_pixel");
		auto tileCeiling = IMAGEMANAGER->findImage("tileCeiling");
		auto tileCeilingPixel = IMAGEMANAGER->findImage("tileCeiling_pixel");

		for (int i = 0; i < 3; ++i)
		{
			tileFloor->render(_mapDC,
				6400 + (i * 382),
				7100);
			tileFloorPixel->render(_pixelDC,
				6400 + (i * 382),
				7100);
		}

		for (int j = 0; j < 3; ++j)
		{
			tileWall->frameRender(_mapDC,
				7200,
				6500 + (j * 212),
				1, 0);
			tileWallPixel->frameRender(_pixelDC,
				7200,
				6500 + (j * 212),
				1, 0);
		}

		for (int i = 0; i < 3; ++i)
		{
			tileCeiling->render(_mapDC,
				6400 + (i * 386),
				6400);
			tileCeilingPixel->render(_pixelDC,
				6400 + (i * 386),
				6400);
		}
	}
}
void dungeon::createObjects()
{

}
