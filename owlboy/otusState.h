#pragma once
#include "gameNode.h"

class otus;

namespace STATE
{
	enum Enum
	{
		NONE,
		STAND,
		RUN,
		RUN_DASH,
		FLY,
		FLY_DASH,
		ATTACK,
		END
	};
}


class otusState : public gameNode
{
protected:
	otus *_otus;
	LEVER::Enum _lever;

	STATE::Enum _state;
	otusState *_currentState;

public:
	virtual HRESULT init(otus* otus);
	virtual void release();
	virtual void update();

	//virtual void changeState(otusState* state);

	//inline void setAddress(otus* otus) { _otus = otus; }

	otusState() {}
	virtual ~otusState() {}
};
