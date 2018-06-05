#include "stdafx.h"
#include "Device.h"
#include "Define.h"

ImplementSingleton(C_Device)

C_Device::C_Device() :
	m_p3D(nullptr),
	m_pDevice(nullptr),
	m_pSprite(nullptr),
	m_pFont(nullptr)
{
}

C_Device::~C_Device(){}

//HRESULT C_Device::Init()
//{
//	m_p3D = Direct3DCreate9(D3D_SDK_VERSION);
//
//	D3DCAPS9		DeviceCaps;
//	ZeroMemory(&DeviceCaps, sizeof(D3DCAPS9));
//
//	if (FAILED(m_p3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &DeviceCaps)))
//	{
//		MessageBox(NULL, L"장치 생성 실패", L"System Message", MB_OK);
//		return E_FAIL;
//	}
//
//	DWORD		vp;
//	if (DeviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
//		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
//
//	else
//		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
//
//	vp |= D3DCREATE_MULTITHREADED;
//
//	D3DPRESENT_PARAMETERS		d3dpp;
//	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
//	SetParameters(d3dpp);
//
//	if (FAILED(m_p3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, vp, &d3dpp, &m_pDevice)))
//	{
//		MessageBox(NULL, L"Create Device failed", L"System Message", MB_OK);
//		return E_FAIL;
//	}
//
//	if (FAILED(D3DXCreateSprite(m_pDevice, &m_pSprite)))
//	{
//		MessageBox(NULL, L"Create Sprite failed", L"System Message", MB_OK);
//		return E_FAIL;
//	}
//
//	D3DXFONT_DESC		tFontInfo;
//	ZeroMemory(&tFontInfo, sizeof(D3DXFONT_DESC));
//
//	tFontInfo.Height = 10;
//	tFontInfo.Width = 10;
//	tFontInfo.Weight = FW_NORMAL;
//	tFontInfo.CharSet = HANGEUL_CHARSET;
//	lstrcpy(tFontInfo.FaceName, L"Andy");
//
//	if (FAILED(D3DXCreateFontIndirect(m_pDevice, &tFontInfo, &m_pFont)))
//	{
//		MessageBox(NULL, L"Font Create Failed", L"System Message", MB_OK);
//		return E_FAIL;
//	}
//
//	return S_OK;
//}

HRESULT C_Device::Init(HWND hWnd)
{
	m_p3D = Direct3DCreate9(D3D_SDK_VERSION);
	
	D3DCAPS9	devicecaps;
	ZeroMemory(&devicecaps, sizeof(D3DCAPS9));

	if (FAILED(m_p3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE::D3DDEVTYPE_HAL, &devicecaps)))
	{
		MessageBox(NULL, L"Failed GetDevicecaps", L"System Message", MB_OK);
		return E_FAIL;
	}

	DWORD vp = 0;
	
	if (devicecaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;

	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	vp |= D3DCREATE_MULTITHREADED;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	
	SetParameters(&d3dpp);

	if (FAILED(m_p3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, vp, &d3dpp, &m_pDevice)))
	{
		MessageBox(NULL, L"m_p3D->CreateDevice Err", L"System Message", MB_OK);
		return E_FAIL;
	}

	if (FAILED(D3DXCreateSprite(m_pDevice, &m_pSprite)))
	{
		MessageBox(NULL, L"Create Sprite failed", L"System Message", MB_OK);
		return E_FAIL;
	}

	D3DXFONT_DESC		tFontInfo;
	ZeroMemory(&tFontInfo, sizeof(D3DXFONT_DESC));

	tFontInfo.Height = 10;
	tFontInfo.Width = 10;
	tFontInfo.Weight = FW_NORMAL;
	tFontInfo.CharSet = HANGEUL_CHARSET;
	lstrcpy(tFontInfo.FaceName, L"Andy");

	if (FAILED(D3DXCreateFontIndirect(m_pDevice, &tFontInfo, &m_pFont)))
	{
		MessageBox(NULL, L"Font Create Failed", L"System Message", MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

VOID C_Device::SetParameters(D3DPRESENT_PARAMETERS * d3dpp)
{
	d3dpp->BackBufferWidth = WINCX;
	d3dpp->BackBufferHeight = WINCY;
	d3dpp->BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp->BackBufferCount = 1;

	d3dpp->MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp->MultiSampleQuality = 0;

	d3dpp->SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp->hDeviceWindow = g_hWnd;
	d3dpp->Windowed = TRUE;

	d3dpp->EnableAutoDepthStencil = TRUE;
	d3dpp->AutoDepthStencilFormat = D3DFMT_D24S8;

	d3dpp->FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp->PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}

const LPDIRECT3DDEVICE9 C_Device::GetDeivce()
{
	return m_pDevice;
}

const LPD3DXSPRITE C_Device::GetSprite()
{
	return m_pSprite;
}

const LPD3DXFONT C_Device::GetFont()
{
	return m_pFont;
}