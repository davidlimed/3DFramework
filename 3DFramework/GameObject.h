#pragma once
#include "Device.h"
#include "Macro.h"

class C_GameObject
{
CreateBen(C_GameObject)
public:
	C_GameObject();
	virtual ~C_GameObject();

//@Pure Function
public:
	virtual HRESULT Init() PURE;
	virtual	INT Update() PURE;
	virtual	VOID Render() PURE;
	virtual	VOID Release() PURE;

//@Interface
public:
	virtual HRESULT Awake();
	virtual INT LastUpdate();
	virtual INT LastRender();
	
public:
	
};