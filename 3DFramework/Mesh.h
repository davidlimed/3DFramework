#pragma once
#include "stdafx.h"
#include "Macro.h"
#include "Component.h"

class C_Mesh
{
CreateBen(C_Mesh)
public:
	C_Mesh();
	virtual ~C_Mesh();

public:
	virtual HRESULT Init();
	virtual void Update();
	virtual void Release();


};