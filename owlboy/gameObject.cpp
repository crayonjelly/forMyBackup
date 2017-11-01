#include "stdafx.h"
#include "gameObject.h"


HRESULT gameObject::init()
{
	_rc = RectMakeCenter(_pos.x, _pos.y, 10, 10);

	_image = NULL;
	_imageKey = "";
	_frame.x = _frame.y = 0;

	return S_OK;
}
void gameObject::release()
{

}
void gameObject::update()
{

}
void gameObject::render()
{
	
}


void gameObject::debugRender()
{
	EllipseMakeCenter(getMemDC(), _pos.x, _pos.y, 10, 10);
	LineMake(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.top);
	LineMake(getMemDC(), _rc.right, _rc.top, _rc.right, _rc.bottom);
	LineMake(getMemDC(), _rc.right, _rc.bottom, _rc.left, _rc.bottom);
	LineMake(getMemDC(), _rc.left, _rc.bottom, _rc.left, _rc.top);
}
void gameObject::changeImage(string imageKey)
{
	_imageKey = imageKey;
	_image = IMAGEMANAGER->findImage(imageKey);
}
