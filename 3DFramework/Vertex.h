#pragma once
#include "stdafx.h"
#include "Component.h"
#include "Macro.h"
#include "VertexInfo.h"

class C_Vertex : public C_Component
{
CreateBen(C_Vertex)

public:
	enum E_VERTEX_ID {eDefault, eVertex, eIndex};

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVB;
	LPDIRECT3DINDEXBUFFER9	m_pIB;

public:
	C_Vertex();
	virtual ~C_Vertex();

public:
	virtual HRESULT Init();
	//@Overriding
	HRESULT Init(WORD VertexCount);
	HRESULT Init(E_VERTEX_ID eID);

public:
	virtual void Update();

public:
	void SetTest();


public:
	LPDIRECT3DVERTEXBUFFER9 GetVB() const;
	LPDIRECT3DINDEXBUFFER9 GetIB() const;

public:
	void Release();
	
};