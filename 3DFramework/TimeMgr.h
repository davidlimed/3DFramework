#pragma once
#include "stdafx.h"
#include "Macro.h"

class C_TimeMgr
{
DeclareSingleton(C_TimeMgr)

private:
	LARGE_INTEGER		m_FrameTime;
	LARGE_INTEGER		m_FixTime;
	LARGE_INTEGER		m_LastTime;
	LARGE_INTEGER		m_CpuTick;
	float				m_fTime;

private:
	C_TimeMgr();
	~C_TimeMgr();

public:
	float GetTime();

public:
	void InitTime();
	void SetTime();
	
};