#include "stdafx.h"
#include "Light.h"

C_Light::C_Light()
{
}

C_Light::~C_Light()
{
	Release();
}

HRESULT C_Light::Init()
{
	return S_OK;
}

void C_Light::Update()
{
}

void C_Light::Release()
{
}

void C_Light::SetMaterial(D3DMATERIAL9 & material)
{
	m_mtrl = material;
}

void C_Light::SetLight(D3DLIGHTTYPE eType, float fDiffuse_r, float fDiffuse_g, float fDiffuse_b, D3DXVECTOR3 vecDir, float fRange)
{
	m_light.Type = eType;
	m_light.Diffuse.r = fDiffuse_r;
	m_light.Diffuse.g = fDiffuse_g;
	m_light.Diffuse.b = fDiffuse_b;

	m_light.Direction = vecDir;
	m_light.Range = fRange;
}
