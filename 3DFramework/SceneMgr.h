#pragma once
#include "Macro.h"


class C_SceneMgr
{
DeclareSingleton(C_SceneMgr)
public:
	enum E_SCENEID {eLogo, eLobby};

private:
	C_SceneMgr();
public:
	~C_SceneMgr();
	
public:
	HRESULT Init();
	
};