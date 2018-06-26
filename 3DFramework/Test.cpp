#include "stdafx.h"
#include "Device.h"
#include "Test.h"
#include "Vertex.h"
#include "FlagDefine.h"
#include "TestLight.h"
#include "RenderMgr.h"
#include "TimeMgr.h"

C_Test::C_Test():
	m_pVerBuffer(nullptr),
	m_pVertexComponent(nullptr),
	m_pTestLight(nullptr),
	m_pTexture(nullptr),
	m_fAngle(0.f),
	m_dwCount(0),
	m_pMesh(nullptr),
	m_pMeshMeterials(nullptr),
	m_pMeshTexture(nullptr)
{
}

C_Test::~C_Test()
{
}

HRESULT C_Test::Init()
{
	if (FAILED(AddComponent()))
		return E_FAIL;

	if (FAILED(D3DXCreateTextureFromFile(Device, L"../Texture/Tex.png", &m_pTexture)))
	{
		MsgBox(L"CreateTexture Fail");
		return E_FAIL;
	}

	CreateObject(m_pVertexComponent, C_Vertex);

	if(FAILED(Device->CreateVertexBuffer(50 * 2 * sizeof(S_VertexTex), 
		NULL, 
		FVF_VER_TEX, 
		D3DPOOL::D3DPOOL_MANAGED, 
		&m_pVerBuffer, 
		NULL)))
	{
		MsgBox(L"Create VertexBuffer Fail");
		return E_FAIL;
	}
	//Z Buffe


	Device->SetRenderState(D3DRS_ZENABLE, TRUE);
	Device->SetRenderState(D3DRS_AMBIENT, 0xffffffff);
	
	//dynamic_cast<C_Vertex*>(m_pVertexComponent)->SetTest();
	//m_pVerBuffer = dynamic_cast<C_Vertex*>(m_pVertexComponent)->GetVB();

	S_VertexTex * pVertices = nullptr;
	
	if (FAILED(m_pVerBuffer->Lock(NULL, NULL, (void**)&pVertices, NULL)))
		return E_FAIL;

	for (DWORD i = 0; i < 50; i++)
	{
		float theta = (2 * D3DX_PI * i) / (50 - 1);

		pVertices[2 * i].vPos = D3DXVECTOR3(sinf(theta), -1.f, cosf(theta));
		pVertices[2 * i].dwColor = 0xffffffff;
		pVertices[2 * i].fU = ((float)i / 49);
		pVertices[2 * i].fV = 1.f;

		pVertices[2 * i + 1].vPos = D3DXVECTOR3(sinf(theta), 1.f, cosf(theta));
		pVertices[2 * i + 1].dwColor = 0xff808080;
		pVertices[2 * i + 1].fU = ((float)i / 49);
		pVertices[2 * i + 1].fV = 0.f;
	}

	m_pVerBuffer->Unlock();

	///////////////////Mesh

	LPD3DXBUFFER pD3DXMtrlBuffer;
	
	if (FAILED(D3DXLoadMeshFromX(L"../Mesh/tiger.x", 
		D3DXMESH_SYSTEMMEM, 
		Device, 
		NULL, 
		&pD3DXMtrlBuffer,
		NULL, 
		&m_dwCount, 
		&m_pMesh)))
	{
		MsgBox(L"Mesh Load Fail");

		return E_FAIL;
	}

	D3DXMATERIAL * pD3dMaterial = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();
	m_pMeshMeterials = new D3DMATERIAL9[m_dwCount];
	m_pMeshTexture = new LPDIRECT3DTEXTURE9[m_dwCount];

	for (DWORD i = 0; i < m_dwCount; i++)
	{
		m_pMeshMeterials[i] = pD3dMaterial[i].MatD3D;
		m_pMeshMeterials[i].Ambient = m_pMeshMeterials[i].Diffuse;

		m_pMeshTexture[i] = NULL;
		if (FAILED(D3DXCreateTextureFromFile(Device, L"../Mesh/tiger.bmp", &m_pMeshTexture[i])))
		{
			MsgBox(L"Mesh Texture Err");
			return E_FAIL;
		}
	}

	pD3DXMtrlBuffer->Release();

	return S_OK;
}

INT C_Test::Update()
{
	m_fAngle += (1.f * DeltaTime);

	D3DXMatrixRotationY(&m_matRot, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&m_matTrans, -1.f, 0.f, 0.f);

	m_matWorld = m_matRot * m_matTrans;

	return 0;
}

VOID C_Test::Render()
{
	C_RenderMgr::GetInstance()->SetLight(true);
	Device->SetTransform(D3DTS_WORLD, &m_matWorld);

	//Device->SetTexture(0, m_pTexture);
	for (DWORD i = 0; i < m_dwCount; ++i)
	{
		Device->SetMaterial(&m_pMeshMeterials[i]);
		Device->SetTexture(0, m_pMeshTexture[i]);

		m_pMesh->DrawSubset(i);
	}


	/*C_RenderMgr::GetInstance()->Rendering(m_matWorld, m_pVerBuffer, sizeof(S_VertexTex), FVF_VER_TEX, D3DPT_TRIANGLESTRIP
		, 2 * 50 - 2);*/

	C_RenderMgr::GetInstance()->SetLight(false);

}

VOID C_Test::Release()
{
	if (m_pMeshMeterials)
		delete[] m_pMeshMeterials;
	
	if (m_pMeshTexture)
	{
		for (DWORD i = 0; i < m_dwCount; i++)
		{
			if (m_pMeshTexture[i])
				m_pMeshTexture[i]->Release();
		}
		delete[] m_pMeshTexture;
	}

	if (m_pMesh)
		m_pMesh->Release();

	m_pVerBuffer->Release();
	m_pVertexComponent->Release();
}

HRESULT C_Test::AddComponent()
{
	return S_OK;
}
