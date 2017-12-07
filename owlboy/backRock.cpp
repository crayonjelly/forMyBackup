#include "stdafx.h"
#include "backRock.h"


HRESULT backRock::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_initPos.x = pos.x;
	_initPos.y = pos.y;

	_angle = RND->getFromFloatTo(0.0f, PI * 8);

	return S_OK;
}
void backRock::update()
{
	gameObject::update();

	_angle += 0.02f;

	_pos.y = _initPos.y + sinf(_angle) * 30;
}
