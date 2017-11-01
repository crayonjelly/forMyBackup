#pragma once
#include "singletonBase.h"


class cameraManager : public singletonBase<cameraManager>
{
private:
	PTINT _pos;
	PTINT *_focus;

public:
	HRESULT init();
	void release();
	void update();

	void moveCamera(int x, int y);
	void moveCamera(PTINT pt);

	//������
	inline PTINT getPos() { return _pos; }
	inline PTINT* getFocus() { return _focus; }

	//������
	inline void setPos(PTINT pos) { _pos = pos; }
	inline void setFocus(PTINT *focus) { _focus = focus; }

	cameraManager() {}
	~cameraManager() {}
};
