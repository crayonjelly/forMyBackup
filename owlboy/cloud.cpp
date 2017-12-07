#include "stdafx.h"
#include "cloud.h"


HRESULT cloud::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_layer = LAYER::BACK1;

	return S_OK;
}
void cloud::release()
{
	gameObject::release();
}
void cloud::update()
{
	gameObject::update();

	_pos.x += 1;

	if (_pos.x > 8000)
	{
		_pos.x = 2000;
	}
}
void cloud::render(float depthScale)
{
	gameObject::render(depthScale);
}
