#include "stdafx.h"
#include "gameObject.h"


HRESULT gameObject::init(PTFLOAT pos)
{
	_bLive = true;
	_pos = pos;
	_rc = RectMakeCenter(pos.x, pos.y, 10, 10);

	_image = NULL;
	_imageKey = "";
	_frame.x = _frame.y = 0;

	_kind = OBJKIND::NONE;
	_layer = LAYER::FRUIT;

	auto test = [&](int a, float b, gameObject* c) {  };
	auto test2 = []() {};
	test(1,2,this);
	return S_OK;
}
void gameObject::release()
{
	_vMessage.clear();
	_mCallback.clear();
}
void gameObject::update()
{
	int size = _vMessage.size();
	if (size >= 1)
	{
		for (int i = 0; i < size; ++i)
		{
			auto msg = _vMessage[i];
			if (auto cb = _mCallback.at(msg.text)) cb(msg);
		}
		_vMessage.clear();
	}
}
void gameObject::render(float depthScale)
{
	//기본적으로는 이미지 있으면 기본렌더로 렌더하기
	if (_image)
	{
		_image->render(getMemDC(),
			-CAMX * depthScale + _pos.x, -CAMY * depthScale + _pos.y);
	}
}


void gameObject::debugRender(float depthScale)
{
	EllipseMakeCenter(getMemDC(), -CAMX * depthScale + _pos.x, -CAMY * depthScale + _pos.y, 10, 10);
	LineMake(getMemDC(), -CAMX * depthScale + _rc.left, -CAMY * depthScale + _rc.top, -CAMX * depthScale + _rc.right, -CAMY * depthScale + _rc.top);
	LineMake(getMemDC(), -CAMX * depthScale + _rc.right, -CAMY * depthScale + _rc.top, -CAMX * depthScale + _rc.right, -CAMY * depthScale + _rc.bottom);
	LineMake(getMemDC(), -CAMX * depthScale + _rc.right, -CAMY * depthScale + _rc.bottom, -CAMX * depthScale + _rc.left, -CAMY * depthScale + _rc.bottom);
	LineMake(getMemDC(), -CAMX * depthScale + _rc.left, -CAMY * depthScale + _rc.bottom, -CAMX * depthScale + _rc.left, -CAMY * depthScale + _rc.top);
}
void gameObject::putRectCenterToPos()
{
	int width = _rc.right - _rc.left;
	int height = _rc.bottom - _rc.top;

	_rc.left = _pos.x - width / 2;
	_rc.right = _rc.left + width;
	_rc.top = _pos.y - height / 2;
	_rc.bottom = _rc.top + height;
}
void gameObject::putRectUponPos()
{
	int width = _rc.right - _rc.left;
	int height = _rc.bottom - _rc.top;

	_rc.left = _pos.x - width / 2;
	_rc.right = _rc.left + width;
	_rc.bottom = _pos.y;
	_rc.top = _rc.bottom - height;
}
void gameObject::putPosCenterToRect()
{
	_pos.x = _rc.left + (_rc.right - _rc.left) / 2;
	_pos.y = _rc.top + (_rc.bottom - _rc.top) / 2;
}
void gameObject::changeImage(string imageKey)
{
	_imageKey = imageKey;
	_image = IMAGEMANAGER->findImage(imageKey);
	if (!_image)
	{
		_imageSize.x = 0;
		_imageSize.y = 0;
		return;
	}

	if (_image->getMaxFrameX() == 0 &&
		_image->getMaxFrameY() == 0)
	{
		_imageSize.x = _image->getWidth();
		_imageSize.y = _image->getHeight();
	}
	else
	{
		_imageSize.x = _image->getFrameWidth();
		_imageSize.y = _image->getFrameHeight();
	}
}
void gameObject::rcResetByImage()
{
	if (!_image) return;

	if (_image->getMaxFrameX() >= 2 || _image->getMaxFrameY() >= 2)
	{
		_rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());
	}
	else
	{
		_rc = RectMake(_pos.x, _pos.y, _image->getWidth(), _image->getHeight());
	}
}
void gameObject::sendMessage(tagMessage msg)
{
	_vMessage.push_back(msg);
}
