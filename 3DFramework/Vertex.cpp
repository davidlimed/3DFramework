#include "stdafx.h"
#include "Macro.h"
#include "Device.h"
#include "FlagDefine.h"
#include "Vertex.h"

C_Vertex::C_Vertex():
	m_pVB(nullptr)
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
		{ 200.f, 50.f, 0.f, 0xffff0000},
		{ 200.f, 100.f, 0.f, 0xff00ff00},
		{ 100.f, 100.f, 0.f, 0xff0000ff}
	
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
