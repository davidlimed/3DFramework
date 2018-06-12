#pragma once
#define KEY_MGR
#define KEY_MAX 256
#include "stdafx.h"
#include "Macro.h"

class C_KeyMgr
{
DeclareSingleton(C_KeyMgr)
private:
	bool m_bKeyDown[KEY_MAX];
	bool m_bKeyUp[KEY_MAX];

private:
	C_KeyMgr();
public:
	~C_KeyMgr();
	
public:
	bool        StayKeyDown(INT nKey);// Ű�� ������ �ִ��� üũ
	bool        OnceKeyDown(INT nKey);// Ű�� �ѹ� ���ȴ��� üũ
	bool        OnceKeyUp(INT nKey);  // Ű�� �ѹ� ���ȴ� �������� üũ
	bool        IsToggleKey(INT nKey);// �ѹ� ���������� on off�� �ٲ�
};
