#include "stdafx.h"
#include "effExplosion.h"


effExplosion::effExplosion(PTFLOAT pos)
{
	init(pos);
	WORLD->addObject(this);
}

HRESULT effExplosion::init(PTFLOAT pos)
{
	gameObject::init(pos);

	changeImage("explosion");
	_pos.x = pos.x - _imageSize.x / 2;
	_pos.y = pos.y - _imageSize.y / 2;

	setLayer(LAYER::FRUIT);

	_time1 = -TIMEMANAGER->getElapsedTime();

	_frame.x = 0;
	_frame.y = 0;

	return S_OK;
}
void effExplosion::release()
{
	gameObject::release();
}
void effExplosion::update()
{
	gameObject::update();

	_time1 += TIMEMANAGER->getElapsedTime();
	if (_time1 >= 0.04f)
	{
		_time1 = 0.0f;

		if (++_frame.x >= 19) setBLive(false);
	}
}
void effExplosion::render(float depthScale)
{
	_image->frameRender(getMemDC(),
		WINSIZEX / 2 + (_pos.x - CAMCX) * depthScale,
		WINSIZEY / 2 + (_pos.y - CAMCY) * depthScale,
		_frame.x, _frame.y);
}
