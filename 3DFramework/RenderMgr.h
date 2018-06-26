#pragma once
#include "Macro.h"

class C_RenderMgr
{
DeclareSingleton(C_RenderMgr)
private:
	C_RenderMgr();
	~C_RenderMgr();

public:
	enum E_RENDER_ID {eDefault};

public:
	void SetLight(bool bIsAble);
	void SetZBuffer(bool bIsAble);
	void SetAmbient(DWORD dwBrightness);
	void Rendering(D3DXMATRIX & matWorld, LPDIRECT3DVERTEXBUFFER9 VertexBuffer, UINT nStride, DWORD Flag, D3DPRIMITIVETYPE eType, UINT nPrimitiveCount);
	void MeshRender();
};