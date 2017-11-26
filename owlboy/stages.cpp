#include "stdafx.h"
#include "stages.h"


void stage::setDCs()
{
	_mapBuffer = IMAGEMANAGER->findImage("mapBuffer");
	_pixelBuffer = IMAGEMANAGER->findImage("pixelBuffer");
	_mapDC = _mapBuffer->getMemDC();
	_pixelDC = _pixelBuffer->getMemDC();
}
void stage::mapPixelClear()
{
	//¸Ê¹öÆÛ, ÇÈ¼¿¹öÆÛ ¸¶Á¨Å¸·Î ½Ï ¹Ð±â
	HBRUSH oldBrush = (HBRUSH)SelectObject(_mapDC, CreateSolidBrush(RGB(255, 0, 255)));
	RectangleMake(_mapDC, -10, -10, _mapBuffer->getWidth() + 10, _mapBuffer->getHeight() + 10);
	DeleteObject(SelectObject(_mapDC, oldBrush));

	//ÇÈ¼¿¹öÆÛ´Â Å×µÎ¸® »¡°²°Ô ÇØ¼­ ¸·ÀÚ
	oldBrush = (HBRUSH)SelectObject(_pixelDC, CreateSolidBrush(RGB(255, 0, 255)));
	HPEN oldPen = (HPEN)SelectObject(_pixelDC, CreatePen(PS_SOLID, 32, RGB(255, 0, 0)));
	RectangleMake(_pixelDC, 0, 0, _pixelBuffer->getWidth(), _pixelBuffer->getHeight());
	DeleteObject(SelectObject(_pixelDC, oldPen));
	DeleteObject(SelectObject(_pixelDC, oldBrush));
}
