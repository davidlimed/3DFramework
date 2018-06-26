#include "stdafx.h"
#include "Player.h"
#include "Vertex.h"
#include "VertexInfo.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "FlagDefine.h"
#include "RenderMgr.h"
#include "TestLight.h"

C_Player::C_Player():
	m_pLight(nullptr)
{}

C_Player::~C_Player()
{
}

HRESULT C_Player::Awake()
{
	return S_OK;
}

HRESULT C_Player::Init()
{
	//Element Setting
	m_vPos = D3DXVECTOR3(0.f, 1.f, 2.f);
	m_fSpeed = 3.f;

	//
	//

	if (FAILED(AddComponent()))
		return E_FAIL;

	m_itor = m_mapComponentContainer.find(L"TestComponent");

	if (m_itor == m_mapComponentContainer.end())
	{
		MsgBox(L"itor err");
		return 0;
	}

	dynamic_cast<C_Vertex*>((*m_itor).second)->SetTest3();

	return S_OK;
}

INT C_Player::Update()
{
	KeyCommand();

	m_fAngle += 10.f * DeltaTime;

	D3DXMatrixScaling(&m_matScale, 0.5f, 0.5f, 0.5f);
	D3DXMatrixRotationY(&m_matRot, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&m_matTrans, m_vPos.x, 0.f, m_vPos.z);

	m_matWorld = m_matScale * m_matRot * m_matTrans;

	return 0;
}

VOID C_Player::Render()
{
	RenderMgr->SetLight(false);
	
	/*RenderMgr->Rendering(m_matWorld,
		dynamic_cast<C_Vertex*>((*m_itor).second)->GetVB(),
		sizeof(S_VertexTex),
		FVF_VER_TEX,
		D3DPT_TRIANGLELIST,
		4);*/

	Device->SetTransform(D3DTS_WORLD, &m_matWorld);
	Device->SetStreamSource(0, dynamic_cast<C_Vertex*>((*m_itor).second)->GetVB(), NULL, sizeof(S_VertexXYZ));
	Device->SetFVF(FVF_VER_COLOR);
	Device->SetIndices(dynamic_cast<C_Vertex*>((*m_itor).second)->GetIB());
	Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);


	RenderMgr->SetLight(false);
}

VOID C_Player::Release()
{
	m_itor = m_mapComponentContainer.begin();
	
	for (; m_itor != m_mapComponentContainer.end(); m_itor++)
	{
		delete m_itor->second;
		m_itor->second = nullptr;
	}
}

HRESULT C_Player::AddComponent()
{
	C_Component * pComponent = new C_Vertex();
	if (FAILED(pComponent->Init()))
		return E_FAIL;

	m_mapComponentContainer.insert(ValueType(L"TestComponent", pComponent));

	pComponent = new C_TestLight();
	if (FAILED(pComponent->Init()))
		return E_FAIL;

	m_mapComponentContainer.insert(ValueType(L"TestLight", pComponent));
	

	return S_OK;
}

VOID C_Player::SetSpeed(FLOAT fSpeed)
{
	m_fSpeed = fSpeed;
}

VOID C_Player::SetPos(D3DXVECTOR3 & vecPos)
{
	m_vPos = vecPos;
}

VOID C_Player::SetDir(D3DXVECTOR3 & vecDir)
{
	m_vDir = vecDir;
}

D3DXVECTOR3 C_Player::GetPos() const
{
	return m_vPos;
}

float C_Player::GetSpeed() const
{
	return m_fSpeed;
}

VOID C_Player::KeyCommand()
{
#ifdef KEY_MGR
	if (KeyMgr->StayKeyDown('W'))
	{
		if (KeyMgr->StayKeyDown('D'))
		{
			m_vPos.z += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}

		else if (KeyMgr->StayKeyDown('A'))
		{
			m_vPos.z += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}

		else
			m_vPos.z += (m_fSpeed * DeltaTime);
	}

	else if (KeyMgr->StayKeyDown('S'))
	{
		if (KeyMgr->StayKeyDown('D'))
		{
			m_vPos.z -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}

		else if (KeyMgr->StayKeyDown('A'))
		{
			m_vPos.z -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}

		else
			m_vPos.z -= (m_fSpeed * DeltaTime);
	}

	else if (KeyMgr->StayKeyDown('A'))
	{
		if (KeyMgr->StayKeyDown('W'))
		{
			m_vPos.z += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}
		else if (KeyMgr->StayKeyDown('S'))
		{
			m_vPos.z -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}
		else
			m_vPos.x -= (m_fSpeed * DeltaTime);
	}

	else if (KeyMgr->StayKeyDown('D'))
	{
		if (KeyMgr->StayKeyDown('W'))
		{
			m_vPos.z += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}
		else if (KeyMgr->StayKeyDown('S'))
		{
			m_vPos.z -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}
		else
			m_vPos.x += (m_fSpeed * DeltaTime);
	}

#else
	if (GetAsyncKeyState('W') & 0x8000)
	{
		if (GetAsyncKeyState('D') & 0x8000)
		{
			m_vPos.z += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}

		else if (GetAsyncKeyState('A') & 0x8000)
		{
			m_vPos.z += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}

		else
			m_vPos.z += (m_fSpeed * DeltaTime);
	}

	else if (GetAsyncKeyState('S') & 0x8000)
	{
		if (GetAsyncKeyState('D') & 0x8000)
		{
			m_vPos.z -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}

		else if (GetAsyncKeyState('A') & 0x8000)
		{
			m_vPos.z -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}

		else
			m_vPos.z -= (m_fSpeed * DeltaTime);
	}

	else if (GetAsyncKeyState('A') & 0x8000)
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			m_vPos.z += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			m_vPos.z -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}
		else
			m_vPos.x -= (m_fSpeed * DeltaTime);
	}

	else if (GetAsyncKeyState('D') & 0x8000)
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			m_vPos.z += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			m_vPos.z -= (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
			m_vPos.x += (m_fSpeed * DeltaTime / (m_fSpeed / 2 * sqrtf(2.f)));
		}
		else
			m_vPos.x += (m_fSpeed * DeltaTime);
	}
#endif
}
