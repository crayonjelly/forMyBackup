#include "stdafx.h"
#include "gameObject.h"


HRESULT gameObject::init(PTFLOAT pos)
{
	_pos = pos;
	_rc = RectMakeCenter(pos.x, pos.y, 10, 10);

	_image = NULL;
	_imageKey = "";
	_frame.x = _frame.y = 0;

	_kind = OBJKIND::NONE;
	_layer = LAYER::FRUIT;

	return S_OK;
}
void gameObject::release()
{

}
void gameObject::update()
{

}
void gameObject::render(float depthScale)
{
	//�⺻�����δ� �̹��� ������ �⺻������ �����ϱ�
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
	_imageSize.x = _image->getWidth();
	_imageSize.y = _image->getHeight();
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
