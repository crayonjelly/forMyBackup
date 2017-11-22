#pragma once
#include "gameObject.h"


class door : public gameObject
{
private:
	gameObject *_target;
	string _message;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	//virtual void render(float depthScale = 1.0f);

	//°Ù¼Â
	inline auto getTarget() { return _target; }
	inline void setTarget(gameObject *target) { _target = target; }

	door() {}
	virtual ~door() {}
};
