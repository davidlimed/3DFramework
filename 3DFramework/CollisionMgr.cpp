#include "stdafx.h"
#include "CollisionMgr.h"

ImplementSingleton(C_CollisionMgr)

C_CollisionMgr::~C_CollisionMgr()
{
	Release();
}

HRESULT C_CollisionMgr::Init()
{
	return S_OK;
}

void C_CollisionMgr::Update()
{
}
