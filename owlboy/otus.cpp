#include "stdafx.h"
#include "otus.h"


HRESULT otus::init(PTFLOAT pos)
{
	gameObject::init(pos);

	changeImage("hero");
	_imageSize = PTINT(_image->getFrameWidth(), _image->getFrameHeight());
	_rc = RectMakeCenter(pos.x, pos.y, _imageSize.x, _imageSize.y);
	_frame.x = 0;
	_frame.y = 2;

	_kind = OBJKIND::OTUS;
	_layer = LAYER::OTUS;

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
void otus::render(float depthScale)
{
	//날개짓 프레임 돌림
	static float timeSave = TIMEMANAGER->getWorldTime();
	if (TIMEMANAGER->getWorldTime() - timeSave >= 0.08f)
	{
		timeSave = TIMEMANAGER->getWorldTime();
		if (_frame.x < 10) ++_frame.x;
		else _frame.x = 0;
	}

	_image->frameRender(getMemDC(), -CAMX + _pos.x - _imageSize.x / 2, -CAMY + _pos.y - _imageSize.y / 2, _frame.x, _frame.y);
}


void otus::move()
{
	//if (KEYMANAGER->isStayKeyDown('A'))
	//{
	//	movePos(-10, 0);
	//}
	//if (KEYMANAGER->isStayKeyDown('D'))
	//{
	//	movePos(10, 0);
	//}
	//if (KEYMANAGER->isStayKeyDown('W'))
	//{
	//	movePos(0, -10);
	//}
	//if (KEYMANAGER->isStayKeyDown('S'))
	//{
	//	movePos(0, 10);
	//}

	//switch (LEVER::Enum inputLever = makingSomethingPerfectLever('A','D','W','S'))
	//{
	//case LEVER::NONE:
	//	break;
	//case LEVER::LEFT_DOWN:
	//case LEVER::DOWN:
	//case LEVER::RIGHT_DOWN:
	//case LEVER::LEFT:
	//case LEVER::NEUTRAL:
	//case LEVER::RIGHT:
	//case LEVER::LEFT_UP:
	//case LEVER::UP:
	//case LEVER::RIGHT_UP:
	//	_lever = inputLever;
	//	break;
	//}
	//
	//switch (_lever)
	//{
	//case LEVER::NONE:
	//	break;
	//case LEVER::LEFT_DOWN:
	//	movePos(-10, 10);
	//	break;
	//case LEVER::DOWN:
	//	movePos(0, 10);
	//	break;
	//case LEVER::RIGHT_DOWN:
	//	movePos(10, 10);
	//	break;
	//case LEVER::LEFT:
	//	movePos(-10, 0);
	//	break;
	//case LEVER::NEUTRAL:
	//	break;
	//case LEVER::RIGHT:
	//	movePos(10, 0);
	//	break;
	//case LEVER::LEFT_UP:
	//	movePos(-10, -10);
	//	break;
	//case LEVER::UP:
	//	movePos(0, -10);
	//	break;
	//case LEVER::RIGHT_UP:
	//	movePos(10, -10);
	//	break;
	//}

	PTINT lever = letsReturnAsPTINTforHorizonAndVertical('A', 'D', 'W', 'S');
	if (lever.x == 4 && lever.y == 4);
	else if (lever.x == 4)
	{
		switch (lever.y)
		{
		case -1:
			while (1 <= (int)_lever && (int)_lever <= 6)
			{
				_lever = (LEVER::Enum)((int)_lever + 3);
			}
			break;
		case 0:
			if (1 <= (int)_lever && (int)_lever <= 3) _lever = (LEVER::Enum)((int)_lever + 3);
			else if (7 <= (int)_lever && (int)_lever <= 9) _lever = (LEVER::Enum)((int)_lever - 3);
			break;
		case 1:
			while (4 <= (int)_lever && (int)_lever <= 9)
			{
				_lever = (LEVER::Enum)((int)_lever - 3);
			}
			break;
		}
	}
	else if (lever.y == 4)
	{
		switch (lever.x)
		{
		case -1:
			if ((int)_lever != 0)
				_lever = (LEVER::Enum)((int)_lever - ((int)_lever - 1) % 3);
			break;
		case 0:
			if ((int)_lever != 0)
				_lever = (LEVER::Enum)((int)_lever - (((int)_lever - 1) % 3 - 1));
			break;
		case 1:
			if ((int)_lever != 0)
				_lever = (LEVER::Enum)((int)_lever - (((int)_lever - 1) % 3 - 2));
			break;
		}
	}
	else
	{
		_lever = (LEVER::Enum)(5 + lever.x + -lever.y * 3);
	}

	switch (_lever)
	{
	case LEVER::NONE:
		break;
	case LEVER::LEFT_DOWN:
		movePos(-10, 10);
		break;
	case LEVER::DOWN:
		movePos(0, 10);
		break;
	case LEVER::RIGHT_DOWN:
		movePos(10, 10);
		break;
	case LEVER::LEFT:
		movePos(-10, 0);
		break;
	case LEVER::NEUTRAL:
		break;
	case LEVER::RIGHT:
		movePos(10, 0);
		break;
	case LEVER::LEFT_UP:
		movePos(-10, -10);
		break;
	case LEVER::UP:
		movePos(0, -10);
		break;
	case LEVER::RIGHT_UP:
		movePos(10, -10);
		break;
	}

	putRectCenterToPos();
}
