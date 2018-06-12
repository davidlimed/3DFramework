#pragma once
#include "stdafx.h"
#include "Macro.h"

class C_Light
{
CreateBen(C_Light)

private:
	D3DMATERIAL9	m_mtrl;
	D3DXVECTOR3		m_vecDir;
	D3DLIGHT9		m_light;
public:
	C_Light();
	virtual ~C_Light();

public:
	virtual HRESULT Init();
	virtual void Update();
	virtual void Release();

public:
	void SetMaterial(D3DMATERIAL9 & material);
	void SetLight(D3DLIGHTTYPE eType, float fDiffuse_r, float fDiffuse_g, float fDiffuse_b, D3DXVECTOR3 vecDir, float fRange);
};
