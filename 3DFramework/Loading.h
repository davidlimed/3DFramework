#pragma once
#include "stdafx.h"
#include "Macro.h"

class C_Loading
{
CreateBen(C_Loading)

public:
	enum E_LOADING_ID {eLobby, eStage1, eStage2};

private:
	CRITICAL_SECTION m_CSKey;
	HANDLE			 m_hThread;

private:
	E_LOADING_ID	m_eLoadingID;
	TCHAR			m_szLoadingMessage[128];
	bool			m_bComplete;


public:
	explicit C_Loading();
	~C_Loading();

public:
	static UINT WINAPI LoadingFunction(void* pArg);

public:
	HRESULT InitLoading();
	HRESULT LobbyLoading();
	HRESULT StageLoading();

public:
	const TCHAR * GetLoadingMessage();
	const bool GetComplete();

private:
	void Release();
};