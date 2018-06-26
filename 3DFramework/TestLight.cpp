#include "stdafx.h"
#include "TestLight.h"
#include "Device.h"

C_TestLight::C_TestLight():
	m_light{},
	m_mtrl{},
	m_vecDir{}
{
}

C_TestLight::~C_TestLight()
{
}

HRESULT C_TestLight::Init()
{
	m_mtrl.Diffuse.a = 1.f;
	m_mtrl.Diffuse.r = 1.f;
	m_mtrl.Diffuse.g = 1.f;
	m_mtrl.Diffuse.b = 1.f;

	Device->SetMaterial(&m_mtrl);

	m_light.Type = D3DLIGHT_DIRECTIONAL;
	m_light.Type = D3DLIGHTTYPE::D3DLIGHT_DIRECTIONAL;

	m_light.Diffuse.r = 1.f;
	m_light.Diffuse.g = 1.f;
	m_light.Diffuse.b = 1.f;
	
	m_vecDir = D3DXVECTOR3(D3DXToRadian(45.f), 1.f, D3DXToRadian(30.f));
	D3DXVec3Normalize((D3DXVECTOR3 *)&m_light.Direction, &m_vecDir);
	m_light.Range = 10000.f;

	Device->SetLight(0, &m_light);
	Device->SetRenderState(D3DRS_AMBIENT, 0x00202020);
	
	return S_OK;
}

void C_TestLight::Update()
{
}

void C_TestLight::Release()
{
}
