#pragma once
#include "gameNode.h"

struct tagMessage
{
	string text;
	int dataInt;
	float dataFloat;
	string dataString;
	gameObject *dataTarget;

	tagMessage() : text(""), dataInt(0), dataFloat(0.0f),
		dataString(""), dataTarget(NULL) {}
	tagMessage(
		string text,
		int dataInt = 0,
		float dataFloat = 0.0f,
		string dataString = "",
		gameObject *dataTarget = NULL) :

		text(text),
		dataInt(dataInt),
		dataFloat(dataFloat),
		dataString(dataString),
		dataTarget(dataTarget) {}
};

class gameObject : public gameNode
{
protected:
	bool _bLive;
	PTFLOAT _pos;
	RECT _rc;
	PTFLOAT _speed;

	image* _image;
	string _imageKey;
	PTINT _imageSize;
	PTINT _frame;

	OBJKIND::Enum _kind;
	LAYER::Enum _layer;

	vector<tagMessage> _vMessage;
	map<string, function<void(tagMessage)>> _mCallback;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	virtual void debugRender(float depthScale = 1.0f);

	void putRectCenterToPos();
	void putRectUponPos();
	void putPosCenterToRect();
	virtual void changeImage(string imageKey);
	void rcResetByImage();
	void sendMessage(tagMessage msg);

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
	inline bool getBLive() { return _bLive; }
	inline PTFLOAT getPos() { return _pos; }
	inline RECT getRect() { return _rc; }
	inline image* getImage() { return _image; }
	inline string getImageKey() { return _imageKey; }
	inline PTINT getImageSize() { return _imageSize; }
	inline PTINT getFrame() { return _frame; }
	inline auto getLayer() { return _layer; }
	inline auto getKind() { return _kind; }

	//설정자
	inline void setBLive(bool live) { _bLive = live; }
	inline void setPos(PTFLOAT pos) { _pos = pos; }
	inline void setRect(RECT rc) { _rc = rc; }
	inline void setImage(image* image) { _image = image; }
	inline void setImageKey(string imageKey) { _imageKey = imageKey; }
	inline void setImageSize(PTINT imageSize) { _imageSize = imageSize; }
	inline void setFrame(PTINT frame) { _frame = frame; }
	inline void setLayer(LAYER::Enum layerEnum) { _layer = layerEnum; }
	inline void setKind(OBJKIND::Enum kind) { _kind = kind; }

	gameObject() {}
	virtual ~gameObject() {}
};
