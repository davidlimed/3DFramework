#pragma once
#include "stdafx.h"
#include "Macro.h"
#include "VertexInfo.h"

class C_Vertex
{
CreateBen(C_Vertex)
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVB;

public:
	C_Vertex();
	~C_Vertex();

public:
	HRESULT Init();
	//@Overriding
	HRESULT Init(WORD VertexCount);
	
public:
	LPDIRECT3DVERTEXBUFFER9 GetVB() const;
	
public:

public:
	void Release();
	
};