#pragma once
#include "gameObject.h"


class gawk : public gameObject
{
private:
#define GAWKSPEED 5

	friend class gawkState;
	friend class gawkSleep;
	friend class gawkWake;
	friend class gawkFly;
	friend class gawkStun;
	friend class gawkDie;
	gawkSleep	*_gawkSleep;
	gawkWake	*_gawkWake;
	gawkFly		*_gawkFly;
	gawkStun	*_gawkStun;
	gawkDie		*_gawkDie;
	//---------------------------------------------------
	bool _bLeft;
	bool _bLeftPast;

	gawkState *_state;
	gameObject *_target;

	PTFLOAT _initialPos;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);


	void changeState(gawkState *state);


	auto getTarget() { return _target; }
	void setTarget(gameObject *target) { _target = target; }

	gawk() {}
	virtual ~gawk() {}
};


//==============  »óÅÂ °´Ã¼  =====================
class gawkState
{
public:
	string _stateName;
	gawk *_gawk;
	image *_image;
	PTINT _frame;
	float _time1;
	int _count1;
	//-------------------------------
	virtual ~gawkState() {}

	virtual void init(gawk *_gawk) {}
	virtual void enter(string pastStateName) {}
	virtual void update() {}
	virtual void render(float depthScale = 1.0f) {}
};
//-------------------------------------
class gawkSleep : public gawkState
{
public:
	virtual void init(gawk *gawk);
	virtual void enter(string pastStateName);
	virtual void update();
	virtual void render(float depthScale = 1.0f);
};
//-------------------------------------
class gawkWake : public gawkState
{
public:
	virtual void init(gawk *gawk);
	virtual void enter(string pastStateName);
	virtual void update();
	virtual void render(float depthScale = 1.0f);
};
//-------------------------------------
class gawkFly : public gawkState
{
public:
	virtual void init(gawk *gawk);
	virtual void enter(string pastStateName);
	virtual void update();
	virtual void render(float depthScale = 1.0f);
};
//-------------------------------------
class gawkStun : public gawkState
{
public:
	virtual void init(gawk *gawk);
	virtual void enter(string pastStateName);
	virtual void update();
	virtual void render(float depthScale = 1.0f);
};
//-------------------------------------
class gawkDie : public gawkState
{
public:
	virtual void init(gawk *gawk);
	virtual void enter(string pastStateName);
	virtual void update();
	virtual void render(float depthScale = 1.0f);
};
