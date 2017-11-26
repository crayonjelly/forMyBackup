#include "stdafx.h"
#include "owlboyScene.h"


void owlboyScene::terrainInit()
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

	//맵버퍼 오브젝트로 만들어서 월드에 추가하기
	auto temp = new gameObject;
	temp->init(PTFLOAT(0, 0));
	temp->setKind(OBJKIND::MAPBUFFER);
	temp->changeImage("mapBuffer");
	temp->setLayer(LAYER::TERRAIN2);
	WORLD->addObject(temp);

	//픽셀버퍼 디버그용으로 월드에 추가
	temp = new gameObject;
	temp->init(PTFLOAT(0, 0));
	temp->setKind(OBJKIND::PIXELBUFFER);
	temp->changeImage("pixelBuffer");
	temp->setLayer((LAYER::Enum)(LAYER::PIXELDC));
	WORLD->addObject(temp);
}
