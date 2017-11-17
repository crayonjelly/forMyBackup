#include "stdafx.h"
#include "gawk.h"


HRESULT gawk::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_rc = RectMakeCenter(pos.x, pos.y, 50, 50);

	_kind = OBJKIND::GAWK;
	_layer = LAYER::FRUIT;

	_bLeft = false;

	//-----------------------------
	_gawkSleep	= new gawkSleep;
	_gawkWake	= new gawkWake;
	_gawkFly	= new gawkFly;
	//_gawkStun	= new gawkStun;
	//_gawkDie	= new gawkDie;

	_gawkSleep	->init(this);
	_gawkWake	->init(this);
	_gawkFly	->init(this);
	//_gawkStun	->init(this);
	//_gawkDie	->init(this);
	//-----------------------------
	_state = _gawkSleep;
	_target = NULL;
	vector<gameObject*> vOtus = WORLD->findByKind(OBJKIND::OTUS);
	if (vOtus.size() >= 1)
	{
		_target = vOtus[0];
	}

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

//==============  ���� ��ü  =====================
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
	if (calcDistance(_gawk->_pos, _gawk->_target->getPos()) <= 300)
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

	//��� �� ������ ��ġ Ȯ���ؼ� �¿� �����س��� �������

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
}
void gawkFly::update()
{
	//_frame.x �����鼭 �̰� �������� ������ ���� Ȯ���ϰ�
	//�ѹ� �� ������ �������� ��������
	//�⺻ �Ʒ����� �ӵ� �����ϰ�
	//������ �ѹ� �� �� �ӵ� �� ƨ�ܼ� ������ ������ �ɰŰ�����?

	//if (������ ����)
	//{
	//	_count1 = 0;
	//
	//	_gawk->_speed.y = -8;
	//}

	//���� �ð����� ī��Ʈ �ø���
	if (TIMEMANAGER->getWorldTime() - _time1 >= 0.4f)
	{
		_time1 = TIMEMANAGER->getWorldTime();
		if (_count1 < 5) ++_count1;
	}

	//�ӵ� ����
	float gravity = 0.3f;
	_gawk->_speed.y += 0.3f;
	if (_gawk->_speed.y > 5.0f) _gawk->_speed.y = 5.0f;

	//�ӵ��� ���� �̵�
	_gawk->movePos(_gawk->_speed);

	//ī��Ʈ�� ���� ������ ����
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