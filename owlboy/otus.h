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
		STATE_AIR,
		STATE_FLY,
		STATE_FLY_DASH,
		STATE_ATTACK,
		STATE_END
	};
	//---------------------------------------------------
	LEVER::Enum _lever;

	STATE _state;
	STATE _pastState;
	bool _bLeft;
	bool _bLeftPast;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	void leverUpdate();
	void updateAsState();
	void groundMove();
	void airMove();
	void flyMove();
	PTFLOAT pixelRayCast(PTFLOAT startPos, PTFLOAT speed);
	void pixelCollision();
	void changeState(STATE state);
	void draw();

	otus() {}
	virtual ~otus() {}
};
