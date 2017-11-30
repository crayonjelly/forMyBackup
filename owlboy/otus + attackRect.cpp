#include "stdafx.h"
#include "otus.h"


HRESULT attackRect::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_existTime = 0.0f;

	return S_OK;
}
void attackRect::release()
{
	gameObject::release();
}
void attackRect::update()
{
	gameObject::update();

	if (_existTime > 0.0f)
	{
		_existTime -= TIMEMANAGER->getElapsedTime();
	}
	else
	{
		this->setBLive(false);
	}

	auto vObj = WORLD->getAllObjects();

	for (int i = 0; i < vObj.size(); ++i)
	{
		if (vObj[i] == this) continue;
		POINT pt = { vObj[i]->getPos().x, vObj[i]->getPos().y };
		if (PtInRect(&_rc, pt))
		{
			WORLD->getOtus()->sendMessage(tagMessage("otusAttack"));
			vObj[i]->sendMessage(tagMessage("otusAttack"));
			this->setBLive(false);
		}
	}
}
void attackRect::render(float depthScale)
{

}
