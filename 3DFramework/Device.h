#pragma once
#include "stdafx.h"
#include "Macro.h"

class C_Device
{
DeclareSingleton(C_Device)
private:
	C_Device();
	
public:
	~C_Device();

private:
	LPDIRECT3D9				m_p3D;
	LPDIRECT3DDEVICE9		m_pDevice;
	LPD3DXSPRITE			m_pSprite;
	LPD3DXFONT				m_pFont;

public:
	HRESULT Init(HWND hWnd);
	VOID	SetParameters(D3DPRESENT_PARAMETERS * d3dpp);
	
public:
	const LPDIRECT3DDEVICE9	GetDevice();
	const LPD3DXSPRITE		GetSprite();
	const LPD3DXFONT		GetFont();

public:
	void DestroyDevice();
};
