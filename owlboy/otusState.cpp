#include "stdafx.h"
#include "otusState.h"
#include "fly.h"


HRESULT otusState::init(otus* otus)
{
	_otus = otus;
	_lever = LEVER::NONE;
	_state = STATE::FLY;

	_currentState = NULL;

	return S_OK;
}
void otusState::release()
{

}
void otusState::update()
{
	switch (_state)
	{
	case STATE::NONE:
		break;
	case STATE::STAND:
		break;
	case STATE::RUN:
		break;
	case STATE::RUN_DASH:
		break;
	case STATE::FLY:
	{
		fly a(_otus);
		a.update();
		//fly* a = new fly(_otus);
		//a->update();
	}
		break;
	case STATE::FLY_DASH:
		break;
	case STATE::ATTACK:
		break;
	case STATE::END:
		break;
	}
}


//void otusState::changeState(otusState* state)
//{
//	this->_currentState = state;
//}
