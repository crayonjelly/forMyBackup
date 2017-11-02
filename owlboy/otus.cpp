#include "stdafx.h"
#include "otus.h"


HRESULT otus::init(PTFLOAT pos)
{
	gameObject::init();

	_pos = pos;

	changeImage("hero");
	_imageSize = PTINT(_image->getFrameWidth(), _image->getFrameHeight());
	_rc = RectMakeCenter(pos.x, pos.y, _imageSize.x, _imageSize.y);
	_frame.x = 0;
	_frame.y = 2;

	return S_OK;
}
void otus::release()
{
	gameObject::release();
}
void otus::update()
{
	gameObject::update();

	move();
}
void otus::render()
{
	//static int frame = 0;
	//++frame;
	//static int saveFrame = 0;
	//static int frameX = 0;
	//if (frame - saveFrame >= 5)
	//{
	//	saveFrame = frame;
	//	if (frameX < 10) ++frameX;
	//	else frameX = 0;
	//}

	static float timeSave = TIMEMANAGER->getWorldTime();
	if (TIMEMANAGER->getWorldTime() - timeSave >= 0.08)
	{
		timeSave = TIMEMANAGER->getWorldTime();
		if (_frame.x < 10) ++_frame.x;
		else _frame.x = 0;
	}

	_image->frameRender(getMemDC(), _pos.x - _imageSize.x / 2, _pos.y - _imageSize.y / 2, _frame.x, _frame.y);

	debugRender();
}


void otus::move()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		//movePos(-10, 0);

		PTFLOAT ff(-10, 0);
		PTINT ii = ff;
		movePos(ii);
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		movePos(10, 0);
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		movePos(0, -10);
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		movePos(0, 10);
	}

	putRectCenterToPos();
}
