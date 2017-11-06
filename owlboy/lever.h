#pragma once
#include "mypoints.h"
#include "keyManager.h"


namespace LEVER
{
	enum Enum
	{
		NONE,
		LEFT_UP,	UP,			RIGHT_UP,
		LEFT,		NEUTRAL,	RIGHT,
		LEFT_DOWN,	DOWN,		RIGHT_DOWN
	};

	inline PTINT leverToPTINT(LEVER::Enum lever)
	{
		if (lever == LEVER::NONE) return PTINT(4, 4);
		else return PTINT(((int)lever - 1) % 3 - 1, ((int)lever - 1) / 3 - 1);
	}

	LEVER::Enum calcLeverStrict(int left, int right, int up, int down);
	LEVER::Enum makingSomethingPerfectLever(int left, int right, int up, int down);
	PTINT letsReturnAsPTINTforHorizonAndVertical(int left, int right, int up, int down);
}
