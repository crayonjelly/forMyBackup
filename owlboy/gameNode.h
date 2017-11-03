#pragma once
#include "image.h"

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);
static image* _mapBuffer = IMAGEMANAGER->addImage("mapBuffer", 10000, 10000);
static image* _pixelBuffer = IMAGEMANAGER->addImage("pixelBuffer", 10000, 10000);


class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;

public:
	virtual HRESULT init(void);
	virtual HRESULT init(bool managerInit);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	image* getBackBuffer(void) { return _backBuffer; }

	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getMapDC() { return _mapBuffer->getMemDC(); }
	HDC getPixelDC() { return _pixelBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND , UINT, WPARAM, LPARAM);

	gameNode() {}
	virtual ~gameNode() {}
};
