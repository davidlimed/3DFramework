#pragma once
#include "GameObject.h"
#include "Macro.h"

#define USING_MESH

class C_Component;

class C_Test : public C_GameObject
{
CreateBen(C_Test);
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVerBuffer;
	C_Component * m_pVertexComponent;
	C_Component * m_pTestLight;

private:
	LPD3DXMESH				m_pMesh;
	D3DMATERIAL9 *			m_pMeshMeterials;
	LPDIRECT3DTEXTURE9 *	m_pMeshTexture;
	LPDIRECT3DTEXTURE9		m_pTexture;
	DWORD					m_dwCount;

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