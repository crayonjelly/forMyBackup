#include "stdafx.h"
#include "terrain.h"


HRESULT terrain::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_layer = LAYER::TERRAIN;

	return S_OK;
}
void terrain::release()
{
	gameObject::release();
}
void terrain::update()
{
	gameObject::update();
}
void terrain::render(float depthScale)
{
	gameObject::render(depthScale);
}
