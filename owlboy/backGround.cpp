#include "stdafx.h"
#include "backGround.h"


HRESULT backGround::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_layer = LAYER::SKY3;

	return S_OK;
}
void backGround::release()
{
	gameObject::release();
}
void backGround::update()
{
	gameObject::update();
}
void backGround::render(float depthScale)
{
	gameObject::render(depthScale);
}
