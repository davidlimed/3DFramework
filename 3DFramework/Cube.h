#pragma once
#include "GameObject.h"

class C_Cube : public C_GameObject
{
CreateBen(C_Cube)
public:
	C_Cube();
	~C_Cube();

public:
	C_Cube(D3DXVECTOR3 vPos);

public:
	virtual HRESULT AddComponent();
	virtual HRESULT Init();
	virtual	INT Update();
	virtual	VOID Render();
	virtual	VOID Release();
};