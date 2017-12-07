#include "stdafx.h"
#include "playGround.h"
#include "owlboyScene.h"


HRESULT playGround::init(void)
{
	gameNode::init(true);

	char str[64] = "Now Loading . . .";
	TextOut(getHDC(), WINSIZEX / 2 - 100, WINSIZEY / 2 - 10, str, strlen(str));

	WORLD->setPG(this);

	IMAGEMANAGER->addImage("cloudBack", "resource/(x2)cloudBack(1180,378).bmp", 1180, 378, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloudMiddle", "resource/(x2)cloudMiddle(1180,344).bmp", 1180, 344, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloudTop", "resource/(x2)cloudTop(1180,206).bmp", 1180, 206, true, RGB(255, 0, 255));
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
	IMAGEMANAGER->addImage("bomboHouse", "resource/(x2)bomboHouse(424,238).bmp", 424, 238, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mandolynHouse", "resource/(x2)mandolynHouse(327,311).bmp", 327, 311, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("otusHouse", "resource/(x2)island01(540,692).bmp", 540, 692, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("otusHouse_pixel", "resource/(x2)island01(540,692)_pixel.bmp", 540, 692, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backWallBig", "resource/(x2)backWallBig(324,638).bmp", 324, 638, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("caveEntry", "resource/(x2)caveEntry(376,230).bmp", 376, 230, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("caveSegment1", "resource/(x2)caveSegment1(278,364).bmp", 278, 364, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("caveSegment3", "resource/(x2)caveSegment3(478,408).bmp", 478, 408, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("caveCombined", "resource/(x2)caveCombined(602,422).bmp", 602, 422, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("fontBig", "resource/(x2)fontBig(572,28,26,1).bmp", 572, 28, 26, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("hero", "resource/(x2)hero(6272,2688,28,14).bmp", 6272, 2688, 28, 14, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("hero2", "resource/(x2)hero2(4480,2688,20,14).bmp", 4480, 2688, 20, 14, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("roll", "resource/(x2)roll(2016,384,9,2).bmp", 2016, 384, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("rollGround", "resource/(x2)rollGround(1344,384,6,2).bmp", 1344, 384, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("gawkSheet", "resource/(x2)gawkSheet(3564,700,22,5).bmp", 3564, 700, 22, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("grassBrownEdge1", "resource/(x2)grassBrown_edge1(744,86,6,1).bmp", 744, 86, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("grassBrownEdge2", "resource/(x2)grassBrown_edge2(576,72,6,1).bmp", 576, 72, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("grassBrownPlatform1", "resource/(x2)grassBrown_platform1(1908,104,6,1).bmp", 1908, 104, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("grassBrownPlatform2", "resource/(x2)grassBrown_platform2(2508,114,6,1).bmp", 2508, 114, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("grassBrownEdge1_pixel", "resource/(x2)grassBrown_edge1_pixel(124,86).bmp", 124, 86, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("grassBrownEdge2_pixel", "resource/(x2)grassBrown_edge2_pixel(96,72).bmp", 96, 72, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("grassBrownPlatform1_pixel", "resource/(x2)grassBrown_platform1_pixel(318,104).bmp", 318, 104, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("grassBrownPlatform2_pixel", "resource/(x2)grassBrown_platform2_pixel(418,114).bmp", 418, 114, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("otusHousePart1", "resource/(x2)otusHousePart1(2352,528,4,1).bmp", 2352, 528, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("otusHousePart2", "resource/(x2)otusHousePart1(2352,528,4,1).bmp", 2352, 528, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("otusHousePart1_pixel", "resource/(x2)otusHousePart1_pixel(588,528).bmp", 588, 528, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("btnClicks", "resource/(x2)btnClicks(72,84,2,2).bmp", 72, 84, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("btnMouseRGrab", "resource/(x2)btnMouseRGrab(92,60,2,1).bmp", 92, 60, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tileCeiling", "resource/(x2)tileCeiling(392,92).bmp", 392, 92, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tileCeiling_pixel", "resource/(x2)tileCeiling_pixel(392,92).bmp", 392, 92, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tileFloor", "resource/(x2)tileFloor(390,96).bmp", 390, 96, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tileFloor_pixel", "resource/(x2)tileFloor_pixel(390,96).bmp", 390, 96, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tileFloorRock", "resource/(x2)tileFloorRock(412,96).bmp", 412, 96, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tileFloorRock_pixel", "resource/(x2)tileFloorRock_pixel(412,96).bmp", 412, 96, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tileWall", "resource/(x2)tileWall(188,214,2,1).bmp", 188, 214, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tileWall_pixel", "resource/(x2)tileWall_pixel(188,214,2,1).bmp", 188, 214, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("explosion", "resource/(x2)explosion(3230,170,19,1).bmp", 3230, 170, 19, 1, true, RGB(255, 0, 255));

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

	//F9 누르면 디버그모드 온/오프
	if (KEYMANAGER->isOnceKeyDown(VK_F9))
	{
		_mainDebugMode = !_mainDebugMode;
	}

	//once 제대로 안먹혀서 조치
	KEYMANAGER->isStayKeyDown(VK_RBUTTON);

	SCENEMANAGER->update();

	//업데이트 다 돌리고 카메라 포커스 맞춰준다
	CAMERA->putCameraCenterToTarget();
}

void playGround::render(void)
{
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//팻블릿 대신 하늘색으로 밀자
	HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), CreateSolidBrush(RGB(121, 185, 255)));
	RectangleMake(getMemDC(), -10, -10, WINSIZEX + 10, WINSIZEY + 10);
	DeleteObject(SelectObject(getMemDC(), oldBrush));


	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());

	//카메라 좌표 표시
	char str[64];
	sprintf_s(str, "(%d, %d)", CAMX, CAMY);
	TextOut(getMemDC(), 2, 60, str, strlen(str));

	//=================== 손 대 지 마 ===================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
