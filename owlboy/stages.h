#pragma once


class stage
{
protected:


public:
	string _stageName;
	image *_mapBuffer;
	image *_pixelBuffer;
	HDC _mapDC;
	HDC _pixelDC;
	//-------------------------------
	stage() {}
	virtual ~stage() {}

	virtual void init() {}
	virtual void release() {}
	virtual void enter(string pastStage = "") {}
	virtual void exit() {}

	virtual void drawMap() {}
	virtual void createObjects() {}

	void mapPixelClear();

	//¼Â
	void setDCs();
};
//-----------------------------------
class vellie : public stage
{
	virtual void init();
	virtual void enter(string pastStage = "");
	virtual void drawMap();
	virtual void createObjects();
};
class otusHouse : public stage
{
	virtual void init();
	virtual void enter(string pastStage = "");
	virtual void drawMap();
	virtual void createObjects();
};
class dungeon : public stage
{
	virtual void init();
	virtual void enter(string pastStage = "");
	virtual void drawMap();
	virtual void createObjects();
};
