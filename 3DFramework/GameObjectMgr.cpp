#include "stdafx.h"
#include "GameObjectMgr.h"
#include "Functor.h"
#include "GameObject.h"

C_GameObjectMgr::~C_GameObjectMgr()
{
}

void C_GameObjectMgr::AddObject(E_OBJECT_ID eID, C_GameObject * pGameObject)
{
	Exception(pGameObject, L"AddObject Err");
	
	map<E_OBJECT_ID, list<C_GameObject*>>::iterator	itor = m_mapGameObject.find(eID);
	if (itor == m_mapGameObject.end())
	{
		m_mapGameObject[eID] = list<C_GameObject*>();
	}
	m_mapGameObject[eID].push_back(pGameObject);
	//추가 후 초기화
	m_mapGameObject[eID].back()->Awake();
	m_mapGameObject[eID].back()->Init();
}

HRESULT C_GameObjectMgr::Init()
{
	

	return S_OK;
}

void C_GameObjectMgr::Update()
{
	map<E_OBJECT_ID, list<C_GameObject*>>::iterator itorfirst = m_mapGameObject.begin();

	for (; itorfirst != m_mapGameObject.end(); ++itorfirst)
	{
		list<C_GameObject*>::iterator itorSecond = itorfirst->second.begin();

		for (; itorSecond != itorfirst->second.end(); ++itorSecond)
		{
			(*itorSecond)->Update();
		}
	}
}

void C_GameObjectMgr::LastUpdate()
{
	map<E_OBJECT_ID, list<C_GameObject*>>::iterator itorfirst = m_mapGameObject.begin();

	for (; itorfirst != m_mapGameObject.end(); ++itorfirst)
	{
		list<C_GameObject*>::iterator itorSecond = itorfirst->second.begin();

		for (; itorSecond != itorfirst->second.end(); ++itorSecond)
		{
			(*itorSecond)->LastUpdate();
		}
	}
}

void C_GameObjectMgr::Render()
{
	map<E_OBJECT_ID, list<C_GameObject*>>::iterator itorfirst = m_mapGameObject.begin();

	for (; itorfirst != m_mapGameObject.end(); ++itorfirst)
	{
		list<C_GameObject*>::iterator itorSecond = itorfirst->second.begin();

		for (; itorSecond != itorfirst->second.end(); ++itorSecond)
		{
			(*itorSecond)->Render();
		}
	}
}

void C_GameObjectMgr::LastRender()
{
	map<E_OBJECT_ID, list<C_GameObject*>>::iterator itorfirst = m_mapGameObject.begin();

	for (; itorfirst != m_mapGameObject.end(); ++itorfirst)
	{
		list<C_GameObject*>::const_iterator itorSecond = itorfirst->second.begin();

		for (; itorSecond != itorfirst->second.end(); ++itorSecond)
		{
			(*itorSecond)->LastRender();
		}
	}
}

list<C_GameObject*> C_GameObjectMgr::GetGameObejctList(E_OBJECT_ID ID)
{
	map<E_OBJECT_ID, list<C_GameObject*>>::iterator	itor = m_mapGameObject.find(ID);

	return itor->second;
}

C_GameObject * C_GameObjectMgr::GetPlayer()
{
	map<E_OBJECT_ID, list<C_GameObject*>>::iterator	itor = m_mapGameObject.find(ePlayer);

	return itor->second.front();
}
