#include "stdafx.h"
#include "door.h"


HRESULT door::init(PTFLOAT pos)
{
	gameObject::init(pos);

	//오투스 타겟으로 잡기
	_target = NULL;
	//auto vOtus = WORLD->findByKind(OBJKIND::OTUS);
	//if (vOtus.size() >= 1)
	//{
	//	_target = vOtus[0];
	//}
	_target = WORLD->getOtus();

	_message = tagMessage("door");

	return S_OK;
}
void door::release()
{
	gameObject::release();
}
void door::update()
{
	gameObject::update();


	POINT pt = { _target->getPos().x, _target->getPos().y };
	if (PtInRect(&_rc, pt))
	{
		_target->sendMessage(_message);
	}
}
