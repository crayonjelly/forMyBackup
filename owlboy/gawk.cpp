#include "stdafx.h"
#include "gawk.h"


HRESULT gawk::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_initialPos = pos;
	_rc = RectMakeCenter(pos.x, pos.y, 50, 50);

	_kind = OBJKIND::GAWK;
	_layer = LAYER::FRUIT;

	_bLeft = false;

	//-----------------------------
	_gawkSleep	= new gawkSleep;
	_gawkWake	= new gawkWake;
	_gawkFly	= new gawkFly;
	_gawkStun	= new gawkStun;
	//_gawkDie	= new gawkDie;

	_gawkSleep	->init(this);
	_gawkWake	->init(this);
	_gawkFly	->init(this);
	_gawkStun	->init(this);
	//_gawkDie	->init(this);
	//-----------------------------
	_state = _gawkSleep;
	_target = NULL;
	vector<gameObject*> vOtus = WORLD->findByKind(OBJKIND::OTUS);
	if (vOtus.size() >= 1)
	{
		_target = vOtus[0];
	}

	//콜백 추가
	_mCallback.insert(make_pair("otusAttack", [this](tagMessage msg)
	{
		if (this->_state->_stateName == "gawkSleep" ||
			this->_state->_stateName == "gawkWake" ||
			this->_state->_stateName == "gawkFly" ||
			this->_state->_stateName == "gawkStun")
		{
			this->changeState(_gawkStun);
		}
	}));

	return S_OK;
}
void gawk::release()
{
	gameObject::release();
}
void gawk::update()
{
	gameObject::update();

	_bLeftPast = _bLeft;

	_state->update();
}
void gawk::render(float depthScale)
{
	_state->render(depthScale);
}


void gawk::changeState(gawkState *state)
{
	string pastName = _state->_stateName;
	_state = state;
	_state->enter(pastName);
}

//==============  상태 객체  =====================
void gawkSleep::init(gawk *gawk)
{
	_stateName = "gawkSleep";
	_gawk = gawk;
	_image = IMAGEMANAGER->findImage("gawkSheet");
	_frame.x = 1;
	_frame.y = 1;
	_time1 = 0.0f;
}
void gawkSleep::enter(string pastStateName)
{
	_time1 = TIMEMANAGER->getWorldTime();
	if (_gawk->_bLeft)
	{
		_frame.x = 21;
	}
	else
	{
		_frame.x = 0;
	}
}
void gawkSleep::update()
{
	if (_gawk->_target &&
		calcDistance(_gawk->_pos, _gawk->_target->getPos()) <= 200)
	{
		_gawk->changeState(_gawk->_gawkWake);
		return;
	}
}
void gawkSleep::render(float depthScale)
{
	if (TIMEMANAGER->getWorldTime() - _time1 >= 0.3f ||
		_gawk->_bLeft != _gawk->_bLeftPast)
	{
		_time1 = TIMEMANAGER->getWorldTime();

		if (_gawk->_bLeft)
		{
			if (--_frame.x <= 19) _frame.x = 21;
		}
		else
		{
			if (++_frame.x >= 2) _frame.x = 0;
		}
	}

	if (_gawk->_bLeft)
	{
		_image->frameRender(_gawk->getMemDC(),
			-CAMX * depthScale + _gawk->_pos.x - _image->getFrameWidth() / 2 + 12,
			-CAMY * depthScale + _gawk->_pos.y - _image->getFrameHeight() / 2,
			_frame.x, _frame.y);
	}
	else
	{
		_image->frameRender(_gawk->getMemDC(),
			-CAMX * depthScale + _gawk->_pos.x - _image->getFrameWidth() / 2 - 12,
			-CAMY * depthScale + _gawk->_pos.y - _image->getFrameHeight() / 2,
			_frame.x, _frame.y);
	}
}
//---------------------------------------------------------------
void gawkWake::init(gawk *gawk)
{
	_stateName = "gawkWake";
	_gawk = gawk;
	_image = IMAGEMANAGER->findImage("gawkSheet");
	_frame.x = 10;
	_frame.y = 2;
	_time1 = 0.0f;
	_count1 = 0;
}
void gawkWake::enter(string pastStateName)
{
	_time1 = TIMEMANAGER->getWorldTime();
	_count1 = 0;

	if (_gawk->_target)
	{
		if (_gawk->_pos.x < _gawk->_target->getPos().x)
		{
			_gawk->_bLeft = false;
		}
		else
		{
			_gawk->_bLeft = true;
		}
	}

	if (_gawk->_bLeft)
	{
		_frame.x = 21 - _count1;
	}
	else
	{
		_frame.x = _count1;
	}
}
void gawkWake::update()
{
	if (TIMEMANAGER->getWorldTime() - _time1 >= 0.07f)
	{
		_time1 = TIMEMANAGER->getWorldTime();
		if (++_count1 >= 11)
		{
			_gawk->changeState(_gawk->_gawkFly);
			return;
		}

		if (_gawk->_bLeft)
		{
			_frame.x = 21 - _count1;
		}
		else
		{
			_frame.x = _count1;
		}
	}
}
void gawkWake::render(float depthScale)
{
	if (_gawk->_bLeft)
	{
		_image->frameRender(_gawk->getMemDC(),
			-CAMX * depthScale + _gawk->_pos.x - _image->getFrameWidth() / 2 + 12,
			-CAMY * depthScale + _gawk->_pos.y - _image->getFrameHeight() / 2,
			_frame.x, _frame.y);
	}
	else
	{
		_image->frameRender(_gawk->getMemDC(),
			-CAMX * depthScale + _gawk->_pos.x - _image->getFrameWidth() / 2 - 12,
			-CAMY * depthScale + _gawk->_pos.y - _image->getFrameHeight() / 2,
			_frame.x, _frame.y);
	}
}
//---------------------------------------------------------------
void gawkFly::init(gawk *gawk)
{
	_stateName = "gawkFly";
	_gawk = gawk;
	_image = IMAGEMANAGER->findImage("gawkSheet");
	_frame.x = 5;
	_frame.y = 0;
	_time1 = 0.0f;
	_count1 = 0;
}
void gawkFly::enter(string pastStateName)
{
	_time1 = TIMEMANAGER->getWorldTime();
	_count1 = 0;

	if (_gawk->_target)
	{
		if (_gawk->_pos.x < _gawk->_target->getPos().x)
		{
			_gawk->_bLeft = false;
			_frame.x = 0;
		}
		else
		{
			_gawk->_bLeft = true;
			_frame.x = 21;
		}
	}
}
void gawkFly::update()
{
	//타겟 맨날 유효검사 귀찮다
	if (_gawk->_target == NULL) return;

	//날개짓
	if (_count1 >= 5 &&
		_gawk->_pos.y  - _gawk->_target->getPos().y >= 0)
	{
		_count1 = 0;
	
		_gawk->_speed.y = -7.0f;
	}

	//일정 시간마다 카운트 올리기
	if (TIMEMANAGER->getWorldTime() - _time1 >= 0.08f)
	{
		_time1 = TIMEMANAGER->getWorldTime();
		if (_count1 < 5) ++_count1;
	}

	//속도 조절
	float gravity = 0.3f;
	_gawk->_speed.y += 0.3f;
	if (_gawk->_speed.y > GAWKSPEED) _gawk->_speed.y = GAWKSPEED;

	if (_gawk->_pos.x < _gawk->_target->getPos().x - 20)
	{
		_gawk->_speed.x = GAWKSPEED;
		_gawk->_bLeft = false;
	}
	else if (_gawk->_pos.x > _gawk->_target->getPos().x + 20)
	{
		_gawk->_speed.x = -GAWKSPEED;
		_gawk->_bLeft = true;
	}
	else _gawk->_speed.x = 0;


	//속도에 따라 이동
	_gawk->movePos(_gawk->_speed);
	_gawk->putRectCenterToPos();

	//카운트에 따라 프레임 설정
	if (_gawk->_bLeft)
	{
		_frame.x = 21 - _count1;
	}
	else
	{
		_frame.x = _count1;
	}
}
void gawkFly::render(float depthScale)
{
	if (_gawk->_bLeft)
	{
		_image->frameRender(_gawk->getMemDC(),
			-CAMX * depthScale + _gawk->_pos.x - _image->getFrameWidth() / 2 + 12,
			-CAMY * depthScale + _gawk->_pos.y - _image->getFrameHeight() / 2,
			_frame.x, _frame.y);
	}
	else
	{
		_image->frameRender(_gawk->getMemDC(),
			-CAMX * depthScale + _gawk->_pos.x - _image->getFrameWidth() / 2 - 12,
			-CAMY * depthScale + _gawk->_pos.y - _image->getFrameHeight() / 2,
			_frame.x, _frame.y);
	}
}
//---------------------------------------------------------------
void gawkStun::init(gawk *gawk)
{
	_stateName = "gawkStun";
	_gawk = gawk;
	_image = IMAGEMANAGER->findImage("gawkSheet");
	_frame.x = 0;
	_frame.y = 3;
	_time1 = 0.0f;
	_count1 = 0;
}
void gawkStun::enter(string pastStateName)
{
	_stunTime = 2.0f;
	PTFLOAT otusCenter = _gawk->_target->getPos();
	otusCenter.y -= (_gawk->_target->getRect().bottom - _gawk->_target->getRect().top) / 2;
	_gawk->_speed = (_gawk->_pos - otusCenter).unit() * 15.0f;
}
void gawkStun::update()
{
	if (_gawk->_speed.scalar() >= 2.0f)
	{
		_gawk->_speed.x *= 0.93f;
		_gawk->_speed.y *= 0.93f;
	}
	else _gawk->_speed.x = _gawk->_speed.y = 0.0f;

	_gawk->_pos += _gawk->_speed;
	_gawk->putRectCenterToPos();

	if (_stunTime > 0.0f)
	{
		_stunTime -= TIMEMANAGER->getElapsedTime();
	}
	else
	{
		_gawk->changeState(_gawk->_gawkFly);
	}
}
void gawkStun::render(float depthScale)
{
	if (_gawk->_bLeft)
	{
		_image->frameRender(_gawk->getMemDC(),
			-CAMX * depthScale + _gawk->_pos.x - _image->getFrameWidth() / 2 + 12,
			-CAMY * depthScale + _gawk->_pos.y - _image->getFrameHeight() / 2,
			_frame.x, _frame.y);
	}
	else
	{
		_image->frameRender(_gawk->getMemDC(),
			-CAMX * depthScale + _gawk->_pos.x - _image->getFrameWidth() / 2 - 12,
			-CAMY * depthScale + _gawk->_pos.y - _image->getFrameHeight() / 2,
			_frame.x, _frame.y);
	}
}
