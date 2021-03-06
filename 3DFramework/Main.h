#pragma once

#include "stdafx.h"
#include "Macro.h"

class C_MainCamera;
class C_Test;
class C_Player;

class C_Main
{
CreateBen(C_Main)

private:
	C_MainCamera *		m_pCameraInstance;
	LPDIRECT3DTEXTURE9	m_pTexture;

private:
	float m_fAngle;

private:
	C_Test * m_pTest;
	C_Player * m_pPlayer;

public:
	C_Main();
	~C_Main();

public:
	HRESULT Awake();
	HRESULT Init();
	
	VOID	Update();
	VOID	LastUpdate();
	
	VOID	Render();
	VOID	LastRender();

public:
	VOID	Release();

};