#include "stdafx.h"
#include "keyManager.h"


HRESULT keyManager::init()
{
	//처음엔 모든 키를 눌려있지 않은 상태로 초기화
	_keyCurrent.reset();
	_keyPast.reset();

	return S_OK;
}
void keyManager::release()
{

}
void keyManager::update()    //gameNode의 update에 추가
{
	//과거키를 현재키로 갱신해준다
	_keyPast = _keyCurrent;
}


bool keyManager::isOnceKeyDown(int key)
{
	//해당 키가 눌린 상태
	if (GetAsyncKeyState(key) & 0x8000)
	{
		//현재키를 눌린 상태로 바꾸고
		_keyCurrent.set(key, true);
		//그 키가 눌려있지 않았다면 return true
		if (!_keyPast[key]) return true;
	}
	//해당 키가 눌리지 않은 상태
	else _keyCurrent.set(key, false);   //현재키를 눌리지 않은 상태로 바꿈

	return false;
}

bool keyManager::isOnceKeyUp(int key)
{
	//해당 키가 눌린 상태					현재키를 눌린 상태로 바꿈
	if (GetAsyncKeyState(key) & 0x8000) _keyCurrent.set(key, true);
	//해당 키가 눌리지 않은 상태
	else
	{
		//현재키를 눌리지 않은 상태로 바꾸고
		_keyCurrent.set(key, false);
		//그 키가 눌려있었다면 return true
		if (_keyPast[key]) return true;
	}

	return false;
}

bool keyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		_keyCurrent.set(key, true);
		return true;
	}

	_keyCurrent.set(key, false);
	return false;
}

bool keyManager::isToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001) return true;

	return false;
}
