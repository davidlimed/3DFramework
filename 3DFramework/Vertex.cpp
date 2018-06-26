#include "stdafx.h"
#include "Macro.h"
#include "Device.h"
#include "FlagDefine.h"
#include "Vertex.h"

C_Vertex::C_Vertex():
	m_pVB(nullptr),
	m_pIB(nullptr)
{
}

C_Vertex::~C_Vertex()
{
	Release();
}

//정점버퍼 생성
HRESULT C_Vertex::Init()
{
	S_VertexXYZ verXYZ[] = 
	{
		{ -1.f, -1.f, 0.f, 0xffff0000},
		{ 1.f, -1.f, 0.f, 0xff00ff00},
		{ 0.f, 1.f, 0.f, 0xff0000ff}
	
	};

	if (FAILED(C_Device::GetInstance()->GetDevice()->CreateVertexBuffer(
		3 * sizeof(S_VertexXYZ),
		NULL,
		FVF_VER_COLOR, 
		D3DPOOL_DEFAULT, 
		&m_pVB, 
		NULL)))
	{
		return E_FAIL;
	}

	void * pVertices;
	
	if (FAILED(m_pVB->Lock(NULL, sizeof(verXYZ), &pVertices, NULL)))
		return E_FAIL;

	memcpy(pVertices, verXYZ, sizeof(verXYZ));

	m_pVB->Unlock();

	return S_OK;
}

//사용자 지정 버텍스 생성
HRESULT C_Vertex::Init(WORD VertexCount)
{

	return S_OK;
}

HRESULT C_Vertex::Init(E_VERTEX_ID eID)
{
	if (eID == E_VERTEX_ID::eVertex)
	{
		if (FAILED(C_Device::GetInstance()->GetDevice()->CreateVertexBuffer(
			3 * sizeof(S_VertexXYZ),
			NULL,
			FVF_VER_COLOR,
			D3DPOOL_DEFAULT,
			&m_pVB,
			NULL)))
		{
			return E_FAIL;
		}

		S_VertexXYZ * pVertices = nullptr;
		
		m_pVB->Lock(NULL, NULL, (void**)&pVertices, NULL);

		pVertices[0] = { 50.f, 0.f, 2.f, 0xffff0000 };
		pVertices[1] = {  100.f, 50.f, 2.f, 0xffff0000 };
		pVertices[2] = { 0.f, 50.f, 2.f, 0xffff0000 };

		m_pVB->Unlock();
	}

	else if (eID == E_VERTEX_ID::eIndex)
	{
		if (FAILED(C_Device::GetInstance()->GetDevice()->CreateIndexBuffer(
			36 * sizeof(WORD),
			D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY,
			D3DFMT_INDEX16,
			D3DPOOL::D3DPOOL_MANAGED,
			&m_pIB,
			0)))
		{
			return E_FAIL;
		}

		S_VertexXYZ * pVertices = nullptr;

		m_pIB->Lock(NULL, NULL, (void**)&pVertices, NULL);

		pVertices[0] = { 50.f, 0.f, 2.f, 0xffff0000 };
		pVertices[1] = { 100.f, 50.f, 2.f, 0xffff0000 };
		pVertices[2] = { 0.f, 50.f, 2.f, 0xffff0000 };

		m_pIB->Unlock();
	}

	else
	{}

	return S_OK;
}

void C_Vertex::Update()
{
}

void C_Vertex::SetTest()
{
	ZeroMemory(m_pVB, sizeof(LPDIRECT3DVERTEXBUFFER9));

	if (FAILED(C_Device::GetInstance()->GetDevice()->CreateVertexBuffer(
		50 * 2 * sizeof(S_VertexNormal),
		NULL,
		FVF_NORMAL,
		D3DPOOL::D3DPOOL_MANAGED,
		&m_pVB,
		NULL)))
	{
		MsgBox(L"SetTest Func Err");

		return;
	}

	S_VertexNormal * pVertices = nullptr;

	if (FAILED(m_pVB->Lock(NULL, NULL, (void**)&pVertices, NULL)))
	{
		MsgBox(L"Lock err");

		return;
	}
	
	for (DWORD i = 0; i < 50; i++)
	{
		float theta = (2 * D3DX_PI * i) / (50 - 1);
		pVertices[2 * i].vPos = D3DXVECTOR3(sinf(theta), -1.f, cosf(theta));
		pVertices[2 * i].vNormal = D3DXVECTOR3(sinf(theta), 0.f, cosf(theta));
		pVertices[2 * i + 1].vPos = D3DXVECTOR3(sinf(theta), 1.f, cosf(theta));
		pVertices[2 * i + 1].vNormal = D3DXVECTOR3(sinf(theta), 1.f, cosf(theta));
	}
	
	m_pVB->Unlock();
}

void C_Vertex::SetTest2()
{
	ZeroMemory(m_pVB, sizeof(LPDIRECT3DVERTEXBUFFER9));

	if (FAILED(C_Device::GetInstance()->GetDevice()->CreateVertexBuffer(
		4 * sizeof(S_VertexTex),
		NULL,
		FVF_VER_TEX,
		D3DPOOL::D3DPOOL_MANAGED,
		&m_pVB,
		NULL)))
	{
		MsgBox(L"SetTest Func Err");

		return;
	}

	S_VertexTex * pVertexTex = nullptr;
	
	if (FAILED(m_pVB->Lock(NULL, NULL, (void**)&pVertexTex, NULL)))
	{
		MsgBox(L"Lock err");

		return;
	}
	pVertexTex[0].vPos = D3DXVECTOR3(-2.f, 2.f, 2.f);
	pVertexTex[0].dwColor = D3DCOLOR_ARGB(255, 255, 0, 0);
	pVertexTex[0].fU = 0.f;
	pVertexTex[0].fV = 0.f;

	pVertexTex[1].vPos = D3DXVECTOR3(2.f, 2.f, 2.f);
	pVertexTex[1].dwColor = D3DCOLOR_ARGB(255, 0, 255, 0);
	pVertexTex[1].fU = 1.f;
	pVertexTex[1].fV = 0.f;

	pVertexTex[2].vPos = D3DXVECTOR3(-2.f, -2.f, 2.f);
	pVertexTex[2].dwColor = D3DCOLOR_ARGB(255, 0, 0, 255);
	pVertexTex[2].fU = 0.f;
	pVertexTex[2].fV = 1.f;

	pVertexTex[3].vPos = D3DXVECTOR3(-2.f, -2.f, 2.f);
	pVertexTex[3].dwColor = D3DCOLOR_ARGB(255, 0, 0, 255);
	pVertexTex[3].fU = 1.f;
	pVertexTex[3].fV = 1.f;
	
	m_pVB->Unlock();

}

void C_Vertex::SetTest3()
{
	S_VertexXYZ * pVertex = nullptr;
	ZeroMemory(&m_pVB, sizeof(LPDIRECT3DVERTEXBUFFER9));

	if (FAILED(Device->CreateVertexBuffer(
		8 * sizeof(S_VertexXYZ),
		NULL,
		FVF_VER_COLOR,
		D3DPOOL::D3DPOOL_MANAGED,
		&m_pVB,
		NULL)))
	{
		MsgBox(L"SetTest Func Err");

		return;
	}

	m_pVB->Lock(NULL, NULL, (void**)&pVertex, NULL);

	pVertex[0].fX = -1; pVertex[0].fY = 1; pVertex[0].fZ = 1; pVertex[0].dwColor = 0xffff0000;
	pVertex[1].fX = 1; pVertex[1].fY = 1; pVertex[1].fZ = 1; pVertex[1].dwColor = 0xff00ff00;
	pVertex[2].fX = 1; pVertex[2].fY = 1; pVertex[2].fZ = -1; pVertex[2].dwColor = 0xffffff00;
	pVertex[3].fX = -1; pVertex[3].fY = 1; pVertex[3].fZ = -1; pVertex[3].dwColor = 0xff00ffff;
	pVertex[4].fX = -1; pVertex[4].fY = -1; pVertex[4].fZ = 1; pVertex[4].dwColor = 0xffff00ff;
	pVertex[5].fX = 1; pVertex[5].fY = -1; pVertex[5].fZ = 1; pVertex[5].dwColor = 0xff0000ff;
	pVertex[6].fX = 1; pVertex[6].fY = -1; pVertex[6].fZ = -1; pVertex[6].dwColor = 0xff000000;
	pVertex[7].fX = -1; pVertex[7].fY = -1; pVertex[7].fZ = -1; pVertex[7].dwColor = 0xffffffff;

	m_pVB->Unlock();

	if (FAILED(Device->CreateIndexBuffer(12 * sizeof(S_Index16), NULL, D3DFMT_INDEX16, D3DPOOL::D3DPOOL_MANAGED, &m_pIB, NULL)))
	{
		MsgBox(L"IndexBuffer ERR");
		return;
	}

	S_Index16 * pIndex16 = nullptr;

	m_pIB->Lock(NULL, NULL, (void**)&pIndex16, NULL);

	//윗면
	pIndex16[0]._0 = 0; pIndex16[0]._1 = 1; pIndex16[0]._2 = 2;
	pIndex16[1]._0 = 0; pIndex16[1]._1 = 2; pIndex16[1]._2 = 3;
	//앞면
	pIndex16[2]._0 = 3; pIndex16[2]._1 = 2; pIndex16[2]._2 = 6;
	pIndex16[3]._0 = 3; pIndex16[3]._1 = 6; pIndex16[3]._2 = 7;
	//오른쪽면
	pIndex16[4]._0 = 2; pIndex16[4]._1 = 1; pIndex16[4]._2 = 5;
	pIndex16[5]._0 = 2; pIndex16[5]._1 = 5; pIndex16[5]._2 = 6;
	//왼쪽면
	pIndex16[6]._0 = 0; pIndex16[6]._1 = 3; pIndex16[6]._2 = 7;
	pIndex16[7]._0 = 0; pIndex16[7]._1 = 7; pIndex16[7]._2 = 4;
	//뒷면
	pIndex16[8]._0 = 1; pIndex16[8]._1 = 0; pIndex16[8]._2 = 4;
	pIndex16[9]._0 = 1; pIndex16[9]._1 = 4; pIndex16[9]._2 = 5;
	//아랫면
	pIndex16[10]._0 = 4; pIndex16[10]._1 = 6; pIndex16[10]._2 = 5;
	pIndex16[11]._0 = 4; pIndex16[11]._1 = 7; pIndex16[11]._2 = 6;

	m_pIB->Unlock();
}

LPDIRECT3DVERTEXBUFFER9 C_Vertex::GetVB() const
{
	return m_pVB;
}

LPDIRECT3DINDEXBUFFER9 C_Vertex::GetIB() const
{
	return m_pIB;
}

void C_Vertex::Release()
{
	if (!m_pVB)
		return;
	
	m_pVB->Release();
	m_pVB = nullptr;

	if (!m_pIB)
		return;
	
	m_pIB->Release();
	m_pIB = nullptr;
}
