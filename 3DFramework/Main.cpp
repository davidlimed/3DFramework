#include "stdafx.h"
#include "Main.h"
#include "Define.h"
#include "Macro.h"
#include "Device.h"
#include "Vertex.h"
#include "VertexInfo.h"
#include "FlagDefine.h"

C_Main::C_Main():
	m_pVertexBuffer(nullptr)
{
}

C_Main::~C_Main(){}

HRESULT C_Main::Awake()
{
	HRESULT hr = C_Device::GetInstance()->Init(g_hWnd);

	if (FAILED(hr))
	{
		MessageBox(NULL, L"Device Init Fail", L"System Massge", MB_OK);
		return E_FAIL;
	}

	S_VertexColor verColor[] =
	{
		{ 150.f, 50.f, 0.5f, 1.f, 0xffff0000 },
		{ 250.f, 250.f, 0.5f, 1.f, 0xff00ff00 },
		{ 50.f, 250.f, 0.5f, 1.f, 0xff0000ff }

	};

	if (FAILED(C_Device::GetInstance()->GetDevice()->CreateVertexBuffer(
		3 * sizeof(S_VertexColor),
		NULL,
		FVF_VER_RHW_COLOR,
		D3DPOOL_DEFAULT,
		&m_pVertexBuffer,
		NULL)))
	{
		return E_FAIL;
	}

	void * pVertices;

	if (FAILED(m_pVertexBuffer->Lock(NULL, sizeof(verColor), &pVertices, NULL)))
		return E_FAIL;

	memcpy(pVertices, verColor, sizeof(verColor));

	m_pVertexBuffer->Unlock();

	return S_OK;
}

HRESULT C_Main::Init()
{

	return S_OK;
}

VOID C_Main::Update()
{

	return;
}

VOID C_Main::LastUpdate()
{
	return;
}

VOID C_Main::Render()
{
	GraphicDevice(C_Device)->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, D3DCOLOR_ARGB(255, 0, 0, 255), 1.f, 0);

	if (SUCCEEDED(GraphicDevice(C_Device)->BeginScene()))
	{
		//render
		GraphicDevice(C_Device)->SetStreamSource(NULL, m_pVertexBuffer, 0, sizeof(S_VertexColor));
		GraphicDevice(C_Device)->SetFVF(FVF_VER_RHW_COLOR);
		GraphicDevice(C_Device)->DrawPrimitive(D3DPRIMITIVETYPE::D3DPT_TRIANGLELIST, 0, 1);


		GraphicDevice(C_Device)->EndScene();
	}

	GraphicDevice(C_Device)->Present(0, 0, 0, 0);
	

	return;
}

VOID C_Main::LastRender()
{

	return;
}

VOID C_Main::Release()
{
	return;
}
