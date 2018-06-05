#include "stdafx.h"
#include "Macro.h"
#include "Device.h"
#include "FlagDefine.h"
#include "Vertex.h"

C_Vertex::C_Vertex():
	m_pVB(nullptr)
{
}

C_Vertex::~C_Vertex(){}

//정점버퍼 생성
HRESULT C_Vertex::Init()
{
	S_VertexColor verColor[] = 
	{
		{ 150.f, 50.f, 0.5f, 0xffff0000},
		{ 250.f, 250.f, 0.5f, 0xff00ff00 },
		{ 50.f, 250.f, 0.5f, 0xff0000ff }
	
	};

	if (FAILED(C_Device::GetInstance()->GetDevice()->CreateVertexBuffer(
		3 * sizeof(S_VertexColor), 
		NULL,
		FVF_VER_COLOR, 
		D3DPOOL_DEFAULT, 
		&m_pVB, 
		NULL)))
	{
		return E_FAIL;
	}

	void * pVertices;
	
	if (FAILED(m_pVB->Lock(NULL, sizeof(verColor), &pVertices, NULL)))
		return E_FAIL;

	memcpy(pVertices, verColor, sizeof(verColor));

	m_pVB->Unlock();

	return S_OK;
}

//사용자 지정 버텍스 생성
HRESULT C_Vertex::Init(WORD VertexCount)
{
	S_VertexColor * verColor = new S_VertexColor[VertexCount];

	if (FAILED(C_Device::GetInstance()->GetDevice()->CreateVertexBuffer(
		VertexCount * sizeof(S_VertexColor),
		NULL,
		FVF_VER_COLOR,
		D3DPOOL_DEFAULT,
		&m_pVB,
		NULL)))
	{
		return E_FAIL;
	}

	void * pVertices;

	if (FAILED(m_pVB->Lock(NULL, sizeof(verColor), &pVertices, NULL)))
		return E_FAIL;

	memcpy(pVertices, verColor, sizeof(verColor));

	m_pVB->Unlock();

	return S_OK;
}

LPDIRECT3DVERTEXBUFFER9 C_Vertex::GetVB() const
{
	return m_pVB;
}

void C_Vertex::Release()
{
	if (!m_pVB)
		return;
	
	m_pVB->Release();
	m_pVB = nullptr;
		
}
