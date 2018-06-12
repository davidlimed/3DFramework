#include "stdafx.h"
#include "MainCamera.h"
#include "TimeMgr.h"
#include "Device.h"

C_MainCamera::C_MainCamera():
	m_matProj{},
	m_matView{},
	m_vecAt{},
	m_vecUp{},
	m_vecPos{},
	m_fAspect(0.f),
	m_fFar(0.f),
	m_fFovY(0.f),
	m_fNear(0.f),
	m_fTime(0),
	m_fRunningTime(0),
	m_fInterval(0),
	m_bisVibration(false),
	m_fMovingSpeed(0.f)
{}

C_MainCamera::~C_MainCamera()
{
	Release();
}

HRESULT C_MainCamera::Init()
{
	m_vecPos = D3DXVECTOR3(0.f, 3.f, -5.f);
	m_vecAt = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_vecUp = D3DXVECTOR3(0.f, 1.f, 0.f);

	m_fFovY = D3DX_PI / 4;
	m_fAspect = 1.f;
	m_fNear = 1.f;
	m_fFar = 100.f;

	D3DXMatrixLookAtLH(&m_matView, &m_vecPos, &m_vecAt, &m_vecUp);
	D3DXMatrixPerspectiveFovLH(&m_matProj, m_fFovY, m_fAspect, m_fNear, m_fFar);

	Device->SetTransform(D3DTRANSFORMSTATETYPE::D3DTS_VIEW, &m_matView);
	Device->SetTransform(D3DTRANSFORMSTATETYPE::D3DTS_PROJECTION, &m_matProj);

	return S_OK;
}

void C_MainCamera::Update()
{
	if (m_bisVibration)
	{
		Vibration();

		return;
	}
	
	if (GetAsyncKeyState(VK_UP))
	{
		m_vecPos.z += (1.f * DeltaTime);
		m_vecAt.z += (1.f * DeltaTime);
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_vecPos.z -= (1.f * DeltaTime);
		m_vecAt.z -= (1.f * DeltaTime);
	}
	
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_vecPos.x += (1.f * DeltaTime);
		m_vecAt.x += (1.f * DeltaTime);
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_vecPos.x -= (1.f * DeltaTime);
		m_vecAt.x -= (1.f * DeltaTime);
	}

	D3DXMatrixLookAtLH(&m_matView, &m_vecPos, &m_vecAt, &m_vecUp);
	D3DXMatrixPerspectiveFovLH(&m_matProj, m_fFovY, m_fAspect, m_fNear, m_fFar);

	Device->SetTransform(D3DTRANSFORMSTATETYPE::D3DTS_VIEW, &m_matView);
	Device->SetTransform(D3DTRANSFORMSTATETYPE::D3DTS_PROJECTION, &m_matProj);
}

void C_MainCamera::SetInterval(float Interval)
{
	m_fInterval = Interval;
}

void C_MainCamera::SetTime(float time)
{
	m_fTime = time;
}

void C_MainCamera::SetTarget(D3DXVECTOR3 vecTargetPos)
{
	m_vecAt = vecTargetPos;
}

void C_MainCamera::SetPos(D3DXVECTOR3 vecEye)
{
	m_vecPos = vecEye;
}

void C_MainCamera::SetUp(D3DXVECTOR3 vecUp)
{
	m_vecUp = vecUp;
}

void C_MainCamera::SetViewElement(D3DXVECTOR3 Eye, D3DXVECTOR3 Up, D3DXVECTOR3 At)
{
	m_vecPos = Eye;
	m_vecUp = Up;
	m_vecAt = At;

	return;
}

void C_MainCamera::SetProjectionElement(float Fov, float Aspect, float Near, float Far)
{
	m_fFovY = Fov;
	m_fAspect = Aspect;
	m_fNear = Near;
	m_fFar = Far;

	return;
}

void C_MainCamera::SetFovY(float Fov)
{
}

void C_MainCamera::SetAspect(float Aspect)
{
}

void C_MainCamera::SetNear(float Near)
{
}

void C_MainCamera::SetFar(float Far)
{
}

void C_MainCamera::Release()
{
}

void C_MainCamera::Vibration()
{
	if (m_fTime <= m_fRunningTime)
	{
		m_bisVibration = false;
		m_fRunningTime = 0;
		return;
	}
	
	m_fRunningTime += (1.f * C_TimeMgr::GetInstance()->GetTime());
	
}
