#include "stdafx.h"
#include "GameObject.h"

C_GameObject::C_GameObject(){}

C_GameObject::~C_GameObject(){}

HRESULT C_GameObject::Awake()
{
	return E_NOTIMPL;
}

INT C_GameObject::LastUpdate()
{
	return 0;
}

INT C_GameObject::LastRender()
{
	return 0;
}
