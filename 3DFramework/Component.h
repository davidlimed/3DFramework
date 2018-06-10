#pragma once
#include "Macro.h"

//Super Class
class C_Component
{
protected:
	UINT m_uRefCnt;

public:
	C_Component();
	virtual ~C_Component();
	
public:
	virtual HRESULT Init() PURE;
	virtual void Update() PURE;
	virtual void Release() PURE;

protected:
	virtual C_Component * GetCloneComponent();
	void AddRefCnt();
};