#include "stdafx.h"
#include "otus.h"


void otusAir::init(otus *otus)
{
	_stateName = "otusAir";
	_otus = otus;
	_image = IMAGEMANAGER->findImage("hero");
	_frame.x = _frame.y = 0;
}
void otusAir::enter(string pastStateName)
{

}
void otusAir::update(otus &otus)
{
	_otus->bLeftUpdate();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_otus->changeObjectiveState2(_otus->_otusAttack);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_otus->changeObjectiveState2(_otus->_otusAirDash);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		//otus.changeObjectiveState(new otusFly);
		_otus->changeObjectiveState2(_otus->_otusFly);
		return;
	}

	_otus->settingSpeedAir();

	//떨어지는 상황은 레이캐스트, 아닌건 그냥
	if (_otus->_speed.y > 0)
	{
		PTFLOAT arrive = _otus->rayCastBlue(_otus->_pos, _otus->_speed);
		if (arrive == _otus->_pos + _otus->_speed) _otus->setPos(arrive);
		else
		{
			_otus->setPos(arrive);
			_otus->_speed.y = 0;
			//otus.changeObjectiveState(new otusStand);
			_otus->changeObjectiveState2(_otus->_otusStand);
		}
	}
	else
	{
		_otus->movePos(_otus->_speed);
	}
	
	//렉트 맞춰줌
	_otus->putRectUponPos();
}
void otusAir::render(otus &otus)
{
	static float timeSave = TIMEMANAGER->getWorldTime();
	_frame.y = 5;
	if (TIMEMANAGER->getWorldTime() - timeSave >= 0.08f ||
		otus._bLeft != otus._bLeftPast)
	{
		timeSave = TIMEMANAGER->getWorldTime();

		if (otus._bLeft)
		{
			if (--_frame.x < 23) _frame.x = 25;
		}
		else
		{
			if (++_frame.x >= 5) _frame.x = 2;
		}
	}

	if (otus._bLeft)
	{
		otus._image->frameRender(otus.getMemDC(), -CAMX + otus._pos.x - otus._imageSize.x / 2 - 15, -CAMY + otus._pos.y - 154, _frame.x, _frame.y);
	}
	else
	{
		otus._image->frameRender(otus.getMemDC(), -CAMX + otus._pos.x - otus._imageSize.x / 2 + 15, -CAMY + otus._pos.y - 154, _frame.x, _frame.y);
	}
}
//--------------------------------
void otusFly::init(otus *otus)
{
	_stateName = "otusFly";
	_otus = otus;
	_image = IMAGEMANAGER->findImage("hero");
	_frame.x = 10;
	_frame.y = 2;
}
void otusFly::enter(string pastStateName)
{
	_time1 = TIMEMANAGER->getWorldTime();
	if (_otus->_bLeft)
	{
		_frame.x = 27;
	}
	else
	{
		_frame.x = 0;
	}
}
void otusFly::update(otus &otus)
{
	otus.bLeftUpdate();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_otus->changeObjectiveState2(_otus->_otusAttack);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_otus->changeObjectiveState2(_otus->_otusAirDash);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		otus._speed.y = 0;
		//otus.changeObjectiveState(new otusAir);
		otus.changeObjectiveState2(otus._otusAir);
		return;
	}

	otus.settingSpeedFly();

	//속도대로 이동하는데, 옆이나 아래쪽으로 이동하는건 레이캐스트
	if (otus._speed.y >= 0)
	{
		PTFLOAT arrive = otus.rayCastBlue(otus._pos, otus._speed);
		if (arrive == otus._pos + otus._speed) otus.setPos(arrive);
		else
		{
			otus.setPos(arrive);
			otus._speed.y = 0;
			//otus.changeObjectiveState(new otusStand);
			otus.changeObjectiveState2(otus._otusStand);
		}
	}
	else
	{
		otus.movePos(otus._speed);
	}

	//렉트 맞춰줌
	otus.putRectUponPos();
}
void otusFly::render(otus &otus)
{
	if (TIMEMANAGER->getWorldTime() - _time1 >= 0.08f ||
		_otus->_bLeft != _otus->_bLeftPast)
	{
		_time1 = TIMEMANAGER->getWorldTime();

		if (_otus->_bLeft)
		{
			if (--_frame.x < 17) _frame.x = 27;
		}
		else
		{
			if (++_frame.x >= 11) _frame.x = 0;
		}
	}

	if (_otus->_bLeft)
	{
		_otus->_image->frameRender(_otus->getMemDC(),
			-CAMX + _otus->_pos.x - _otus->_imageSize.x / 2 - 15,
			-CAMY + _otus->_pos.y - 154,
			_frame.x, _frame.y);
	}
	else
	{
		_otus->_image->frameRender(_otus->getMemDC(),
			-CAMX + _otus->_pos.x - _otus->_imageSize.x / 2 + 15,
			-CAMY + _otus->_pos.y - 154,
			_frame.x, _frame.y);
	}
}
//--------------------------------
void otusStand::init(otus *otus)
{
	_stateName = "otusStand";
	_otus = otus;
	_image = IMAGEMANAGER->findImage("hero");
	_frame.x = _frame.y = 0;
}
void otusStand::enter(string pastStateName)
{

}
void otusStand::update(otus &otus)
{
	otus.bLeftUpdate();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_otus->changeObjectiveState2(_otus->_otusAttack);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_otus->changeObjectiveState2(_otus->_otusGroundDash);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		otus._speed.y = -16;
		//otus.changeObjectiveState(new otusAir);
		otus.changeObjectiveState2(otus._otusAir);
		return;
	}

	//땅이 변할 수도 있으니 픽셀 검출해서 공중으로
	COLORREF color = GetPixel(otus.getPixelDC(), otus._pos.x, otus._pos.y);
	if (!(GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255))
	{
		//otus.changeObjectiveState(new otusAir);
		otus.changeObjectiveState2(otus._otusAir);
		return;
	}

	if (abs(LEVER::convertToPTINT(otus._lever).x) == 1)
	{
		//otus.changeObjectiveState(new otusRun);
		otus.changeObjectiveState2(otus._otusRun);
	}
}
void otusStand::render(otus &otus)
{
	otus._frame.y = 0;
	if (TIMEMANAGER->getWorldTime() - otus._renderTimeSave >= 0.11f ||
		otus._bLeft != otus._bLeftPast)
	{
		otus._renderTimeSave = TIMEMANAGER->getWorldTime();

		if (otus._bLeft)
		{
			if (--otus._frame.x < 15) otus._frame.x = 25;
		}
		else
		{
			if (++otus._frame.x >= 13) otus._frame.x = 2;
		}
	}

	if (otus._bLeft)
	{
		otus._image->frameRender(otus.getMemDC(), -CAMX + otus._pos.x - otus._imageSize.x / 2 - 15, -CAMY + otus._pos.y - 154, otus._frame.x, otus._frame.y);
	}
	else
	{
		otus._image->frameRender(otus.getMemDC(), -CAMX + otus._pos.x - otus._imageSize.x / 2 + 15, -CAMY + otus._pos.y - 154, otus._frame.x, otus._frame.y);
	}
}
//--------------------------------
void otusRun::init(otus *otus)
{
	_stateName = "otusRun";
	_otus = otus;
	_image = IMAGEMANAGER->findImage("hero");
	_frame.x = _frame.y = 0;
}
void otusRun::enter(string pastStateName)
{
	_otus->_speed.y = 0;
}
void otusRun::update(otus &otus)
{
	otus.bLeftUpdate();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_otus->changeObjectiveState2(_otus->_otusAttack);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_otus->changeObjectiveState2(_otus->_otusGroundDash);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		otus._speed.y = -16;
		//otus.changeObjectiveState(new otusAir);
		otus.changeObjectiveState2(otus._otusAir);
		return;
	}

	//otus.groundMove();
	PTINT lever = LEVER::convertToPTINT(_otus->_lever);
	if (lever.x == 0)
	{
		_otus->changeObjectiveState2(_otus->_otusStand);
		return;
	}
	if (lever.x != 4)
	{
		_otus->_speed.x = lever.x * RUNSPEED;
	}

	_otus->movePos(_otus->_speed);
	_otus->putRectUponPos();

	//땅 찾음
	HDC dc = _otus->getPixelDC();
	int y = _otus->_pos.y;
	COLORREF color = GetPixel(dc, _otus->_pos.x, y);
	if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
	{
		while (true)
		{
			color = GetPixel(dc, otus._pos.x, y - 1);
			if (!(GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255))
			{
				break;
			}
			if (otus._pos.y - --y > 20) break;
		}
		otus._pos.y = y;
	}
	else
	{
		while (true)
		{
			if (++y - otus._pos.y > 20)
			{
				otus.movePos(otus._speed);
				otus.putRectUponPos();
				//otus.changeObjectiveState(new otusAir);
				otus.changeObjectiveState2(otus._otusAir);
				return;
			}
			color = GetPixel(dc, otus._pos.x, y);
			if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
			{
				otus._pos.y = y;
				break;
			}
		}
	}

	_otus->putRectUponPos();
}
void otusRun::render(otus &otus)
{
	otus._frame.y = 1;
	if (TIMEMANAGER->getWorldTime() - otus._renderTimeSave >= 0.08f ||
		otus._bLeft != otus._bLeftPast)
	{
		otus._renderTimeSave = TIMEMANAGER->getWorldTime();

		if (otus._bLeft)
		{
			if (--otus._frame.x < 20) otus._frame.x = 27;
		}
		else
		{
			if (++otus._frame.x >= 8) otus._frame.x = 0;
		}
	}

	if (otus._bLeft)
	{
		otus._image->frameRender(otus.getMemDC(), -CAMX + otus._pos.x - otus._imageSize.x / 2 - 15, -CAMY + otus._pos.y - 154, otus._frame.x, otus._frame.y);
	}
	else
	{
		otus._image->frameRender(otus.getMemDC(), -CAMX + otus._pos.x - otus._imageSize.x / 2 + 15, -CAMY + otus._pos.y - 154, otus._frame.x, otus._frame.y);
	}
}
//--------------------------------
void otusAttack::init(otus *otus)
{
	_stateName = "otusAttack";
	_otus = otus;
	_image = IMAGEMANAGER->findImage("hero2");
	_frame.x = 3;
	_frame.y = 11;
	_time1 = 0.0f;
	_count1 = 0;
}
void otusAttack::enter(string pastStateName)
{
	_time1 = TIMEMANAGER->getWorldTime();
	_count1 = 0;

	if (_otus->_bLeft)
	{
		_frame.x = 19 - _count1;
	}
	else
	{
		_frame.x = _count1;
	}

	//공격 생성해줘야함
}
void otusAttack::update(otus &otus)
{
	if (TIMEMANAGER->getWorldTime() - _time1 >= 0.08f)
	{
		_time1 = TIMEMANAGER->getWorldTime();
		if (++_count1 >= 4)
		{
			auto color = GetPixel(_otus->getPixelDC(), _otus->_pos.x, _otus->_pos.y);
			if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
			{
				_otus->changeObjectiveState2(_otus->_otusStand);
				return;
			}
			else
			{
				_otus->changeObjectiveState2(_otus->_otusFly);
				return;
			}
		}

		if (_otus->_bLeft)
		{
			_frame.x = 19 - _count1;
		}
		else
		{
			_frame.x = _count1;
		}
	}
}
void otusAttack::render(otus &otus)
{
	if (_otus->_bLeft)
	{
		_image->frameRender(_otus->getMemDC(),
			-CAMX + _otus->_pos.x - _otus->_imageSize.x / 2 - 15,
			-CAMY + _otus->_pos.y - 154,
			_frame.x, _frame.y);
	}
	else
	{
		_image->frameRender(_otus->getMemDC(),
			-CAMX + _otus->_pos.x - _otus->_imageSize.x / 2 + 15,
			-CAMY + _otus->_pos.y - 154,
			_frame.x, _frame.y);
	}
}
//--------------------------------
void otusGroundDash::init(otus *otus)
{
	_stateName = "otusGroundDash";
	_otus = otus;
	_image = IMAGEMANAGER->findImage("rollGround");
	_frame.x = 5;
	_frame.y = 1;
	_time1 = 0.0f;
	_count1 = 0;
}
void otusGroundDash::enter(string pastStateName)
{
	_time1 = TIMEMANAGER->getWorldTime();
	_count1 = 0;

	if (_otus->_bLeft)
	{
		_frame.y = 1;
		_frame.x = 5 - _count1;
		_otus->_speed.x = -13;
	}
	else
	{
		_frame.y = 0;
		_frame.x = _count1;
		_otus->_speed.x = 13;
	}
}
void otusGroundDash::update(otus &otus)
{
	if (TIMEMANAGER->getWorldTime() - _time1 >= 0.06f)
	{
		_time1 = TIMEMANAGER->getWorldTime();
		if (++_count1 > 5)
		{
			_otus->changeObjectiveState2(_otus->_otusStand);
		}

		if (_otus->_bLeft)
		{
			_frame.x = 5 - _count1;
		}
		else
		{
			_frame.x = _count1;
		}
	}

	_otus->movePos(_otus->_speed);
	_otus->putRectUponPos();

	//땅 찾음
	HDC dc = _otus->getPixelDC();
	int y = _otus->_pos.y;
	COLORREF color = GetPixel(dc, _otus->_pos.x, y);
	if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
	{
		while (true)
		{
			color = GetPixel(dc, otus._pos.x, y - 1);
			if (!(GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255))
			{
				break;
			}
			if (otus._pos.y - --y > 20) break;
		}
		otus._pos.y = y;
	}
	else
	{
		while (true)
		{
			if (++y - otus._pos.y > 20)
			{
				otus.movePos(otus._speed);
				otus.putRectUponPos();
				//otus.changeObjectiveState(new otusAir);
				otus.changeObjectiveState2(otus._otusAir);
				return;
			}
			color = GetPixel(dc, otus._pos.x, y);
			if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
			{
				otus._pos.y = y;
				break;
			}
		}
	}

	_otus->putRectUponPos();
}
void otusGroundDash::render(otus &otus)
{
	if (_otus->_bLeft)
	{
		_image->frameRender(_otus->getMemDC(),
			-CAMX + _otus->_pos.x - _otus->_imageSize.x / 2 - 15,
			-CAMY + _otus->_pos.y - 154,
			_frame.x, _frame.y);
	}
	else
	{
		_image->frameRender(_otus->getMemDC(),
			-CAMX + _otus->_pos.x - _otus->_imageSize.x / 2 + 15,
			-CAMY + _otus->_pos.y - 154,
			_frame.x, _frame.y);
	}
}
//--------------------------------
void otusAirDash::init(otus *otus)
{
	_stateName = "otusAirDash";
	_otus = otus;
	_image = IMAGEMANAGER->findImage("roll");
	_frame.x = 8;
	_frame.y = 1;
	_time1 = 0.0f;
	_count1 = 0;
}
void otusAirDash::enter(string pastStateName)
{
	_time1 = TIMEMANAGER->getWorldTime();
	_count1 = 0;

	if (_otus->_bLeft)
	{
		_frame.y = 1;
		_frame.x = 8 - _count1;
	}
	else
	{
		_frame.y = 0;
		_frame.x = _count1;
	}

	PTINT lever = LEVER::convertToPTINT(_otus->_lever);
	if (lever.x != 4 && lever.y != 4)
	{
		_otus->_speed = lever.unit() * 13;
	}
}
void otusAirDash::update(otus &otus)
{
	if (TIMEMANAGER->getWorldTime() - _time1 >= 0.05f)
	{
		_time1 = TIMEMANAGER->getWorldTime();
		if (++_count1 > 8)
		{
			_otus->changeObjectiveState2(_otus->_otusFly);
		}

		if (_otus->_bLeft)
		{
			_frame.x = 8 - _count1;
		}
		else
		{
			_frame.x = _count1;
		}
	}

	//속도대로 이동하는데, 옆이나 아래쪽으로 이동하는건 레이캐스트
	if (otus._speed.y >= 0)
	{
		PTFLOAT arrive = otus.rayCastBlue(otus._pos, otus._speed);
		if (arrive == otus._pos + otus._speed) otus.setPos(arrive);
		else
		{
			otus.setPos(arrive);
			otus._speed.y = 0;
			//otus.changeObjectiveState(new otusStand);
			otus.changeObjectiveState2(otus._otusStand);
		}
	}
	else
	{
		otus.movePos(otus._speed);
	}

	//렉트 맞춰줌
	otus.putRectUponPos();
}
void otusAirDash::render(otus &otus)
{
	if (_otus->_bLeft)
	{
		_image->frameRender(_otus->getMemDC(),
			-CAMX + _otus->_pos.x - _otus->_imageSize.x / 2 - 15,
			-CAMY + _otus->_pos.y - 154,
			_frame.x, _frame.y);
	}
	else
	{
		_image->frameRender(_otus->getMemDC(),
			-CAMX + _otus->_pos.x - _otus->_imageSize.x / 2 + 15,
			-CAMY + _otus->_pos.y - 154,
			_frame.x, _frame.y);
	}
}
