#pragma once
#include "gameObject.h"


class layerObject : public gameObject
{
private:
	image* _layerImage;
	HDC _layerDC;

public:
	virtual HRESULT init(PTFLOAT pos);
	virtual void release();
	virtual void update();
	virtual void render(float depthScale = 1.0f);

	//°Ù¼Â
	inline auto getLayerDC() { return _layerDC; }
	inline auto getLayerImage() { return _layerImage; }

	inline void setLayerImage(image* img)
	{
		_layerImage = img;
		_layerDC = img->getMemDC();
	}

	layerObject() {}
	virtual ~layerObject() {}
};
