#include "stdafx.h"
#include "otus.h"


HRESULT otus::init(PTFLOAT pos)
{
	gameObject::init(pos);

	changeImage("hero");
	_imageSize = PTINT(_image->getFrameWidth(), _image->getFrameHeight());
	_rc = RectMake(pos.x - 50, pos.y - 200, 50, 90);
	_frame.x = 0;
	_frame.y = 2;

	_kind = OBJKIND::OTUS;
	_layer = LAYER::OTUS;

	//_state = STATE_FLY;
	_bLeft = false;
	_renderTimeSave = 0;

	_bPassDown = false;
	_downInputTimeSave = 0.0f;

	//-----------------------------
	_otusAir		= new otusAir;
	_otusStand		= new otusStand;
	_otusRun		= new otusRun;
	_otusFly		= new otusFly;
	_otusAttack		= new otusAttack;
	_otusGroundDash = new otusGroundDash;
	_otusAirDash	= new otusAirDash;

	_otusAir		->init(this);
	_otusStand		->init(this);
	_otusRun		->init(this);
	_otusFly		->init(this);
	_otusAttack		->init(this);
	_otusGroundDash	->init(this);
	_otusAirDash	->init(this);
	//-----------------------------
	_pState = _otusAir;

	return S_OK;
}
void otus::release()
{
	gameObject::release();
}
void otus::update()
{
	gameObject::update();

	_bLeftPast = _bLeft;

	leverUpdate();

	_pState->update(*this);
}
void otus::render(float depthScale)
{
	_pState->render(*this);

	char str[64];
	sprintf_s(str, "%f", _speed.y);
	TextOut(getMemDC(), 2, 400, str, strlen(str));
}


void otus::leverUpdate()
{
	//switch (LEVER::Enum inputLever = LEVER::makingSomethingPerfectLever('A','D','W','S'))
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
}

void otus::bLeftUpdate()
{
	if (LEVER::convertToPTINT(_lever).x == 1) _bLeft = false;
	else if (LEVER::convertToPTINT(_lever).x == -1) _bLeft = true;
}

//void otus::flyMove()
//{
//	//레버에 따라서 스피드 설정
//	switch (_lever)
//	{
//	case LEVER::NONE:
//		break;
//	case LEVER::LEFT_UP:
//		//movePos(-10, -10);
//		_speed.x = -10;
//		_speed.y = -10;
//		break;
//	case LEVER::UP:
//		//movePos(0, -10);
//		_speed.x = 0;
//		_speed.y = -10;
//		break;
//	case LEVER::RIGHT_UP:
//		//movePos(10, -10);
//		_speed.x = 10;
//		_speed.y = -10;
//		break;
//	case LEVER::LEFT:
//		//movePos(-10, 0);
//		_speed.x = -10;
//		_speed.y = 0;
//		break;
//	case LEVER::NEUTRAL:
//		_speed.x = _speed.y = 0;
//		break;
//	case LEVER::RIGHT:
//		//movePos(10, 0);
//		_speed.x = 10;
//		_speed.y = 0;
//		break;
//	case LEVER::LEFT_DOWN:
//		//movePos(-10, 10);
//		_speed.x = -10;
//		_speed.y = 10;
//		break;
//	case LEVER::DOWN:
//		//movePos(0, 10);
//		_speed.x = 0;
//		_speed.y = 10;
//		break;
//	case LEVER::RIGHT_DOWN:
//		//movePos(10, 10);
//		_speed.x = 10;
//		_speed.y = 10;
//		break;
//	}
//
//	bLeftUpdate();
//
//	movePos(_speed);
//
//	//좌표에 맞춰서 렉트 조정
//	putRectUponPos();
//}

void otus::settingSpeedFly()
{
	//레버에 따라서 스피드 설정
	PTINT lever = LEVER::convertToPTINT(_lever);

	if (lever.x == 4 || lever.y == 4) return;

	_speed = lever.unit() * RUNSPEED;
}

void otus::settingSpeedAir()
{
	float gravity = 0.0f;

	//상승-하강 속도에 따라서 중력(+y 방향 가속도) 설정
	if (_speed.y > 0)
	{
		gravity = 0.4f - 0.002f * (_speed.y * _speed.y);
	}
	else
	{
		gravity = 0.4f + 0.002f * (_speed.y * _speed.y);
	}

	//너무 작은 중력값은 무시
	if (gravity >= 0.001f)
	{
		_speed.y += gravity;
	}

	//x축 속도 설정
	PTINT lever = LEVER::convertToPTINT(_lever);
	if (lever.x != 4)
	{
		_speed.x = lever.x * RUNSPEED;
	}
}

//void otus::groundMove()
//{
//	PTINT lever = LEVER::leverToPTINT(_lever);
//	_speed.x = lever.x * 10;
//
//	HDC dc = IMAGEMANAGER->findImage("pixelBuffer")->getMemDC();
//	int y = _pos.y;
//	COLORREF color = GetPixel(dc, _pos.x, y);
//	if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
//	{
//		while (true)
//		{
//			color = GetPixel(dc, _pos.x, y - 1);
//			if (!(GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255))
//			{
//				break;
//			}
//			if (_pos.y - --y > 20) break;
//		}
//		_pos.y = y;
//	}
//	else
//	{
//		while (true)
//		{
//			if (++y - _pos.y > 20)
//			{
//				movePos(_speed);
//				putRectUponPos();
//				changeObjectiveState(new otusAir);
//				return;
//			}
//			color = GetPixel(dc, _pos.x, y);
//			if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
//			{
//				_pos.y = y;
//				break;
//			}
//		}
//	}
//
//	movePos(_speed);
//	putRectUponPos();
//}

PTFLOAT otus::pixelRayCast(PTFLOAT startPos, PTFLOAT speed)
{
	//스피드 0이면 시작점 그대로 돌려줌
	if (speed.x == 0 && speed.y == 0) return startPos;

	HDC dc = IMAGEMANAGER->findImage("pixelBuffer")->getMemDC();
	PTFLOAT pos = startPos;
	PTFLOAT dest = startPos + speed;
	PTFLOAT unit = speed.unit() * 0.9f;
	//COLORREF color = GetPixel(dc, pos.x, pos.y);
	COLORREF color;		//현재점은 검색하지 않음

	//범위용
	PTFLOAT minpt = PTFLOAT(min(startPos.x, dest.x), min(startPos.y, dest.y));
	PTFLOAT maxpt = PTFLOAT(max(startPos.x, dest.x), max(startPos.y, dest.y));

	//파란색 픽셀충돌 - 통과 가능한 땅
	if (unit.y > 0)
	{
		while (true)
		{
			pos.x += unit.x;
			pos.y += unit.y;
			if (!(minpt.x <= pos.x && pos.x <= maxpt.x &&
				minpt.y <= pos.y && pos.y <= maxpt.y))
				break;

			color = GetPixel(dc, pos.x, pos.y);
			if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
			{
				return pos;
			}
		}		//나왔다는건 dest까지 가는데 파란색 없었다는 것
	}

	return dest;
}
PTFLOAT otus::rayCastBlue(PTFLOAT startPos, PTFLOAT speed)
{
	//스피드 0이면 시작점 그대로 돌려줌
	if (speed.x == 0 && speed.y == 0) return startPos;

	HDC dc = IMAGEMANAGER->findImage("pixelBuffer")->getMemDC();
	PTFLOAT pos = startPos;
	PTFLOAT dest = startPos + speed;
	PTFLOAT unit = speed.unit() * 0.9f;
	COLORREF color;		//현재점은 검색하지 않음

	//범위용
	PTFLOAT minpt = PTFLOAT(min(startPos.x, dest.x), min(startPos.y, dest.y));
	PTFLOAT maxpt = PTFLOAT(max(startPos.x, dest.x), max(startPos.y, dest.y));

	while (true)
	{
		pos.x += unit.x;
		pos.y += unit.y;
		if (!(minpt.x <= pos.x && pos.x <= maxpt.x &&
			minpt.y <= pos.y && pos.y <= maxpt.y))
			break;

		color = GetPixel(dc, pos.x, pos.y);
		if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
		{
			return pos;
		}
	}		//나왔다는건 dest까지 가는데 파란색 없었다는 것

	return dest;
}
void otus::pixelCollision()
{
	//파란색 픽셀충돌 - 통과 가능한 땅
	if (_speed.y >= 0)
	{
		HDC dc = IMAGEMANAGER->findImage("pixelBuffer")->getMemDC();
		int i = _pos.y;
		COLORREF color = GetPixel(dc, _pos.x, i);

		//파란색에서 시작 (땅속)
		if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
		{
			while (--i >= _pos.y - 20)
			{
				color = GetPixel(dc, _pos.x, i);
				if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
				{
					continue;
				}
				else
				{
					_pos.y = i + 1;
					putRectUponPos();
					break;
				}
			}
		}
		//파란색 아닌곳에서 시작 (공중)
		else
		{
			while (++i <= _pos.y + 20)
			{
				color = GetPixel(dc, _pos.x, i);
				if (GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
				{
					_pos.y = i;
					putRectUponPos();
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}

	//for (int i = _pos.y - 20; i <= _pos.y + 20; ++i)
	//{
	//	COLORREF color = GetPixel(IMAGEMANAGER->findImage("pixelBuffer")->getMemDC(), _pos.x, i);
	//
	//	if (GetRValue(color) == 255 && GetGValue(color) == 0 && GetBValue(color) == 0)
	//	{
	//
	//	}
	//	else if (_speed.y > 0 &&
	//		GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255)
	//	{
	//		_pos.y = i;
	//		putRectUponPos();
	//		changeState(STATE_STAND);
	//
	//		break;
	//	}
	//}
}

//void otus::draw()
//{
//	//시간 저장용 변수 만든다
//	static float timeSave = TIMEMANAGER->getWorldTime();
//
//	switch (_state)
//	{
//	case otus::STATE_NONE:
//		break;
//	case otus::STATE_STAND:
//		_frame.y = 0;
//		if (TIMEMANAGER->getWorldTime() - timeSave >= 0.11f ||
//			_bLeft != _bLeftPast)
//		{
//			timeSave = TIMEMANAGER->getWorldTime();
//
//			if (_bLeft)
//			{
//				if (--_frame.x < 15) _frame.x = 25;
//			}
//			else
//			{
//				if (++_frame.x >= 13) _frame.x = 2;
//			}
//		}
//		break;
//	case otus::STATE_RUN:
//		_frame.y = 1;
//		if (TIMEMANAGER->getWorldTime() - timeSave >= 0.08f ||
//			_bLeft != _bLeftPast)
//		{
//			timeSave = TIMEMANAGER->getWorldTime();
//
//			if (_bLeft)
//			{
//				if (--_frame.x < 20) _frame.x = 27;
//			}
//			else
//			{
//				if (++_frame.x >= 8) _frame.x = 0;
//			}
//		}
//		break;
//	case otus::STATE_RUN_DASH:
//		break;
//	case otus::STATE_AIR:
//		_frame.y = 5;
//		if (TIMEMANAGER->getWorldTime() - timeSave >= 0.08f ||
//			_bLeft != _bLeftPast)
//		{
//			timeSave = TIMEMANAGER->getWorldTime();
//
//			if (_bLeft)
//			{
//				if (--_frame.x < 23) _frame.x = 25;
//			}
//			else
//			{
//				if (++_frame.x >= 5) _frame.x = 2;
//			}
//		}
//		break;
//	case otus::STATE_FLY:
//		_frame.y = 2;
//		if (TIMEMANAGER->getWorldTime() - timeSave >= 0.08f ||
//			_bLeft != _bLeftPast)
//		{
//			timeSave = TIMEMANAGER->getWorldTime();
//
//			if (_bLeft)
//			{
//				if (--_frame.x < 17) _frame.x = 27;
//			}
//			else
//			{
//				if (++_frame.x >= 11) _frame.x = 0;
//			}
//		}
//		break;
//	case otus::STATE_FLY_DASH:
//		break;
//	case otus::STATE_ATTACK:
//		break;
//	case otus::STATE_END:
//		break;
//	}
//
//	if (_bLeft)
//	{
//		_image->frameRender(getMemDC(), -CAMX + _pos.x - _imageSize.x / 2 - 15, -CAMY + _pos.y - 154, _frame.x, _frame.y);
//	}
//	else
//	{
//		_image->frameRender(getMemDC(), -CAMX + _pos.x - _imageSize.x / 2 + 15, -CAMY + _pos.y - 154, _frame.x, _frame.y);
//	}
//}

//void otus::changeState(STATE state)
//{
//	if (_state != state) _state = state;
//}

//void otus::changeObjectiveState(otusState *newState)
//{
//	SAFE_DELETE(_pState);
//	_pState = newState;
//	_pState->enter(*this);
//}

void otus::changeObjectiveState2(otusState *state)
{
	string temp = _pState->_stateName;
	_pState = state;
	_pState->enter(temp);
}

//void otus::updateAsState()
//{
//	switch (_state)
//	{
//	case otus::STATE_NONE:
//		break;
//	case otus::STATE_STAND:
//		groundMove();
//		switch (_lever)
//		{
//		case LEVER::NONE:
//			break;
//		case LEVER::LEFT_UP:
//		case LEVER::UP:
//		case LEVER::RIGHT_UP:
//			changeState(STATE_AIR);
//			break;
//		case LEVER::LEFT:
//		case LEVER::RIGHT:
//		case LEVER::LEFT_DOWN:
//		case LEVER::RIGHT_DOWN:
//			changeState(STATE_RUN);
//			break;
//		case LEVER::NEUTRAL:
//			break;
//		case LEVER::DOWN:
//			break;
//		}
//		break;
//	case otus::STATE_RUN:
//	{
//		groundMove();
//		PTINT lever = LEVER::leverToPTINT(_lever);
//		if (lever.y == -1) changeState(STATE_AIR);
//		else if (lever.x == 0) changeState(STATE_STAND);
//	}
//		break;
//	case otus::STATE_RUN_DASH:
//		break;
//	case otus::STATE_AIR:
//	{
//		if (KEYMANAGER->isOnceKeyDown('W'))
//		{
//			changeState(STATE_FLY);
//			break;
//		}
//		airMove();
//	}
//		break;
//	case otus::STATE_FLY:
//		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
//		{
//			changeState(STATE_AIR);
//			break;
//		}
//		flyMove();
//		break;
//	case otus::STATE_FLY_DASH:
//		break;
//	case otus::STATE_ATTACK:
//		break;
//	case otus::STATE_END:
//		break;
//	}
//}

void otus::bPassDownTrueUpdate()
{
	auto color = GetPixel(getPixelDC(), _pos.x, _pos.y);

	if (!(GetRValue(color) == 0 && GetGValue(color) == 0 && GetBValue(color) == 255))
	{
		_bPassDown = false;
		return;
	}
}

void otus::doubleDownUpdate()
{
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		if (TIMEMANAGER->getWorldTime() - _downInputTimeSave <= 0.2f)
		{
			_bPassDown = true;
			return;
		}

		_downInputTimeSave = TIMEMANAGER->getWorldTime();
	}
}
