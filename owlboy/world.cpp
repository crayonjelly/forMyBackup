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
		//월드에서 렌더할 때 레이어 깊이에 따라서 인자로 넣어준다.
		//이렇게 하면 월드에서만 조정하면 전체의 깊이감 조정 가능.

		//depthScale의 기본값 1.0f
		float depthScale = 1.0f;

		switch ((LAYER::Enum)iter->first)
		{
		case LAYER::SKY3:
			depthScale = 0;
			break;
		case LAYER::SKY2:
			depthScale = 0;
			break;
		case LAYER::SKY1:
			depthScale = 0;
			break;
		case LAYER::BACK3:
			depthScale = 0.5f;
			break;
		case LAYER::BACK2:
			depthScale = 0.6f;
			break;
		case LAYER::BACK1:
			depthScale = 0.8f;
			break;
		case LAYER::TERRAIN: case LAYER::FRUIT:
		case LAYER::TEAM: case LAYER::NPC:
		case LAYER::OTUS: case LAYER::GRAB_LIGHT:
		case LAYER::ARM: case LAYER::GRAB_HEAVY:
		case LAYER::GRAB_TEAM: case LAYER::COINBOX:
		case LAYER::FRONT_TERRAIN:
			//얘네들은 기본값 1.0f
			break;
		case LAYER::FRONT1:
			depthScale = 1.2f;
			break;
		case LAYER::FRONT2:
			depthScale = 1.3f;
			break;
		case LAYER::FOG:
			depthScale = 0;
			break;
		case LAYER::MASK:
			depthScale = 0;
			break;
		case LAYER::UI:
			depthScale = 0;
			break;
		case LAYER::END:
			break;
		}

		iter->second->render(depthScale);
		iter->second->debugRender(depthScale);
	}
}


void world::addObject(gameObject* obj)
{
	_vObject.push_back(obj);
}
