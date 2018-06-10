#pragma once
#include "GameObject.h"
#include "Macro.h"

class C_Component;

class C_Test : public C_GameObject
{
CreateBen(C_Test);
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVerBuffer;
	C_Component * m_pVertexComponent;
	C_Component * m_pTestLight;

private:
	float m_fAngle;

public:
	C_Test();
	virtual ~C_Test();

	//Implement Virtual Pure Function
public:
	virtual HRESULT		Init();
	virtual	INT			Update();
	virtual	VOID		Render();
	virtual	VOID		Release();

public:
	virtual HRESULT AddComponent();
};