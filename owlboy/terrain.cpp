#include "stdafx.h"
#include "terrain.h"


HRESULT terrain::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_layer = LAYER::TERRAIN2;
	_renderTimeSave = 0.0f;
	_maxFrame = PTINT(0, 0);

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
	if (!_image) return;

	if (_image->getMaxFrameX() == 0)
	{
		_image->render(getMemDC(),
			-CAMX * depthScale + _pos.x,
			-CAMY * depthScale + _pos.y);
	}
	else
	{
		if (TIMEMANAGER->getWorldTime() - _renderTimeSave >= 0.1f)
		{
			_renderTimeSave = TIMEMANAGER->getWorldTime();
			if (++_frame.x > _maxFrame.x) _frame.x = 0;
		}

		_image->frameRender(getMemDC(),
			-CAMX * depthScale + _pos.x,
			-CAMY * depthScale + _pos.y,
			_frame.x, _frame.y);
	}
}


void terrain::changeImage(string imageKey)
{
	gameObject::changeImage(imageKey);

	auto image = IMAGEMANAGER->findImage(imageKey);
	_maxFrame.x = image->getMaxFrameX();
	_maxFrame.y = image->getMaxFrameY();
	
	if (image->getMaxFrameX() == 0)
	{
		rcResetByImage();
	}
	else
	{
		_rc = RectMake(_pos.x, _pos.y,
			_image->getFrameWidth(), _image->getFrameHeight());
	}
}
