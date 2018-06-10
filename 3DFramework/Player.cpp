#include "stdafx.h"
#include "Player.h"
#include "Vertex.h"
#include "VertexInfo.h"
#include "TimeMgr.h"
#include "FlagDefine.h"
#include "RenderMgr.h"

C_Player::C_Player(){}

C_Player::~C_Player()
{
}

HRESULT C_Player::Init()
{
	if (FAILED(AddComponent()))
		return E_FAIL;

	itor = m_mapComponentContainer.find(L"TestComponent");

	if (itor == m_mapComponentContainer.end())
	{
		MsgBox(L"itor err");
		return 0;
	}

	dynamic_cast<C_Vertex*>((*itor).second)->SetTest();

	return S_OK;
}

INT C_Player::Update()
{
	m_fAngle += 0.1f;

	D3DXMatrixRotationY(&m_matRot, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&m_matTrans, 2.f, 0.f, 4.f);

	m_matWorld = m_matRot * m_matTrans;

	return 0;
}

VOID C_Player::Render()
{
	C_RenderMgr::GetInstance()->Rendering(m_matWorld, dynamic_cast<C_Vertex*>((*itor).second)->GetVB(), sizeof(S_VertexNormal), FVF_NORMAL, D3DPT_TRIANGLESTRIP, UINT(2 * 50 - 2));
}

VOID C_Player::Release()
{
	return VOID();
}

HRESULT C_Player::AddComponent()
{
	C_Component * pComponent = new C_Vertex();
	if (FAILED(pComponent->Init()))
		return E_FAIL;

	m_mapComponentContainer.insert(map<wstring, C_Component*>::value_type(L"TestComponent", pComponent));
	

	return S_OK;
}
