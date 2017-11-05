#pragma once
#include "mypoints.h"
#include "keyManager.h"


namespace LEVER
{
	enum Enum
	{
		NONE,
		LEFT_DOWN,	DOWN,		RIGHT_DOWN,
		LEFT,		NEUTRAL,	RIGHT,
		LEFT_UP,	UP,			RIGHT_UP
	};
}

LEVER::Enum calculateLever(int left, int right, int up, int down);
LEVER::Enum makingSomethingPerfectLever(int left, int right, int up, int down);
PTINT letsReturnAsPTINTforHorizonAndVertical(int left, int right, int up, int down);
