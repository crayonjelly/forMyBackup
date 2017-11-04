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
}
void cloud::render(float depthScale)
{
	gameObject::render(depthScale);
}
