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
	{

	}

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
