#pragma once
#include "stdafx.h"
#include "Component.h"
#include "Macro.h"

class C_TestLight : public C_Component
{
CreateBen(C_TestLight);

private:
	D3DMATERIAL9	m_mtrl;
	D3DXVECTOR3		m_vecDir;
	D3DLIGHT9		m_light;

public:
	C_TestLight();
	virtual ~C_TestLight();

public:
	virtual HRESULT Init();
	virtual void Update();
	virtual void Release();

};