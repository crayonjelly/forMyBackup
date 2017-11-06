#pragma once
#include "gameNode.h"


class gameObject : public gameNode
{
protected:
	PTFLOAT _pos;
	RECT _rc;
	PTFLOAT _speed;

	image* _image;
	string _imageKey;
	PTINT _imageSize;
	PTINT _frame;

	OBJKIND::Enum _kind;
	LAYER::Enum _layer;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	virtual void debugRender(float depthScale = 1.0f);

	void putRectCenterToPos()
	{
		int width = _rc.right - _rc.left;
		int height = _rc.bottom - _rc.top;

		_rc.left = _pos.x - width / 2;
		_rc.right = _rc.left + width;
		_rc.top = _pos.y - height / 2;
		_rc.bottom = _rc.top + height;
	}
	void putPosCenterToRect()
	{
		_pos.x = _rc.left + (_rc.right - _rc.left) / 2;
		_pos.y = _rc.top + (_rc.bottom - _rc.top) / 2;
	}
	void changeImage(string imageKey);
	void rcResetByImage();

	//inline 함수
	inline void movePos(PTFLOAT dPos)
	{
		_pos += dPos;
	}
	inline void movePos(float x, float y)
	{
		_pos.x += x;
		_pos.y += y;
	}

	//접근자
	inline PTFLOAT getPos() { return _pos; }
	inline RECT getRect() { return _rc; }
	inline image* getImage() { return _image; }
	inline string getImageKey() { return _imageKey; }
	inline PTINT getImageSize() { return _imageSize; }
	inline PTINT getFrame() { return _frame; }
	inline auto getLayer() { return _layer; }

	//설정자
	inline void setPos(PTFLOAT pos) { _pos = pos; }
	inline void setRect(RECT rc) { _rc = rc; }
	inline void setImage(image* image) { _image = image; }
	inline void setImageKey(string imageKey) { _imageKey = imageKey; }
	inline void setImageSize(PTINT imageSize) { _imageSize = imageSize; }
	inline void setFrame(PTINT frame) { _frame = frame; }
	inline void setLayer(LAYER::Enum layerEnum) { _layer = layerEnum; }

	gameObject() {}
	virtual ~gameObject() {}
};
