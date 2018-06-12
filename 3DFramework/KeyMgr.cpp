#include "stdafx.h"
#include "KeyMgr.h"

ImplementSingleton(C_KeyMgr)

C_KeyMgr::C_KeyMgr()
{
}

C_KeyMgr::~C_KeyMgr()
{
	Release();
}

bool C_KeyMgr::StayKeyDown(INT nKey)
{
	if (GetAsyncKeyState(nKey) & 0x8000)
	{
		return TRUE;
	}

	return FALSE;
	
}

bool C_KeyMgr::OnceKeyDown(INT nKey)
{
	if (GetAsyncKeyState(nKey) & 0x8000)
	{
		//  눌리는 순간 true
		if (m_bKeyDown[nKey] == false)
		{
			m_bKeyDown[nKey] = true;
			return TRUE;
		}
	}

	else
	{
		//  떼는 순간 false
		m_bKeyDown[nKey] = false;
	}

	return FALSE;
}

bool C_KeyMgr::OnceKeyUp(INT nKey)
{
	if (GetAsyncKeyState(nKey) & 0x8000)
	{
		m_bKeyUp[nKey] = true;
	}

	else
	{
		// 눌려진 순간 true가 되므로 true일때만 진입
		if (m_bKeyUp[nKey] == true)
		{
			//  키상태를 false로 만들어 재진입 불가
			m_bKeyUp[nKey] = false;

			return TRUE;
		}
	}

	return FALSE;
}

bool C_KeyMgr::IsToggleKey(INT nKey)
{
	if (GetKeyState(nKey) & 0x0001) // GetKeyState의 0x0001 은 이전에 눌렸는가 를 체크한다.
	{
		return TRUE;
	}
	return FALSE;
}
