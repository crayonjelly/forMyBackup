#include "stdafx.h"
#include "owlboyScene.h"
#include "otus.h"
#include "cloud.h"
#include "terrain.h"
#include "backGround.h"


HRESULT owlboyScene::init()
{
	{
		auto temp = new otus;
		temp->init(PTFLOAT(800, 600));
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
	{
		//맵버퍼, 픽셀버퍼 마젠타로 싹 밀기
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMapDC(), CreateSolidBrush(RGB(255, 0, 255)));
		RectangleMake(getMapDC(), -10, -10, getMapBuffer()->getWidth() + 10, getMapBuffer()->getHeight() + 10);
		DeleteObject(SelectObject(getMapDC(), oldBrush));

		//픽셀버퍼는 테두리 빨갛게 해서 막자
		oldBrush = (HBRUSH)SelectObject(getPixelDC(), CreateSolidBrush(RGB(255, 0, 255)));
		HPEN oldPen = (HPEN)SelectObject(getPixelDC(), CreatePen(PS_SOLID, 32, RGB(255, 0, 0)));
		RectangleMake(getPixelDC(), 0, 0, getPixelBuffer()->getWidth(), getPixelBuffer()->getHeight());
		DeleteObject(SelectObject(getPixelDC(), oldPen));
		DeleteObject(SelectObject(getPixelDC(), oldBrush));

		//맵버퍼에 지형 그리기
		IMAGEMANAGER->findImage("bomboShop")->render(getMapDC(), 500, 500);
		IMAGEMANAGER->findImage("saunaFront")->render(getMapDC(), 1000, 500);

		//픽셀버퍼에 픽셀 그리기
		IMAGEMANAGER->findImage("bomboShop_pixel")->render(getPixelDC(), 500, 500);
		IMAGEMANAGER->findImage("saunaFront_pixel")->render(getPixelDC(), 1000, 500);

		//맵버퍼 오브젝트로 만들어서 월드에 추가하기
		auto temp = new gameObject;
		temp->init(PTFLOAT(0, 0));
		temp->changeImage("mapBuffer");
		temp->setLayer(LAYER::TERRAIN);
		WORLD->addObject(temp);

		//픽셀버퍼 월드에 추가해본다
		temp = new gameObject;
		temp->init(PTFLOAT(0, 0));
		temp->changeImage("pixelBuffer");
		temp->setLayer((LAYER::Enum)(LAYER::TERRAIN + 1));
		WORLD->addObject(temp);
	}
	for (int i = 0; i < 40; ++i)
	{
		auto temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(0, 4000), RND->getFromIntTo(0, 4000)));
		temp->changeImage("cloud01");
		temp->rcResetByImage();
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
		temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(0, 4000), RND->getFromIntTo(0, 4000)));
		temp->changeImage("cloud02");
		temp->rcResetByImage();
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
		temp = new cloud;
		temp->init(PTFLOAT(RND->getFromIntTo(0, 4000), RND->getFromIntTo(0, 4000)));
		temp->changeImage("cloud03");
		temp->rcResetByImage();
		temp->setLayer((LAYER::Enum)RND->getFromIntTo(3, 5));
		WORLD->addObject(temp);
	}

	return S_OK;
}
void owlboyScene::release()
{

}
void owlboyScene::update()
{
	WORLD->update();

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		CAMERA->moveCamera(-10, 0);
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		CAMERA->moveCamera(10, 0);
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		CAMERA->moveCamera(0, -10);
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		CAMERA->moveCamera(0, 10);
	}
}
void owlboyScene::render()
{
	WORLD->render();
}
