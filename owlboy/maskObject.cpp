#include "stdafx.h"
#include "maskObject.h"


HRESULT maskObject::init(PTFLOAT pos)
{
	gameObject::init(pos);

	setLayer(LAYER::MASK);
	
	setPos(PTFLOAT(0, 0));
	_color = RGB(133, 75, 133);
	_alpha = 0;

	_image = new image;
	_image->init(WINSIZEX, WINSIZEY, RGB(255, 0, 255));

	return S_OK;
}
void maskObject::release()
{
	_image->release();
	delete _image;
	_image = NULL;

	gameObject::release();
}
void maskObject::update()
{
	gameObject::update();

	//255,50,100
	//_color = RGB(255, 255 + (50 - 255) * WORLD->getMainTime() / 10.0f,
	//	255 + (100 - 255) * WORLD->getMainTime() / 10.0f);
	_alpha = WORLD->getMainTime() / 10.0f * 200;
}
void maskObject::render(float depthScale)
{
	HBRUSH oldBrush = (HBRUSH)SelectObject(_image->getMemDC(), CreateSolidBrush(_color));
	RectangleMake(_image->getMemDC(), -10, -10, WINSIZEX + 10, WINSIZEY + 10);
	DeleteObject(SelectObject(_image->getMemDC(), oldBrush));

	_image->alphaRender(getMemDC(), _alpha);
}
