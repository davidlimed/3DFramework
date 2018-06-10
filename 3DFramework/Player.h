#pragma once
#include "GameObject.h"
#include "Macro.h"

class C_Player : public C_GameObject
{
CreateBen(C_Player);
private:
	map<wstring, C_Component*>::iterator itor;

public:
	C_Player();
	virtual ~C_Player();
	
//Implement Virtual Pure Function
public:
	virtual HRESULT		Init();
	virtual	INT			Update();
	virtual	VOID		Render();
	virtual	VOID		Release();

public:
	virtual HRESULT AddComponent();
};