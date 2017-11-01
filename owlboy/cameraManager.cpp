#include "stdafx.h"
#include "cameraManager.h"


HRESULT cameraManager::init()
{
	_pos.x = 0;
	_pos.y = 0;
	_focus = NULL;

	return S_OK;
}
void cameraManager::release()
{

}
void cameraManager::update()
{
	if (_focus)
	{
		_pos.x = _focus->x - WINSIZEX / 2;
		_pos.y = _focus->y - WINSIZEY / 2;
	}
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
