#include "stdafx.h"
#include "GameObject.h"

C_GameObject::C_GameObject():
	m_fSpeed(0.f)
{
	ZeroMemory(m_vPos, sizeof(D3DXVECTOR3));
	ZeroMemory(m_vDir, sizeof(D3DXVECTOR3));
	ZeroMemory(m_vLook, sizeof(D3DXVECTOR3));

	ZeroMemory(m_matWorld, sizeof(D3DXMATRIX));
}

C_GameObject::~C_GameObject(){}

HRESULT C_GameObject::Awake()
{
	return S_OK;
}

INT C_GameObject::LastUpdate()
{
	return 0;
}

INT C_GameObject::LastRender()
{
	return 0;
}
