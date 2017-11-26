#include "stdafx.h"
#include "owlboyScene.h"


void owlboyScene::terrainInit()
{
	//�ʹ���, �ȼ����� ����Ÿ�� �� �б�
	HBRUSH oldBrush = (HBRUSH)SelectObject(getMapDC(), CreateSolidBrush(RGB(255, 0, 255)));
	RectangleMake(getMapDC(), -10, -10, getMapBuffer()->getWidth() + 10, getMapBuffer()->getHeight() + 10);
	DeleteObject(SelectObject(getMapDC(), oldBrush));

	//�ȼ����۴� �׵θ� ������ �ؼ� ����
	oldBrush = (HBRUSH)SelectObject(getPixelDC(), CreateSolidBrush(RGB(255, 0, 255)));
	HPEN oldPen = (HPEN)SelectObject(getPixelDC(), CreatePen(PS_SOLID, 32, RGB(255, 0, 0)));
	RectangleMake(getPixelDC(), 0, 0, getPixelBuffer()->getWidth(), getPixelBuffer()->getHeight());
	DeleteObject(SelectObject(getPixelDC(), oldPen));
	DeleteObject(SelectObject(getPixelDC(), oldBrush));

	//�ʹ��� ������Ʈ�� ���� ���忡 �߰��ϱ�
	auto temp = new gameObject;
	temp->init(PTFLOAT(0, 0));
	temp->setKind(OBJKIND::MAPBUFFER);
	temp->changeImage("mapBuffer");
	temp->setLayer(LAYER::TERRAIN2);
	WORLD->addObject(temp);

	//�ȼ����� ����׿����� ���忡 �߰�
	temp = new gameObject;
	temp->init(PTFLOAT(0, 0));
	temp->setKind(OBJKIND::PIXELBUFFER);
	temp->changeImage("pixelBuffer");
	temp->setLayer((LAYER::Enum)(LAYER::PIXELDC));
	WORLD->addObject(temp);
}
