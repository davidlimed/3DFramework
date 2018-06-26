#pragma once
#include "GameObject.h"
#include "Macro.h"

class C_TestLight;

class C_Player : public C_GameObject
{
CreateBen(C_Player);
private:
	typedef map<wstring, C_Component*>::value_type ValueType;

//Container
private:
	map<wstring, C_Component*>::iterator m_itor;
	queue<D3DXVECTOR3> m_queue;

private:
	LPDIRECT3DTEXTURE9 m_pTexture;
	C_TestLight * m_pLight;

public:
	C_Player();
	virtual ~C_Player();
	
//Implement Virtual Pure Function
public:
	virtual HRESULT		Awake();
	virtual HRESULT		Init();//pure
	virtual	INT			Update();//pure
	virtual	VOID		Render();//pure
	virtual	VOID		Release();

public:
	virtual HRESULT AddComponent();

public:
	VOID SetSpeed(FLOAT fSpeed);
	VOID SetPos(D3DXVECTOR3 & vecPos);
	VOID SetDir(D3DXVECTOR3 & vecDir);

public:
	D3DXVECTOR3 GetPos() const;
	float		GetSpeed() const;

private:
	VOID KeyCommand();
};