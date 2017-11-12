#include "stdafx.h"
#include "playGround.h"
#include "owlboyScene.h"


HRESULT playGround::init(void)
{
	gameNode::init(true);

	char *str = "Now Loading . . .";
	TextOut(getHDC(), WINSIZEX / 2 - 100, WINSIZEY / 2 - 10, str, strlen(str));

	IMAGEMANAGER->addImage("cloudBack", "resource/(x2)cloudBack(1180,378).bmp", 1180, 378, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bomboShop", "resource/(x2)bomboShop(674,402).bmp", 674, 402, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bomboShop_pixel", "resource/(x2)bomboShop(674,402)_pixel.bmp", 674, 402, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("saunaFront", "resource/(x2)saunaFront(896,724).bmp", 896, 724, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("saunaFront_pixel", "resource/(x2)saunaFront(896,724)_pixel.bmp", 896, 724, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backRockFar1", "resource/(x2)back_rock_far1(82,92).bmp", 82, 92, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backRockFar2", "resource/(x2)back_rock_far2(96,120).bmp", 96, 120, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backRockFar3", "resource/(x2)back_rock_far3(90,82).bmp", 90, 82, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backRock1", "resource/(x2)back_rock1(194,172).bmp", 194, 172, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backRock2", "resource/(x2)back_rock2(220,244).bmp", 220, 244, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backRock3", "resource/(x2)back_rock3(170,192).bmp", 170, 192, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloud01", "resource/(x2)cloud01(690,602).bmp", 690, 602, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloud02", "resource/(x2)cloud02(848,266).bmp", 848, 266, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloud03", "resource/(x2)cloud03(380,212).bmp", 380, 212, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blueTest", "resource/파랑픽셀 테스트(674,402).bmp", 674, 402, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("hero", "resource/(x2)hero(6272,2688,28,14).bmp", 6272, 2688, 28, 14, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("아울보이씬", new owlboyScene);

	SCENEMANAGER->changeScene("아울보이씬");

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

	//업데이트 다 돌리고 카메라 포커스 맞춰준다
	CAMERA->putCameraCenterToTarget();
}

void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());

	//카메라 좌표 표시
	char str[64];
	sprintf_s(str, "(%d, %d)", CAMX, CAMY);
	TextOut(getMemDC(), 2, 60, str, strlen(str));

	//=================== 손 대 지 마 ===================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
