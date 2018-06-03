#include "stdafx.h"
#include "Main.h"
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
