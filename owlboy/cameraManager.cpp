#include "stdafx.h"
#include "cameraManager.h"


HRESULT cameraManager::init()
{
	_pos.x = 0;
	_pos.y = 0;
	_target = NULL;

	return S_OK;
}
void cameraManager::release()
{

}

void cameraManager::moveCamera(int x, int y)
{
	_pos.x += x;
	_pos.y += y;
}
void cameraManager::moveCamera(PTINT pt)
{
	_pos.x += pt.x;
	_pos.y += pt.y;
}
void cameraManager::putCameraCenterToTarget()
{
	if (_target)
	{
		_pos.x = _target->getPos().x - WINSIZEX / 2;
		_pos.y = _target->getPos().y - WINSIZEY / 2;
	}
}
