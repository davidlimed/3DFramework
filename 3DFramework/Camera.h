#pragma once
#include "stdafx.h"
#include "Define.h"

class C_Camera
{
private:
public:
	C_Camera();
	~C_Camera();

public:
	virtual HRESULT Init();
	virtual void Update();
	virtual void Release();
};