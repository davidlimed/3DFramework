#include "stdafx.h"
#include "Main.h"
#include "Define.h"
#include "Macro.h"
#include "Device.h"
#include "Vertex.h"
#include "VertexInfo.h"
#include "FlagDefine.h"
#include "MainCamera.h"
#include "TimeMgr.h"
#include "Test.h"
#include "Player.h"

C_Main::C_Main():
	m_pVertexBuffer(nullptr),
	m_pCameraInstance(nullptr),
	m_pPlayer(nullptr)
{
}

C_Main::~C_Main()
{
	Release();
}

HRESULT C_Main::Awake()
{
	HRESULT hr = C_Device::GetInstance()->Init(g_hWnd);

	GraphicDevice(C_Device)->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	GraphicDevice(C_Device)->SetRenderState(D3DRS_ZENABLE, TRUE);
	GraphicDevice(C_Device)->SetRenderState(D3DRS_LIGHTING, false);

	CreateObject(m_pCameraInstance, C_MainCamera);
	CreateObject(m_pTest, C_Test);
	CreateObject(m_pPlayer, C_Player);

	//Create Device
	if (FAILED(hr))
	{
		MessageBox(NULL, L"Device Init Fail", L"System Massge", MB_OK);
		return E_FAIL;
	}

	C_TimeMgr::GetInstance()->InitTime();

	return S_OK;
}

HRESULT C_Main::Init()
{

	return S_OK;
}

VOID C_Main::Update()
{
	C_TimeMgr::GetInstance()->SetTime();

	//Obejct Update Begin
	m_pPlayer->Update();
	m_pTest->Update();

	//Object Update End

	m_pCameraInstance->Update();

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
		m_pPlayer->Render();
		m_pTest->Render();
	}


	return;
}

VOID C_Main::LastRender()
{

	GraphicDevice(C_Device)->EndScene();
	GraphicDevice(C_Device)->Present(NULL, NULL, NULL, NULL);
	return;
}

VOID C_Main::Release()
{


	C_Device::GetInstance()->Release();
	return;
}
