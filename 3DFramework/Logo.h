#pragma once
#include "Scene.h"
#include "Macro.h"

class C_Logo : public C_Scene
{
CreateBen(C_Logo)

public:
	C_Logo();
	virtual ~C_Logo();

public:
	virtual HRESULT Init();
	virtual VOID Update();
	virtual VOID LastUpdate();
	virtual VOID Render();
	virtual VOID LastRender();

};