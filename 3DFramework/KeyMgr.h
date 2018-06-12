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
	bool        StayKeyDown(INT nKey);// 키가 눌리고 있는지 체크
	bool        OnceKeyDown(INT nKey);// 키가 한번 눌렸는지 체크
	bool        OnceKeyUp(INT nKey);  // 키가 한번 눌렸다 떼졌는지 체크
	bool        IsToggleKey(INT nKey);// 한번 눌릴때마다 on off로 바뀜
};
