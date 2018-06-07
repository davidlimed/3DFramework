#pragma once

#include "stdafx.h"
#include "Macro.h"

class C_MainCamera;

class C_Main
{
CreateBen(C_Main)

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVertexBuffer;
	C_MainCamera * m_pCameraInstance;

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