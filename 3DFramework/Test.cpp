#include "stdafx.h"
#include "Device.h"
#include "Test.h"
#include "Vertex.h"
#include "FlagDefine.h"
#include "TestLight.h"

C_Test::C_Test():
	m_pVerBuffer(nullptr),
	m_pVertexComponent(nullptr),
	m_pTestLight(nullptr),
	m_fAngle(0.f)
{
}

C_Test::~C_Test()
{
}

HRESULT C_Test::Init()
{
	if (FAILED(AddComponent()))
		return E_FAIL;

	CreateObject(m_pVertexComponent, C_Vertex);
	CreateObject(m_pTestLight, C_TestLight);
	dynamic_cast<C_Vertex*>(m_pVertexComponent)->SetTest();
	m_pVerBuffer = dynamic_cast<C_Vertex*>(m_pVertexComponent)->GetVB();


	return S_OK;
}

INT C_Test::Update()
{
	m_fAngle += 0.1f;

	D3DXMatrixRotationY(&m_matRot, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&m_matTrans, -1.f, 0.f, 0.f);

	m_matWorld = m_matRot * m_matTrans;

	return 0;
}

VOID C_Test::Render()
{
	GraphicDevice(C_Device)->LightEnable(0, true);
	GraphicDevice(C_Device)->SetRenderState(D3DRS_LIGHTING, true);

	GraphicDevice(C_Device)->SetTransform(D3DTS_WORLD, &m_matWorld);
	GraphicDevice(C_Device)->SetStreamSource(NULL, m_pVerBuffer, 0, sizeof(S_VertexNormal));
	GraphicDevice(C_Device)->SetFVF(FVF_NORMAL);
	GraphicDevice(C_Device)->DrawPrimitive(D3DPRIMITIVETYPE::D3DPT_TRIANGLESTRIP, 0, 2 * 50 -2);

	//GraphicDevice(C_Device)->LightEnable(0, false);
	//GraphicDevice(C_Device)->SetRenderState(D3DRS_LIGHTING, false);
}

VOID C_Test::Release()
{
	m_pVerBuffer->Release();
	m_pVertexComponent->Release();
}

HRESULT C_Test::AddComponent()
{
	return S_OK;
}
