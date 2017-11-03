#include "stdafx.h"
#include "playGround.h"
#include "owlboyScene.h"


HRESULT playGround::init(void)
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("cloudBack", "resource/(x2)cloudBack(1180,378).bmp", 1180, 378, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bomboShop", "resource/(x2)bomboShop(674,402).bmp", 674, 402, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("saunaFront", "resource/(x2)saunaFront(896,724).bmp", 896, 724, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("hero", "resource/(x2)hero(3136,2688,14,14).bmp", 3136, 2688, 14, 14, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("�ƿﺸ�̾�", new owlboyScene);

	SCENEMANAGER->changeScene("�ƿﺸ�̾�");

	return S_OK;
}

void playGround::release(void)
{
	gameNode::release();
}

void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

	//������Ʈ �� ������ ī�޶� ��Ŀ�� �����ش�
	CAMERA->putCameraCenterToTarget();
}

void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());

	//ī�޶� ��ǥ ǥ��
	char str[64];
	sprintf_s(str, "(%d, %d)", CAMX, CAMY);
	TextOut(getMemDC(), 2, 60, str, strlen(str));

	//=================== �� �� �� �� ===================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
