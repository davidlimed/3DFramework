#pragma once
#include "Scene.h"
#include "Macro.h"

class C_Stage1 : public C_Scene
{
CreateBen(C_Stage1)
public:
	C_Stage1();
	virtual ~C_Stage1();

private:
	virtual HRESULT Init();
	virtual VOID Update();
	virtual VOID LastUpdate();
	virtual VOID Render();
	virtual VOID LastRender();
};