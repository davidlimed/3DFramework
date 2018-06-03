#pragma once
#include "stdafx.h"
#include "Macro.h"

class C_Device
{
DeclareSingleton(C_Device)

private:
	LPDIRECT3D9				m_p3D;
	LPDIRECT3DDEVICE9		m_pDevice;
	LPD3DXSPRITE			m_pSprite;
	LPD3DXFONT				m_pFont;
	/////////////////////////////////////////////
	D3DXFONT_DESC*			m_tFontInfo;

public:
	HRESULT Init();
	VOID	SetParameters(D3DPRESENT_PARAMETERS d3dpp);
	VOID	SetFont(int nHeight = 10, int nWidth = 10, UINT uWeight = 400);
	
public:
	const LPDIRECT3DDEVICE9	GetDeivce();
	const LPD3DXSPRITE		GetSprite();
	const LPD3DXFONT		GetFont();
};
