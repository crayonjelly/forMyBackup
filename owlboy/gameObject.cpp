#include "stdafx.h"
#include "gameObject.h"


HRESULT gameObject::init(PTFLOAT pos)
{
	_pos = pos;
	_rc = RectMakeCenter(pos.x, pos.y, 10, 10);

	_image = NULL;
	_imageKey = "";
	_frame.x = _frame.y = 0;

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
	//기본적으로는 이미지 있으면 기본렌더로 렌더하기
	if (_image)
	{
		_image->render(getMemDC(), -CAMX * depthScale + _pos.x, -CAMY * depthScale + _pos.y);
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
