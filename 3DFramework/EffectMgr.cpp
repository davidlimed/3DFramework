#include "stdafx.h"
#include "EffectMgr.h"

ImplementSingleton(C_EffectMgr)

C_EffectMgr::C_EffectMgr()
{
}

C_EffectMgr::~C_EffectMgr()
{
	Release();
}
