#pragma once
#include "Device.h"
#include "Macro.h"

class C_Component;

class C_GameObject
{
CreateBen(C_GameObject)
protected:
	map<wstring, C_Component*> m_mapComponentContainer;

protected:
	D3DXVECTOR3 m_vPos;
	D3DXVECTOR3 m_vDir;
	D3DXVECTOR3 m_vLook;

protected:
	D3DXMATRIX	m_matWorld;

	D3DXMATRIX	m_matScale;
	D3DXMATRIX	m_matRot;
	D3DXMATRIX	m_matTrans;
	D3DXMATRIX	m_matRev;
	D3DXMATRIX	m_matParents;

protected:
	float		m_fSpeed;
	float		m_fAngle;

public:
	C_GameObject();
	virtual ~C_GameObject();

//@Pure Function
public:
	virtual HRESULT AddComponent() PURE;
	virtual HRESULT Init() PURE;
	virtual	INT Update() PURE;
	virtual	VOID Render() PURE;
	virtual	VOID Release() PURE;

//@Interface
public:
	virtual HRESULT Awake();
	virtual INT LastUpdate();
	virtual INT LastRender();
	
};