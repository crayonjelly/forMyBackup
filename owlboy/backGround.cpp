#include "stdafx.h"
#include "backGround.h"


HRESULT backGround::init(PTFLOAT pos)
{
	gameObject::init(pos);

	_layer = LAYER::SKY3;

	return S_OK;
}
void backGround::release()
{
	gameObject::release();
}
void backGround::update()
{
	gameObject::update();

	//_pos.x += 0.5f;
	//if (_pos.x > WINSIZEX + 200)
	//{
	//	_posx.
	//}
}
void backGround::render(float depthScale)
{
	//_image->render(getMemDC(),
	//	WINSIZEX / 2 + (_pos.x - CAMCX) * depthScale,
	//	WINSIZEY / 2 + (_pos.y - CAMCY) * depthScale);

	_image->render(getMemDC(), _pos.x, _pos.y);
}
