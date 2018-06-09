#include "stdafx.h"
#include "Player.h"

C_Player::C_Player()
{
	ZeroMemory(m_vPos, sizeof(D3DXVECTOR3));
	ZeroMemory(m_vDir, sizeof(D3DXVECTOR3));
	ZeroMemory(m_vLook, sizeof(D3DXVECTOR3));

	ZeroMemory(m_matWorld, sizeof(D3DXMATRIX));
}

C_Player::~C_Player()
{
}

HRESULT C_Player::Init()
{
	return S_OK;
}

INT C_Player::Update()
{
	return 0;
}

VOID C_Player::Render()
{
	return VOID();
}

VOID C_Player::Release()
{
	return VOID();
}
