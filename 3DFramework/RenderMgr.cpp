#include "stdafx.h"
#include "RenderMgr.h"
#include "Device.h"
#include "Macro.h"

ImplementSingleton(C_RenderMgr)

C_RenderMgr::C_RenderMgr(){}

C_RenderMgr::~C_RenderMgr()
{
	this->Release();
}

void C_RenderMgr::SetLight(bool bIsAble)
{
	Device->LightEnable(0, bIsAble);
	Device->SetRenderState(D3DRS_LIGHTING, bIsAble);
}

void C_RenderMgr::SetZBuffer(bool bIsAble)
{
	Device->SetRenderState(D3DRS_ZENABLE, bIsAble);
}

void C_RenderMgr::SetAmbient(DWORD dwBrightness)
{
	Device->SetRenderState(D3DRS_AMBIENT, dwBrightness);
}

void C_RenderMgr::Rendering(D3DXMATRIX & matWorld, LPDIRECT3DVERTEXBUFFER9 VertexBuffer, UINT nStride, DWORD Flag, D3DPRIMITIVETYPE eType, UINT nPrimitiveCount)
{
	Device->SetTransform(D3DTS_WORLD, &matWorld);
	Device->SetStreamSource(NULL, VertexBuffer, 0, nStride);
	Device->SetFVF(Flag);
	Device->DrawPrimitive(eType, 0, nPrimitiveCount);
}

void C_RenderMgr::MeshRender()
{
}
