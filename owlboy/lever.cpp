#include "stdafx.h"
#include "lever.h"


////이 버전은 위쪽에 있는게 우선적용됨
//LEVER::Enum calculateLever(int left, int right, int up, int down)
//{
//	bool ll = keyManager::getSingleton()->isStayKeyDown(left);
//	bool rr = keyManager::getSingleton()->isStayKeyDown(right);
//	bool uu = keyManager::getSingleton()->isStayKeyDown(up);
//	bool dd = keyManager::getSingleton()->isStayKeyDown(down);
//
//	if (!ll && !rr && !uu && !dd) return LEVER::NEUTRAL;
//	else if (ll && uu) return LEVER::LEFT_UP;
//	else if (rr && uu) return LEVER::RIGHT_UP;
//	else if (ll && dd) return LEVER::LEFT_DOWN;
//	else if (rr && dd) return LEVER::RIGHT_DOWN;
//	else if (ll) return LEVER::LEFT;
//	else if (rr) return LEVER::RIGHT;
//	else if (uu) return LEVER::UP;
//	else if (dd) return LEVER::DOWN;
//	else return LEVER::NONE;
//}

//엄격 버전
LEVER::Enum calculateLever(int left, int right, int up, int down)
{
	bool ll = keyManager::getSingleton()->isStayKeyDown(left);
	bool rr = keyManager::getSingleton()->isStayKeyDown(right);
	bool uu = keyManager::getSingleton()->isStayKeyDown(up);
	bool dd = keyManager::getSingleton()->isStayKeyDown(down);

	if (!ll && !rr && !uu && !dd) return LEVER::NEUTRAL;
	else if (ll && uu && !rr && !dd) return LEVER::LEFT_UP;
	else if (rr && uu && !ll && !dd) return LEVER::RIGHT_UP;
	else if (ll && dd && !rr && !uu) return LEVER::LEFT_DOWN;
	else if (rr && dd && !ll && !uu) return LEVER::RIGHT_DOWN;
	else if (ll && !rr && !uu && !dd) return LEVER::LEFT;
	else if (rr && !ll && !uu && !dd) return LEVER::RIGHT;
	else if (uu && !ll && !rr && !dd) return LEVER::UP;
	else if (dd && !ll && !rr && !uu) return LEVER::DOWN;
	else return LEVER::NONE;
}

LEVER::Enum makingSomethingPerfectLever(int left, int right, int up, int down)
{
	bool ll = keyManager::getSingleton()->isStayKeyDown(left);
	bool rr = keyManager::getSingleton()->isStayKeyDown(right);
	bool uu = keyManager::getSingleton()->isStayKeyDown(up);
	bool dd = keyManager::getSingleton()->isStayKeyDown(down);

	if (!ll && !rr && !uu && !dd) return LEVER::NEUTRAL;
	//--------------------------------
	int horizon = 0;
	int vertical = 0;

	if (!ll && !rr) horizon = 0;
	else if (ll && !rr) horizon = 10;
	else if (!ll && rr) horizon = 20;
	else if (ll && rr)
	{
		bool lll = keyManager::getSingleton()->isOnceKeyDown(left);
		bool rrr = keyManager::getSingleton()->isOnceKeyDown(right);

		if (!lll && !rrr || lll && rrr) horizon = 30;
		else if (lll && !rrr) horizon = 10;
		else if (!lll && rrr) horizon = 20;
	}

	if (!uu && !dd) vertical = 0;
	else if (uu && !dd) vertical = 1;
	else if (!uu && dd) vertical = 2;
	else if (uu && dd)
	{
		bool uuu = keyManager::getSingleton()->isOnceKeyDown(up);
		bool ddd = keyManager::getSingleton()->isOnceKeyDown(down);

		if (!uuu && !ddd || uuu && ddd) vertical = 3;
		else if (uuu && !ddd) vertical = 1;
		else if (!uuu && ddd) vertical = 2;
	}

	switch (horizon + vertical)
	{
	case 12:
		return LEVER::LEFT_DOWN;
		break;
	case 2:
		return LEVER::DOWN;
		break;
	case 22:
		return LEVER::RIGHT_DOWN;
		break;
	case 10:
		return LEVER::LEFT;
		break;
	case 20:
		return LEVER::RIGHT;
		break;
	case 11:
		return LEVER::LEFT_UP;
		break;
	case 1:
		return LEVER::UP;
		break;
	case 21:
		return LEVER::RIGHT_UP;
		break;
	default:
		return LEVER::NONE;
		break;
	}
	//--------------------------------
	return LEVER::NONE;
}

PTINT letsReturnAsPTINTforHorizonAndVertical(int left, int right, int up, int down)
{
	bool ll = keyManager::getSingleton()->isStayKeyDown(left);
	bool rr = keyManager::getSingleton()->isStayKeyDown(right);
	bool uu = keyManager::getSingleton()->isStayKeyDown(up);
	bool dd = keyManager::getSingleton()->isStayKeyDown(down);

	PTINT result;

	if (!ll && !rr) result.x = 0;
	else if (ll && !rr) result.x = -1;
	else if (!ll && rr) result.x = 1;
	else if (ll && rr)
	{
		bool lll = keyManager::getSingleton()->isOnceKeyDown(left);
		bool rrr = keyManager::getSingleton()->isOnceKeyDown(right);

		if (!lll && !rrr || lll && rrr) result.x = 4;
		else if (lll && !rrr) result.x = -1;
		else if (!lll && rrr) result.x = 1;
	}

	if (!uu && !dd) result.y = 0;
	else if (uu && !dd) result.y = -1;
	else if (!uu && dd) result.y = 1;
	else if (uu && dd)
	{
		bool uuu = keyManager::getSingleton()->isOnceKeyDown(up);
		bool ddd = keyManager::getSingleton()->isOnceKeyDown(down);

		if (!uuu && !ddd || uuu && ddd) result.y = 4;
		else if (uuu && !ddd) result.y = -1;
		else if (!uuu && ddd) result.y = 1;
	}

	return result;
}
