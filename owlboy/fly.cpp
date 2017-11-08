#include "stdafx.h"
#include "fly.h"
#include "otus.h"


void fly::update()
{
	PTINT lever = LEVER::letsReturnAsPTINTforHorizonAndVertical('A', 'D', 'W', 'S');
	if (lever.x == 4 && lever.y == 4);
	else if (lever.x == 4)
	{
		switch (lever.y)
		{
		case -1:
			while (4 <= (int)_lever && (int)_lever <= 9)
			{
				_lever = (LEVER::Enum)((int)_lever - 3);
			}
			break;
		case 0:
			if (1 <= (int)_lever && (int)_lever <= 3) _lever = (LEVER::Enum)((int)_lever + 3);
			else if (7 <= (int)_lever && (int)_lever <= 9) _lever = (LEVER::Enum)((int)_lever - 3);
			break;
		case 1:
			while (1 <= (int)_lever && (int)_lever <= 6)
			{
				_lever = (LEVER::Enum)((int)_lever + 3);
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
		_lever = (LEVER::Enum)(5 + lever.x + lever.y * 3);
	}

	//레버에 따라서 이동
	switch (_lever)
	{
	case LEVER::NONE:
		break;
	case LEVER::LEFT_UP:
		_otus->movePos(-10, -10);
		break;
	case LEVER::UP:
		_otus->movePos(0, -10);
		break;
	case LEVER::RIGHT_UP:
		_otus->movePos(10, -10);
		break;
	case LEVER::LEFT:
		_otus->movePos(-10, 0);
		break;
	case LEVER::NEUTRAL:
		break;
	case LEVER::RIGHT:
		_otus->movePos(10, 0);
		break;
	case LEVER::LEFT_DOWN:
		_otus->movePos(-10, 10);
		break;
	case LEVER::DOWN:
		_otus->movePos(0, 10);
		break;
	case LEVER::RIGHT_DOWN:
		_otus->movePos(10, 10);
		break;
	}
}
