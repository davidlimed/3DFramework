#pragma once
#include "Scene.h"

class C_Logo : public C_Scene
{
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