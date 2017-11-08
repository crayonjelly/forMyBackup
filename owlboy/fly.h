#pragma once
#include "otusState.h"


class fly : public otusState
{
public:
	virtual void update();

	fly() {}
	fly(otus* otus) { _otus = otus; }
	virtual ~fly() {}
};
