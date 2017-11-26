#include "stdafx.h"
#include "owlboyScene.h"
#include "otus.h"
#include "cloud.h"
#include "terrain.h"
#include "backGround.h"
#include "gawk.h"


HRESULT owlboyScene::init()
{
	//�ʹ���, �ȼ����� ���忡 �߰�
	terrainInit();

	//������ �߰�
	{
		auto temp = new otus;
		temp->init(PTFLOAT(5000, 3000));
		WORLD->addObject(temp);
		WORLD->setOtus(temp);

		CAMERA->setTarget(temp);
	}

	//----------- �������� �غ��� ------------
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
