#include "stdafx.h"
#include "Main.h"
#include "Define.h"
#include "Device.h"

C_Main::C_Main(){}

C_Main::~C_Main(){}

HRESULT C_Main::Awake()
{
	HRESULT hr = C_Device::GetInstance()->Init(g_hWnd);

	if (FAILED(hr))
	{
		MessageBox(NULL, L"Device Init Fail", L"System Massge", MB_OK);
		return E_FAIL;
	}

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
	C_Device::GetInstance()->GetDeivce()->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL , D3DCOLOR_ARGB(255, 0, 0, 255), 0, 0);
	C_Device::GetInstance()->GetDeivce()->BeginScene();

	C_Device::GetInstance()->GetDeivce()->EndScene();
	C_Device::GetInstance()->GetDeivce()->Present(0, 0, g_hWnd, 0);
	

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
