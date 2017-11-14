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
		_otus->changeObjectiveState2(_otus->_otusAttack, _stateName);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		//otus.changeObjectiveState(new otusFly);
		_otus->changeObjectiveState2(_otus->_otusFly, _stateName);
		return;
	}

	_otus->settingSpeedAir();

	//�������� ��Ȳ�� ����ĳ��Ʈ, �ƴѰ� �׳�
	if (_otus->_speed.y > 0)
	{
		PTFLOAT arrive = _otus->rayCastBlue(_otus->_pos, _otus->_speed);
		if (arrive == _otus->_pos + _otus->_speed) _otus->setPos(arrive);
		else
		{
			_otus->setPos(arrive);
			_otus->_speed.y = 0;
			//otus.changeObjectiveState(new otusStand);
			_otus->changeObjectiveState2(_otus->_otusStand, _stateName);
		}
	}
	else
	{
		_otus->movePos(_otus->_speed);
	}
	
	//��Ʈ ������
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
		_otus->changeObjectiveState2(_otus->_otusAttack, _stateName);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		otus._speed.y = 0;
		//otus.changeObjectiveState(new otusAir);
		otus.changeObjectiveState2(otus._otusAir, _stateName);
		return;
	}

	otus.settingSpeedFly();

	//�ӵ���� �̵��ϴµ�, ���̳� �Ʒ������� �̵��ϴ°� ����ĳ��Ʈ
	if (otus._speed.y >= 0)
	{
		PTFLOAT arrive = otus.rayCastBlue(otus._pos, otus._speed);
		if (arrive == otus._pos + otus._speed) otus.setPos(arrive);
		else
		{
			otus.setPos(arrive);
			otus._speed.y = 0;
			//otus.changeObjectiveState(new otusStand);
			otus.changeObjectiveState2(otus._otusStand, _stateName);
		}
	}
	else
	{
		otus.movePos(otus._speed);
	}

	//��Ʈ ������
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
		_otus->changeObjectiveState2(_otus->_otusAttack, _stateName);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		otus._speed.y = -10;
		//otus.changeObjectiveState(new otusAir);
		otus.changeObjectiveState2(otus._otusAir, _stateName);
		return;
	}

	//���� ���� ���� ������ �ȼ� �����ؼ� ��������
	COLORREF color = GetPixel(otus.getPixelDC(), otus._pos.x, otus._pos.y);
	if (!(GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255))
	{
		//otus.changeObjectiveState(new otusAir);
		otus.changeObjectiveState2(otus._otusAir, _stateName);
		return;
	}

	if (abs(LEVER::convertToPTINT(otus._lever).x) == 1)
	{
		//otus.changeObjectiveState(new otusRun);
		otus.changeObjectiveState2(otus._otusRun, _stateName);
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

}
void otusRun::update(otus &otus)
{
	otus.bLeftUpdate();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_otus->changeObjectiveState2(_otus->_otusAttack, _stateName);
		return;
	}
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		otus._speed.y = -10;
		//otus.changeObjectiveState(new otusAir);
		otus.changeObjectiveState2(otus._otusAir, _stateName);
		return;
	}

	//otus.groundMove();
	PTINT lever = LEVER::convertToPTINT(otus._lever);
	otus._speed.x = lever.x * 10;

	HDC dc = IMAGEMANAGER->findImage("pixelBuffer")->getMemDC();
	int y = otus._pos.y;
	COLORREF color = GetPixel(dc, otus._pos.x, y);
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
				otus.changeObjectiveState2(otus._otusAir, _stateName);
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

	otus.movePos(otus._speed);
	otus.putRectUponPos();
	//PTINT lever = LEVER::leverToPTINT(otus._lever);
	if (lever.x == 0) //otus.changeObjectiveState(new otusStand);
		otus.changeObjectiveState2(otus._otusStand, _stateName);
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

	//���� �����������
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
				_otus->changeObjectiveState2(_otus->_otusStand, _stateName);
				return;
			}
			else
			{
				_otus->changeObjectiveState2(_otus->_otusFly, _stateName);
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
	_frame.x = 0;
	_frame.y = 0;
	_time1 = 0.0f;
	_count1 = 0;
}
void otusGroundDash::enter(string pastStateName)
{

}
void otusGroundDash::update(otus &otus)
{

}
void otusGroundDash::render(otus &otus)
{

}
//--------------------------------
void otusAirDash::init(otus *otus)
{
	_stateName = "otusAirDash";
	_otus = otus;
	_image = IMAGEMANAGER->findImage("roll");
	_frame.x = 0;
	_frame.y = 0;
	_time1 = 0.0f;
	_count1 = 0;
}
void otusAirDash::enter(string pastStateName)
{

}
void otusAirDash::update(otus &otus)
{

}
void otusAirDash::render(otus &otus)
{

}
