#include "stdafx.h"
#include "cloud.h"


HRESULT cloud::init(PTFLOAT pos)
{
	gameObject::init(pos);

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
void cloud::render()
{
	if (_image)
	{
		_image->render(getMemDC(), _pos.x, _pos.y);
	}
}
