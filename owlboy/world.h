#pragma once
#include "singletonBase.h"


class world : public singletonBase<world>
{
private:
	vector<gameObject*> _vObject;
	gameNode *_pg;
	gameObject *_otus;
	float _mainTime;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void addObject(gameObject* obj);
	vector<gameObject*> findByKind(OBJKIND::Enum kind);
	void allDieExceptBase();

	//°Ù¼Â
	inline gameObject* getOtus() { return _otus; }
	inline auto getAllObjects() { return _vObject; }
	inline auto getMainTime() { return _mainTime; }

	inline void setPG(gameNode *pg) { _pg = pg; }
	inline void setOtus(gameObject *otus) { _otus = otus; }
	inline void setMainTime(float time) { _mainTime = time; }

	world() {}
	~world() {}
};
