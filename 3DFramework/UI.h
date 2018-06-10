#pragma once
#include "stdafx.h"
#include "Component.h"
#include "Macro.h"

class C_UI : public C_Component
{
CreateBen(C_UI);
private:
	D3DXVECTOR3 m_vecPos;

public:
	C_UI();
	virtual ~C_UI();

public:
	virtual C_Component * GetCloneComponent();

	virtual HRESULT Init();
	virtual void Update();
	virtual void Release();
};