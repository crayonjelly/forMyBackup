#include "stdafx.h"
#include "stages.h"


void stage::setDCs()
{
	_mapDC = IMAGEMANAGER->findImage("mapBuffer")->getMemDC();
	_pixelDC = IMAGEMANAGER->findImage("pixelBuffer")->getMemDC();
}
