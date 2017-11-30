#pragma once
#include "gameObject.h"

class buttonPopup;


class otus : public gameObject
{
private:
#define RUNSPEED 6

	friend class otusState;
	friend class otusAir;
	friend class otusStand;
	friend class otusRun;
	friend class otusFly;
	friend class otusAttack;
	friend class otusGroundDash;
	friend class otusAirDash;
	otusAir			*_otusAir;
	otusStand		*_otusStand;
	otusRun			*_otusRun;
	otusFly			*_otusFly;
	otusAttack		*_otusAttack;
	otusGroundDash	*_otusGroundDash;
	otusAirDash		*_otusAirDash;
	//---------------------------------------------------
	//enum STATE
	//{
	//	STATE_NONE,
	//	STATE_STAND,
	//	STATE_RUN,
	//	STATE_RUN_DASH,
	//	STATE_AIR,
	//	STATE_FLY,
	//	STATE_FLY_DASH,
	//	STATE_ATTACK,
	//	STATE_END
	//};
	//---------------------------------------------------
	LEVER::Enum _lever;

	//STATE _state;
	//STATE _pastState;
	bool _bLeft;
	bool _bLeftPast;
	float _renderTimeSave;

	bool _bPassDown;
	float _downInputTimeSave;

	otusState *_pState;
	gameObject *_btn;

	PTFLOAT _leftPT;
	PTFLOAT _rightPT;
	PTFLOAT _topPT;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	virtual void debugRender(float depthScale = 1.0f);

	void leverUpdate();
	void bLeftUpdate();
	//void updateAsState();
	//void groundMove();
	void settingSpeedAir();
	//void flyMove();
	void settingSpeedFly();
	PTFLOAT pixelRayCast(PTFLOAT startPos, PTFLOAT speed);
	PTFLOAT rayCastBlue(PTFLOAT startPos, PTFLOAT speed);
	PTFLOAT rayCastColor(PTFLOAT startPos, PTFLOAT speed, COLORREF castColor);
	void pixelCollision();
	//void changeState(STATE state);
	//void changeObjectiveState(otusState *newState);
	void changeObjectiveState2(otusState *state);
	//void draw();
	void bPassDownTrueUpdate();
	void doubleDownUpdate();
	void putRectAndPTs();

	otus() {}
	virtual ~otus() {}
};


class attackRect : public gameObject
{
private:
	float _existTime;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	//void setting(RECT)

	inline void setExistTime(float time) { _existTime = time; }

	attackRect() {}
	virtual ~attackRect() {}
};

//==============  »óÅÂ °´Ã¼  =====================
class otusState
{
public:
	string _stateName;
	otus *_otus;
	image *_image;
	PTINT _frame;
	float _time1;
	int _count1;
	//-------------------------------
	virtual ~otusState() {}

	virtual void init(otus *otus) {}
	virtual void enter(string pastStateName) {}
	virtual void update(otus &otus) {}
	virtual void render(otus &otus) {}
};
//-------------------------------------
class otusAir : public otusState
{
public:
	virtual void init(otus *otus);
	virtual void enter(string pastStateName);
	virtual void update(otus &otus);
	virtual void render(otus &otus);
};

class otusFly : public otusState
{
public:
	virtual void init(otus *otus);
	virtual void enter(string pastStateName);
	virtual void update(otus &otus);
	virtual void render(otus &otus);
};

class otusStand : public otusState
{
public:
	virtual void init(otus *otus);
	virtual void enter(string pastStateName);
	virtual void update(otus &otus);
	virtual void render(otus &otus);
};

class otusRun : public otusState
{
public:
	virtual void init(otus *otus);
	virtual void enter(string pastStateName);
	virtual void update(otus &otus);
	virtual void render(otus &otus);
};

class otusAttack : public otusState
{
public:
	virtual void init(otus *otus);
	virtual void enter(string pastStateName);
	virtual void update(otus &otus);
	virtual void render(otus &otus);
};

class otusGroundDash : public otusState
{
public:
	virtual void init(otus *otus);
	virtual void enter(string pastStateName);
	virtual void update(otus &otus);
	virtual void render(otus &otus);
};

class otusAirDash : public otusState
{
public:
	virtual void init(otus *otus);
	virtual void enter(string pastStateName);
	virtual void update(otus &otus);
	virtual void render(otus &otus);
};
