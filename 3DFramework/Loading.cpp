#include "stdafx.h"
#include "Loading.h"

C_Loading::C_Loading():
	m_bComplete(false),
	m_hThread(nullptr),
	m_CSKey{},
	m_szLoadingMessage(),
	m_eLoadingID()
{
}


C_Loading::~C_Loading()
{
	Release();
}

UINT C_Loading::LoadingFunction(void * pArg)
{
	HRESULT		hr = E_FAIL;
	C_Loading*	pLoading = static_cast<C_Loading*>(pArg);

	//EnterCriticalSection(&pLoading->m_CSKey);

	switch (pLoading->m_eLoadingID)
	{
	case E_LOADING_ID::eLobby:
		hr = pLoading->LobbyLoading();
		break;
	}

	//LeaveCriticalSection(&pLoading->m_CSKey);
	return 0;
}

HRESULT C_Loading::InitLoading()
{
	return S_OK;
}

HRESULT C_Loading::LobbyLoading()
{

	return S_OK;
}

HRESULT C_Loading::StageLoading()
{
	return S_OK;
}

const TCHAR * C_Loading::GetLoadingMessage()
{
	return m_szLoadingMessage;
}

const bool C_Loading::GetComplete()
{
	return m_bComplete;
}

void C_Loading::Release()
{
	WaitForSingleObject(m_hThread, INFINITE);
	CloseHandle(m_hThread);
}
