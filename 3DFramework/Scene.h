#pragma once
#include "stdafx.h"

class C_Scene
{
public:
	C_Scene() {}
	virtual ~C_Scene() {}

public:
	virtual HRESULT Init() PURE;
	virtual VOID Update() PURE;
	virtual VOID LastUpdate() PURE;
	virtual VOID Render() PURE;
	virtual VOID LastRender() PURE;
};