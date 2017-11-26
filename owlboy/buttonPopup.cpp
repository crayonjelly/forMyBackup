#include "stdafx.h"
#include "buttonPopup.h"


HRESULT buttonPopup::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_layer = LAYER::OTUS;
	_renderTimeSave = 0.0f;

	//오투스 타겟으로 잡기
	_target = NULL;
	auto vOtus = WORLD->findByKind(OBJKIND::OTUS);
	if (vOtus.size() >= 1)
	{
		_target = vOtus[0];
	}

	_bSignal = false;

	//콜백 넣자
	_mCallback.insert(make_pair("door", [this](tagMessage msg)
	{
		_bSignal = true;
	}));

	return S_OK;
}
void buttonPopup::release()
{
	gameObject::release();
}
void buttonPopup::update()
{
	_bSignal = false;

	//여기에서 메세지 처리하면서 "door" 받으면 _bSignal true로 만든다
	gameObject::update();

	if (!_bSignal) _bLive = false;

	_pos = _target->getPos() + PTFLOAT(0, -100);
}
void buttonPopup::render(float depthScale)
{
	if (!_image) return;

	if (_image->getMaxFrameX() == 0)
	{
		_image->render(getMemDC(),
			-CAMX * depthScale + _pos.x - _imageSize.x / 2,
			-CAMY * depthScale + _pos.y - _imageSize.y / 2);
	}
	else
	{
		if (TIMEMANAGER->getWorldTime() - _renderTimeSave >= 0.2f)
		{
			_renderTimeSave = TIMEMANAGER->getWorldTime();
			if (++_frame.x > _maxFrame.x) _frame.x = 0;
		}

		_image->frameRender(getMemDC(),
			-CAMX * depthScale + _pos.x - _imageSize.x / 2,
			-CAMY * depthScale + _pos.y - _imageSize.y / 2,
			_frame.x, _frame.y);
	}
}

void buttonPopup::changeImage(string imageKey)
{
	gameObject::changeImage(imageKey);

	auto image = IMAGEMANAGER->findImage(imageKey);
	if (!image) return;

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
