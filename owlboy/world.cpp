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
	//렌더 순서 정렬하기 - 멀티맵
	multimap<int, gameObject*> mRenderOrder;
	for (int i = 0; i < _vObject.size(); ++i)
	{
		auto obj = _vObject[i];
		mRenderOrder.insert(make_pair((int)obj->getLayer(), obj));
	}
	for (auto iter = mRenderOrder.begin(); iter != mRenderOrder.end(); ++iter)
	{
		iter->second->render();
	}
}


void world::addObject(gameObject* obj)
{
	_vObject.push_back(obj);
}
