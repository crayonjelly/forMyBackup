#pragma once
#include "gameObject.h"

class otus : public gameObject
{
private:
	enum STATE
	{
		STATE_NONE,
		STATE_STAND,
		STATE_RUN,
		STATE_RUN_DASH,
		STATE_FLY,
		STATE_FLY_DASH,
		STATE_ATTACK,
		STATE_END
	};
	//---------------------------------------------------
	LEVER::Enum _lever;
	bool _bLeft;
	bool _bAir;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	void move();

	otus() {}
	virtual ~otus() {}
};
