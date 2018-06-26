#pragma once
#include "stdafx.h"
#include "Macro.h"

class C_GameObject;

class C_GameObjectMgr
{
DeclareSingleton(C_GameObjectMgr)
public:
	enum E_OBJECT_ID { ePlayer, eTest, eEnd};

private:
	map<E_OBJECT_ID, list<C_GameObject*>> m_mapGameObject;

private:
	C_GameObjectMgr();

public:
	~C_GameObjectMgr();
	
public:
	//Object ID = Include C_GameObjectMgr
	void AddObject(E_OBJECT_ID eID, C_GameObject * pGameObject);
	
public:
	HRESULT Init();
	void Update();
	void LastUpdate();
	void Render();
	void LastRender();

	//Set
public:
	void SetPlayerPos(D3DXVECTOR3 vPos);

	//Get
public:
	list<C_GameObject*> GetGameObejctList(E_OBJECT_ID ID);
	C_GameObject * GetPlayer();

};