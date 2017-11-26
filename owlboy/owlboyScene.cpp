#include "stdafx.h"
#include "owlboyScene.h"
#include "otus.h"
#include "cloud.h"
#include "terrain.h"
#include "backGround.h"
#include "gawk.h"


HRESULT owlboyScene::init()
{
	//맵버퍼, 픽셀버퍼 월드에 추가
	terrainInit();

	//오투스 추가
	{
		auto temp = new otus;
		temp->init(PTFLOAT(5000, 3000));
		WORLD->addObject(temp);
		WORLD->setOtus(temp);

		CAMERA->setTarget(temp);
	}

	//----------- 스테이지 해보자 ------------
	STAGEMANAGER->insertStage("vellie", new vellie);
	STAGEMANAGER->insertStage("otusHouse", new otusHouse);

	STAGEMANAGER->changeStage("vellie");
	//---------------------------------------

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
