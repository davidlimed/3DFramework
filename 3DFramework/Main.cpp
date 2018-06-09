#include "stdafx.h"
#include "Main.h"
#include "Define.h"
#include "Macro.h"
#include "Device.h"
#include "Vertex.h"
#include "VertexInfo.h"
#include "FlagDefine.h"
#include "MainCamera.h"

C_Main::C_Main():
	m_pVertexBuffer(nullptr),
	m_pCameraInstance(nullptr)
{
}

C_Main::~C_Main(){}

HRESULT C_Main::Awake()
{
	HRESULT hr = C_Device::GetInstance()->Init(g_hWnd);

	GraphicDevice(C_Device)->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	GraphicDevice(C_Device)->SetRenderState(D3DRS_LIGHTING, false);

	CreateObject(m_pCameraInstance, C_MainCamera);

	//Create Device
	if (FAILED(hr))
	{
		MessageBox(NULL, L"Device Init Fail", L"System Massge", MB_OK);
		return E_FAIL;
	}

	C_Vertex * vt = new C_Vertex();
	
	vt->Init();
	m_pVertexBuffer = vt->GetVB();

	return S_OK;
}

HRESULT C_Main::Init()
{

	return S_OK;
}

VOID C_Main::Update()
{
	D3DXMATRIX matWorld = {};
	D3DXMATRIX matTrans = {};
	D3DXMATRIX matRot = {};

	m_fAngle += 0.1f;

	D3DXMatrixRotationY(&matRot, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&matTrans, 0.f, 0.f, 0.f);

	matWorld = matRot * matTrans;
	GraphicDevice(C_Device)->SetTransform(D3DTS_WORLD, &matWorld);

	m_pCameraInstance->Update();

	GraphicDevice(C_Device)->SetRenderState(D3DRENDERSTATETYPE::D3DRS_FILLMODE, D3DFILL_WIREFRAME);

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
		GraphicDevice(C_Device)->SetStreamSource(NULL, m_pVertexBuffer, 0, sizeof(S_VertexXYZ));
		GraphicDevice(C_Device)->SetFVF(FVF_VER_COLOR);
		GraphicDevice(C_Device)->DrawPrimitive(D3DPRIMITIVETYPE::D3DPT_TRIANGLESTRIP, 0, 1);

		GraphicDevice(C_Device)->EndScene();
	}

	GraphicDevice(C_Device)->Present(NULL, NULL, NULL, NULL);

	return;
}

VOID C_Main::LastRender()
{


	return;
}

VOID C_Main::Release()
{
	C_Device::GetInstance()->Release();
	return;
}
