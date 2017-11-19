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
	//���� ���� �����ϱ� - ��Ƽ��
	multimap<int, gameObject*> mRenderOrder;
	for (int i = 0; i < _vObject.size(); ++i)
	{
		auto obj = _vObject[i];
		mRenderOrder.insert(make_pair((int)obj->getLayer(), obj));
	}

	for (auto iter = mRenderOrder.begin(); iter != mRenderOrder.end(); ++iter)
	{
		//���忡�� ������ �� ���̾� ���̿� ���� ���ڷ� �־��ش�.
		//�̷��� �ϸ� ���忡���� �����ϸ� ��ü�� ���̰� ���� ����.

		//depthScale�� �⺻�� 1.0f
		float depthScale = 1.0f;

		//���̾ ���� depthScale ����
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
		case LAYER::TERRAIN3: case LAYER::TERRAIN2:
		case LAYER::TERRAIN1: case LAYER::PIXELDC:
		case LAYER::FRUIT:
		case LAYER::TEAM: case LAYER::NPC:
		case LAYER::OTUS: case LAYER::GRAB_LIGHT:
		case LAYER::ARM: case LAYER::GRAB_HEAVY:
		case LAYER::GRAB_TEAM: case LAYER::COINBOX:
		case LAYER::FRONT_TERRAIN:
			//��׵��� �⺻�� 1.0f
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

		//������
		switch ((LAYER::Enum)iter->first)
		{
		case LAYER::PIXELDC:
			//�ȼ��浹 �׸��� ����׿����� ����
			break;
		default:
			iter->second->render(depthScale);
			break;
		}
		
		//����׸��
		if (_mainDebugMode)
		{
			//���� ��Ʈ ǥ���ϸ� ���ž�� ����
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
