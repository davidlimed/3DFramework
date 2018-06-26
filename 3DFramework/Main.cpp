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
#include "GameObjectMgr.h"

C_Main::C_Main():
	m_pTexture(nullptr),
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

	Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	Device->SetRenderState(D3DRS_ZENABLE, TRUE);
	Device->SetRenderState(D3DRS_LIGHTING, false);

	////////////////////////////////////////////////////////////////////////
	CreateObject(m_pCameraInstance, C_MainCamera);
	GameObjMgr->Init();

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
	if (FAILED(D3DXCreateTextureFromFile(C_Device::GetInstance()->GetDevice(),
		L"../Texture/Tex.png",
		&m_pTexture)))
	{
		return E_FAIL;
	}

	return S_OK;
}

VOID C_Main::Update()
{
	C_TimeMgr::GetInstance()->SetTime();

	//Obejct Update Begin
	GameObjMgr->Update();

	//Object Update End

	m_pCameraInstance->Update();

	return;
}

VOID C_Main::LastUpdate()
{
	GameObjMgr->LastUpdate();

	return;
}

VOID C_Main::Render()
{
	Device->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, D3DCOLOR_ARGB(255, 0, 0, 255), 1.f, 0);

	if (SUCCEEDED(Device->BeginScene()))
	{
		//render
		GameObjMgr->Render();
	}


	return;
}

VOID C_Main::LastRender()
{
	GameObjMgr->LastRender();
	Device->EndScene();
	Device->Present(NULL, NULL, NULL, NULL);
	return;
}

VOID C_Main::Release()
{
	GameObjMgr->Release();

	C_Device::GetInstance()->Release();
	return;
}
