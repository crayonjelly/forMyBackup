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
		switch (lever)
		{
		case LEVER::NONE:			return PTINT( 4,  4);
		case LEVER::LEFT_UP:		return PTINT(-1, -1);
		case LEVER::UP:				return PTINT( 0, -1);
		case LEVER::RIGHT_UP:		return PTINT( 1, -1);
		case LEVER::LEFT:			return PTINT(-1,  0);
		case LEVER::NEUTRAL:		return PTINT( 0,  0);
		case LEVER::RIGHT:			return PTINT( 1,  0);
		case LEVER::LEFT_DOWN:		return PTINT(-1,  1);
		case LEVER::DOWN:			return PTINT( 0,  1);
		case LEVER::RIGHT_DOWN:		return PTINT( 1,  1);
		}
	}
}

LEVER::Enum calculateLever(int left, int right, int up, int down);
LEVER::Enum makingSomethingPerfectLever(int left, int right, int up, int down);
PTINT letsReturnAsPTINTforHorizonAndVertical(int left, int right, int up, int down);
