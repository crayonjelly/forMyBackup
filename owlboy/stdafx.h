#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <iostream>
#include <memory.h>
#include <tchar.h>

using namespace std;

#include <functional>

#include "mypoints.h"		//���� ���� PTINT, PTFLOAT
#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "imageManager.h"
#include "keyManager.h"
#include "lever.h"		//Ű�Ŵ��� ��Ŭ���. ���� ���ӽ����̽� �̳��ϰ� ���� ����Լ�.
#include "soundManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "sceneManager.h"
#include "utils.h"
#include "collision.h"
#include "txtData.h"
#include "database.h"
#include "keyAniManager.h"
#include "iniDataManager.h"
#include "cameraManager.h"
#include "stageManager.h"

using namespace OMICRON_UTIL;

//========================================
// ## ������ �� ## 17.07.03 ##
//========================================

#define WINNAME (LPTSTR)(TEXT("Final Portfolio <Owlboy> - Jericho"))
#define WINSTARTX 80
#define WINSTARTY 10
#define WINSIZEX 1200
#define WINSIZEY 800
#define WINCX (WINSIZEX / 2)
#define WINCY (WINSIZEY / 2)
#define WINSTYLE WS_CAPTION | WS_SYSMENU


//=============================================================
// ## 17.07.06 ## Singleton Define ##
//=============================================================

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define KEYANIMANAGER keyAniManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define DATABASE database::getSingleton()
#define INIDATA iniDataManager::getSingleton()
#define CAMERA cameraManager::getSingleton()
#define WORLD world::getSingleton()
#define STAGEMANAGER stageManager::getSingleton()

//ī�޶� ��ũ��
#define CAMX (CAMERA->getPos().x)
#define CAMY (CAMERA->getPos().y)
#define CAMCX (CAMERA->getPos().x + WINSIZEX / 2)
#define CAMCY (CAMERA->getPos().y + WINSIZEY / 2)

//=============================================================
// ## 17.07.06 ## Macro ##
//=============================================================

#define SAFE_DELETE(p) {if(p) {delete(p); (p) = NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) { delete[](p); (p) = NULL;}}

//=============================================================
// ## 17.07.06 ## �������� ##
//=============================================================

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;
extern BOOL _leftButtonDown;
extern BOOL _mainDebugMode;

#define ABSMOUSEX (CAMX + _ptMouse.x)
#define ABSMOUSEY (CAMY + _ptMouse.y)

//����ȭ ��ų �����
#include "worldNode.h"
#include "gameObject.h"
#include "world.h"
