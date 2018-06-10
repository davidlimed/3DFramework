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

void C_RenderMgr::Rendering()
{

}

void C_RenderMgr::Rendering(LPDIRECT3DVERTEXBUFFER9 & VertexBuffer)
{

}

void C_RenderMgr::Rendering(D3DXMATRIX & matWorld, LPDIRECT3DVERTEXBUFFER9 VertexBuffer, UINT nStride, DWORD Flag, D3DPRIMITIVETYPE eType, UINT nPrimitiveCount)
{
	GraphicDevice(C_Device)->SetTransform(D3DTS_WORLD, &matWorld);
	GraphicDevice(C_Device)->SetStreamSource(NULL, VertexBuffer, 0, nStride);
	GraphicDevice(C_Device)->SetFVF(Flag);
	GraphicDevice(C_Device)->DrawPrimitive(eType, 0, nPrimitiveCount);
}
