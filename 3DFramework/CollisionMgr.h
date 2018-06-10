#pragma once
#include "stdafx.h"
#include "Macro.h"

class C_CollisionMgr
{
DeclareSingleton(C_CollisionMgr)
private:
	C_CollisionMgr() {}

public:
	HRESULT Init();
	void Update();
};