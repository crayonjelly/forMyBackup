#include "stdafx.h"
#include "owlboyScene.h"
#include "terrain.h"


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

	//�ʹ��ۿ� ���� �׸���

	//�ȼ����ۿ� �ȼ� �׸���
	IMAGEMANAGER->findImage("blueTest")->render(getPixelDC(), 500, 1000);

	//������ �����
	PTINT makePos(4000, 3200);

	auto makeTerrain = new terrain;
	makeTerrain->init(makePos);
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(getPixelDC(),
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	makeTerrain = new terrain;
	makeTerrain->init(makePos + PTINT(360, 0));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(getPixelDC(),
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	IMAGEMANAGER->findImage("bomboShop")->render(getMapDC(),
		makePos.x + 40, makePos.y + 30);
	IMAGEMANAGER->findImage("bomboShop_pixel")->render(getPixelDC(),
		makePos.x + 40, makePos.y + 30);
	IMAGEMANAGER->findImage("bomboHouse")->render(getMapDC(),
		makePos.x + 200, makePos.y - 220);

	//������ ��
	makePos = PTINT(5100, 2700);

	makeTerrain = new terrain;
	makeTerrain->init(makePos);
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(getPixelDC(),
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	makeTerrain = new terrain;
	makeTerrain->init(makePos + PTINT(200, 0));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(getPixelDC(),
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	makeTerrain = new terrain;
	makeTerrain->init(makePos + PTINT(400, 0));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(getPixelDC(),
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	IMAGEMANAGER->findImage("mandolynHouse")->render(getMapDC(),
		makePos.x + 300, makePos.y - 300);

	//��쳪 �����
	makePos = PTINT(5800, 3100);
	IMAGEMANAGER->findImage("saunaFront")->render(getMapDC(), makePos.x, makePos.y);
	IMAGEMANAGER->findImage("saunaFront_pixel")->render(getPixelDC(), makePos.x, makePos.y);

	//�׳� �� �ϳ�
	makeTerrain = new terrain;
	makeTerrain->init(PTFLOAT(4800, 3000));
	makeTerrain->changeImage("grassBrownPlatform2");
	makeTerrain->setLayer(LAYER::TERRAIN3);
	WORLD->addObject(makeTerrain);
	IMAGEMANAGER->findImage("grassBrownPlatform2_pixel")->render(getPixelDC(),
		makeTerrain->getPos().x, makeTerrain->getPos().y);

	//������ ��
	makePos = PTINT(4900, 4000);
	IMAGEMANAGER->findImage("otusHouse")->render(getMapDC(),
		makePos.x, makePos.y);
	IMAGEMANAGER->findImage("otusHouse_pixel")->render(getPixelDC(),
		makePos.x, makePos.y);

	//�ʹ��� ������Ʈ�� ���� ���忡 �߰��ϱ�
	auto temp = new gameObject;
	temp->init(PTFLOAT(0, 0));
	temp->changeImage("mapBuffer");
	temp->setLayer(LAYER::TERRAIN2);
	WORLD->addObject(temp);

	//�ȼ����� ����׿����� ���忡 �߰�
	temp = new gameObject;
	temp->init(PTFLOAT(0, 0));
	temp->changeImage("pixelBuffer");
	temp->setLayer((LAYER::Enum)(LAYER::PIXELDC));
	WORLD->addObject(temp);
}
