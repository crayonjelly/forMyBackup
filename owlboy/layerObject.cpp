#include "stdafx.h"
#include "layerObject.h"


HRESULT layerObject::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_layer = LAYER::TERRAIN2;
	_layerImage = NULL;
	_layerDC = NULL;

	return S_OK;
}
void layerObject::release()
{
	gameObject::release();

	if (_layerImage)
	{
		_layerImage->release();
		delete _layerImage;
		_layerImage = NULL;
		_layerDC = NULL;
	}
}
void layerObject::update()
{
	gameObject::update();
}
void layerObject::render(float depthScale)
{
	if (_layerImage)
	{
		_layerImage->render(getMemDC(),
			-CAMX * depthScale + _pos.x, -CAMY * depthScale + _pos.y);
	}
}
