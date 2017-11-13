#include "stdafx.h"
#include "otus.h"


void otusAir::enter(otus &otus)
{

}
void otusAir::update(otus &otus)
{
	otus.bLeftUpdate();

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		otus.changeObjectiveState(new otusFly);
		return;
	}

	otus.settingSpeedAir();

	//떨어지는 상황은 레이캐스트, 아닌건 그냥
	if (otus._speed.y > 0)
	{
		PTFLOAT arrive = otus.rayCastBlue(otus._pos, otus._speed);
		if (arrive == otus._pos + otus._speed) otus.setPos(arrive);
		else
		{
			otus.setPos(arrive);
			otus._speed.y = 0;
			otus.changeObjectiveState(new otusStand);
		}
	}
	else
	{
		otus.movePos(otus._speed);
	}
	
	//렉트 맞춰줌
	otus.putRectUponPos();
}
void otusAir::render(otus &otus)
{
	static float timeSave = TIMEMANAGER->getWorldTime();
	otus._frame.y = 5;
	if (TIMEMANAGER->getWorldTime() - timeSave >= 0.08f ||
		otus._bLeft != otus._bLeftPast)
	{
		timeSave = TIMEMANAGER->getWorldTime();

		if (otus._bLeft)
		{
			if (--otus._frame.x < 23) otus._frame.x = 25;
		}
		else
		{
			if (++otus._frame.x >= 5) otus._frame.x = 2;
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
void otusFly::enter(otus &otus)
{

}
void otusFly::update(otus &otus)
{
	otus.bLeftUpdate();

	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		otus._speed.y = 0;
		otus.changeObjectiveState(new otusAir);
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
			otus.changeObjectiveState(new otusStand);
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
	otus._frame.y = 2;
	if (TIMEMANAGER->getWorldTime() - otus._renderTimeSave >= 0.08f ||
		otus._bLeft != otus._bLeftPast)
	{
		otus._renderTimeSave = TIMEMANAGER->getWorldTime();

		if (otus._bLeft)
		{
			if (--otus._frame.x < 17) otus._frame.x = 27;
		}
		else
		{
			if (++otus._frame.x >= 11) otus._frame.x = 0;
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
void otusStand::enter(otus &otus)
{

}
void otusStand::update(otus &otus)
{
	otus.bLeftUpdate();

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		otus._speed.y = -10;
		otus.changeObjectiveState(new otusAir);
		return;
	}

	//땅이 변할 수도 있으니 픽셀 검출해서 공중으로
	COLORREF color = GetPixel(otus.getPixelDC(), otus._pos.x, otus._pos.y);
	if (!(GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255))
	{
		otus.changeObjectiveState(new otusAir);
		return;
	}

	if (abs(LEVER::convertToPTINT(otus._lever).x) == 1)
	{
		otus.changeObjectiveState(new otusRun);
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
void otusRun::enter(otus &otus)
{

}
void otusRun::update(otus &otus)
{
	otus.bLeftUpdate();

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		otus._speed.y = -10;
		otus.changeObjectiveState(new otusAir);
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
				otus.changeObjectiveState(new otusAir);
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
	if (lever.x == 0) otus.changeObjectiveState(new otusStand);
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
