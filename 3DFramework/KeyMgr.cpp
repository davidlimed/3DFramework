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
		//  ������ ���� true
		if (m_bKeyDown[nKey] == false)
		{
			m_bKeyDown[nKey] = true;
			return TRUE;
		}
	}

	else
	{
		//  ���� ���� false
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
		// ������ ���� true�� �ǹǷ� true�϶��� ����
		if (m_bKeyUp[nKey] == true)
		{
			//  Ű���¸� false�� ����� ������ �Ұ�
			m_bKeyUp[nKey] = false;

			return TRUE;
		}
	}

	return FALSE;
}

bool C_KeyMgr::IsToggleKey(INT nKey)
{
	if (GetKeyState(nKey) & 0x0001) // GetKeyState�� 0x0001 �� ������ ���ȴ°� �� üũ�Ѵ�.
	{
		return TRUE;
	}
	return FALSE;
}
