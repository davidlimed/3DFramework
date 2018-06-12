#include "stdafx.h"
#include "ResourceMgr.h"

ImplementSingleton(C_ResourceMgr)

C_ResourceMgr::C_ResourceMgr()
{
}

C_ResourceMgr::~C_ResourceMgr()
{
	Release();
}
