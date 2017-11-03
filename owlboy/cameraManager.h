#pragma once
#include "singletonBase.h"

class gameObject;


class cameraManager : public singletonBase<cameraManager>
{
private:
	PTINT _pos;
	gameObject *_target;

public:
	HRESULT init();
	void release();

	void moveCamera(int x, int y);
	void moveCamera(PTINT pt);
	void putCameraCenterToTarget();

	//접근자
	inline PTINT getPos() { return _pos; }
	inline gameObject* getTarget() { return _target; }

	//설정자
	inline void setPos(PTINT pos) { _pos = pos; }
	inline void setTarget(gameObject *target) { _target = target; }

	cameraManager() {}
	~cameraManager() {}
};
