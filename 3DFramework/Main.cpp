#include "stdafx.h"
#include "Main.h"
#include "Define.h"
#include "Device.h"


C_Main::C_Main(){}

C_Main::~C_Main(){}

HRESULT C_Main::Awake()
{
	if (FAILED(C_Device::GetInstance()->Init()))
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
	C_Device::GetInstance()->GetDeivce()->Clear(0, 0, 0, D3DCOLOR_ARGB(255, 0, 0, 255), 0, 0);
	C_Device::GetInstance()->GetDeivce()->BeginScene();
	

	return;
}

VOID C_Main::LastRender()
{

	C_Device::GetInstance()->GetDeivce()->EndScene();
	C_Device::GetInstance()->GetDeivce()->Present(0, 0, 0, 0);

	return;
}

VOID C_Main::Release()
{
	return;
}
