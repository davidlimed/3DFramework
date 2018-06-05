#pragma once
#include "stdafx.h"
#include "Macro.h"

class C_MainCamera
{
CreateBen(C_MainCamera)
private:
	D3DXMATRIX m_matView;
	D3DXVECTOR3 m_vecPos;
	D3DXVECTOR3 m_vecLook;
	D3DXVECTOR3 m_vecAt;

private:
	D3DXMATRIX m_matProj;

private:
	UINT	m_unInterval;

public:
	C_MainCamera();
	~C_MainCamera();

public:
	void Init();
	void SetInterval(UINT Interval);
	void Release();
};