#include "stdafx.h"
#include "MainCamera.h"

C_MainCamera::C_MainCamera():
	m_matProj{},
	m_matView{},
	m_vecAt{},
	m_vecLook{},
	m_vecPos{}
{}

C_MainCamera::~C_MainCamera()
{
}

void C_MainCamera::Init()
{
}

void C_MainCamera::SetInterval(UINT Interval)
{
	m_unInterval = Interval;
}

void C_MainCamera::Release()
{
}
