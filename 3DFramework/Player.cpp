#include "stdafx.h"
#include "Player.h"
#include "Vertex.h"
#include "VertexInfo.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "FlagDefine.h"
#include "RenderMgr.h"

C_Player::C_Player(){}

C_Player::~C_Player()
{
}

HRESULT C_Player::Awake()
{
	return S_OK;
}

HRESULT C_Player::Init()
{
	if (FAILED(AddComponent()))
		return E_FAIL;

	m_itor = m_mapComponentContainer.find(L"TestComponent");

	if (m_itor == m_mapComponentContainer.end())
	{
		MsgBox(L"itor err");
		return 0;
	}

	dynamic_cast<C_Vertex*>((*m_itor).second)->SetTest();

	return S_OK;
}

INT C_Player::Update()
{
	KeyCommand();

	m_fAngle += 0.1f;

	D3DXMatrixRotationY(&m_matRot, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&m_matTrans, m_vPos.x, 0.f, m_vPos.z);

	m_matWorld = m_matRot * m_matTrans;

	return 0;
}

VOID C_Player::Render()
{
	RenderMgr->Rendering(m_matWorld,
		dynamic_cast<C_Vertex*>((*m_itor).second)->GetVB(),
		sizeof(S_VertexNormal),
		FVF_NORMAL,
		D3DPT_TRIANGLESTRIP,
		UINT(2 * 50 - 2));
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

VOID C_Player::KeyCommand()
{
#ifdef KEY_MGR
	if (KeyMgr->OnceKeyDown('W'))
	{
		if (KeyMgr->OnceKeyDown('D'))
		{
			m_vPos.z += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}

		else if (KeyMgr->OnceKeyDown('A'))
		{
			m_vPos.z += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}

		else
			m_vPos.z += (3.f * DeltaTime);
	}

	else if (KeyMgr->OnceKeyDown('S'))
	{
		if (KeyMgr->OnceKeyDown('D'))
		{
			m_vPos.z -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}

		else if (KeyMgr->OnceKeyDown('A'))
		{
			m_vPos.z -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}

		else
			m_vPos.z -= (3.f * DeltaTime);
	}

	else if (KeyMgr->OnceKeyDown('A'))
	{
		if (KeyMgr->OnceKeyDown('W'))
		{
			m_vPos.z += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}
		else if (KeyMgr->OnceKeyDown('S'))
		{
			m_vPos.z -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}
		else
			m_vPos.x -= (3.f * DeltaTime);
	}

	else if (KeyMgr->OnceKeyDown('D'))
	{
		if (KeyMgr->OnceKeyDown('W'))
		{
			m_vPos.z += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}
		else if (KeyMgr->OnceKeyDown('S'))
		{
			m_vPos.z -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}
		else
			m_vPos.x += (3.f * DeltaTime);
	}

#endif
	if (GetAsyncKeyState('W') & 0x8000)
	{
		if (GetAsyncKeyState('D') & 0x8000)
		{
			m_vPos.z += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}

		else if (GetAsyncKeyState('A') & 0x8000)
		{
			m_vPos.z += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}

		else
			m_vPos.z += (3.f * DeltaTime);
	}

	else if (GetAsyncKeyState('S') & 0x8000)
	{
		if (GetAsyncKeyState('D') & 0x8000)
		{
			m_vPos.z -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}

		else if (GetAsyncKeyState('A') & 0x8000)
		{
			m_vPos.z -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}

		else
			m_vPos.z -= (3.f * DeltaTime);
	}

	else if (GetAsyncKeyState('A') & 0x8000)
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			m_vPos.z += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			m_vPos.z -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}
		else
			m_vPos.x -= (3.f * DeltaTime);
	}

	else if (GetAsyncKeyState('D') & 0x8000)
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			m_vPos.z += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			m_vPos.z -= (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
			m_vPos.x += (3.f * DeltaTime / (1.5f * sqrtf(2.f)));
		}
		else
			m_vPos.x += (3.f * DeltaTime);
	}
}
