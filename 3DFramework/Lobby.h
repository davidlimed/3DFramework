#pragma once
#include "Scene.h"
#include "Macro.h"

class C_Lobby : public C_Scene
{
CreateBen(C_Lobby)
private:
	

public:
	C_Lobby();
	virtual ~C_Lobby();

public:
	virtual HRESULT Init();
	virtual VOID Update();
	virtual VOID LastUpdate();
	virtual VOID Render();
	virtual VOID LastRender();
};
