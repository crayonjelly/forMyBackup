#include "stdafx.h"
#include "world.h"


HRESULT world::init()
{


	return S_OK;
}
void world::release()
{

}
void world::update()
{
	for (int i = 0; i < _vObject.size(); ++i)
	{
		_vObject[i]->update();
	}
}
void world::render()
{
	for (int i = 0; i < _vObject.size(); ++i)
	{
		_vObject[i]->render();
	}
}


void world::addObject(gameObject* obj)
{
	_vObject.push_back(obj);
}
