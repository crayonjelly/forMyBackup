#include "stdafx.h"
#include "world.h"


HRESULT world::init()
{
	_pg = NULL;
	_otus = NULL;
	_mainTime = 0.0f;

	return S_OK;
}
void world::release()
{

}
void world::update()
{
	_mainTime += TIMEMANAGER->getElapsedTime();

	for (int i = 0; i < _vObject.size(); ++i)
	{
		auto obj = _vObject[i];

		if (!obj->getBLive())
		{
			obj->release();
			delete obj;
			obj->setBLive(false);
			_vObject.erase(_vObject.begin() + i--);
			continue;
		}
		obj->update();
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

		//레이어에 따라 depthScale 설정
		switch ((LAYER::Enum)iter->first)
		{
		case LAYER::SKY3:
		case LAYER::SKY2:
		case LAYER::SKY1:
			//얘들도 걍 1로. 렌더함수 depthScale값 안쓰고 그냥 ui 처럼.
			break;
		case LAYER::BACK3:
			depthScale = 0.4f;
			break;
		case LAYER::BACK2:
			depthScale = 0.6f;
			break;
		case LAYER::BACK1:
			depthScale = 0.8f;
			break;
		case LAYER::TERRAIN3: case LAYER::TERRAIN2:
		case LAYER::TERRAIN1: case LAYER::PIXELDC:
		case LAYER::FRUIT:
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

		//렌더링
		switch ((LAYER::Enum)iter->first)
		{
		case LAYER::PIXELDC:
			//픽셀충돌 그린건 디버그에서만 보자
			break;
		default:
			iter->second->render(depthScale);
			break;
		}
		
		//디버그모드
		if (_mainDebugMode)
		{
			//구름 렉트 표시하면 정신없어서 지움
			switch ((LAYER::Enum)iter->first)
			{
			case LAYER::BACK3:
			case LAYER::BACK2:
			case LAYER::BACK1:
				break;
			case LAYER::PIXELDC:
				iter->second->render(depthScale);
				break;
			default:
				iter->second->debugRender(depthScale);
				break;
			}

			//_vObject 크기 표시
			char str[64];
			sprintf_s(str, "world: %d", _vObject.size());
			TextOut(_pg->getMemDC(), WINSIZEX - 100, 2, str, strlen(str));

			//마우스 절대좌표 표시
			auto oldMode = SetBkMode(_pg->getMemDC(), OPAQUE);
			sprintf_s(str, "(%d, %d)", ABSMOUSEX, ABSMOUSEY);
			TextOut(_pg->getMemDC(), _ptMouse.x + 13, _ptMouse.y, str, strlen(str));
			SetBkMode(_pg->getMemDC(), oldMode);
		}
	}
}


void world::addObject(gameObject* obj)
{
	_vObject.push_back(obj);
}

vector<gameObject*> world::findByKind(OBJKIND::Enum kind)
{
	vector<gameObject*> result;
	for (int i = 0; i < _vObject.size(); ++i)
	{
		if (_vObject[i]->getKind() == kind)
		{
			result.push_back(_vObject[i]);
		}
	}

	return result;
}

void world::allDieExceptBase()
{
	for (int i = 0; i < _vObject.size(); ++i)
	{
		auto obj = _vObject[i];
		
		auto kind = obj->getKind();
		if (kind == OBJKIND::OTUS ||
			kind == OBJKIND::MAPBUFFER ||
			kind == OBJKIND::PIXELBUFFER)
		{
			continue;
		}
		
		obj->setBLive(false);
	}
}
