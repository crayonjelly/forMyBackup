#pragma once


class stage
{
protected:


public:
	string _stageName;
	HDC _mapDC;
	HDC _pixelDC;
	//-------------------------------
	stage() {}
	virtual ~stage() {}

	virtual void init() {}
	virtual void release() {}
	virtual void enter() {}
	virtual void exit() {}

	virtual void drawMap() {}
	virtual void createObjects() {}

	//¼Â
	void setDCs();
};
//-----------------------------------
class vellie : public stage
{
	virtual void init();
	virtual void enter();
	virtual void drawMap();
	virtual void createObjects();
};
class otusHouse : public stage
{

};
