#pragma once
#include "GameObject.h"
#include "Macro.h"

class C_Player : public C_GameObject
{
CreateBen(C_Player);
private:
	typedef map<wstring, C_Component*>::value_type ValueType;

private:
	map<wstring, C_Component*>::iterator m_itor;

public:
	C_Player();
	virtual ~C_Player();
	
//Implement Virtual Pure Function
public:
	virtual HRESULT		Awake();
	virtual HRESULT		Init();//pure
	virtual	INT			Update();
	virtual	VOID		Render();
	virtual	VOID		Release();

public:
	virtual HRESULT AddComponent();

public:
	VOID SetSpeed(FLOAT fSpeed);
	VOID SetPos(D3DXVECTOR3 & vecPos);
	VOID SetDir(D3DXVECTOR3 & vecDir);

private:
	VOID KeyCommand();
};