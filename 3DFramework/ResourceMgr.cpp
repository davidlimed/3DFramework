#include "stdafx.h"
#include "ResourceMgr.h"
#include "Device.h"

ImplementSingleton(C_ResourceMgr)

C_ResourceMgr::C_ResourceMgr()
{
}

C_ResourceMgr::~C_ResourceMgr()
{
	Release();
}

void C_ResourceMgr::AddTexture(E_TEXID eID, const wstring & FilePath, const wstring & FileName, UINT nCount)
{
	if (nCount)
	{
		for (UINT i = 0; i < nCount; i++)
		{
			LPDIRECT3DTEXTURE9 pTexture = nullptr;
			TCHAR Path[256] = L"";
			wstring wsConvert = FilePath + FileName;

			wsprintf(Path, wsConvert.c_str(), i);

			if (FAILED(D3DXCreateTextureFromFile(Device, Path, &pTexture)))
			{

				MsgBox(L"Path Err");
				return;
			}

			m_SearchItor = m_mapTextureContainer.find(eID);

			if (m_SearchItor == m_mapTextureContainer.end())
			{
				m_mapTextureContainer[eID] = vector<LPDIRECT3DTEXTURE9>();
			}

			m_mapTextureContainer[eID].push_back(pTexture);
		}

		return;
	}

	LPDIRECT3DTEXTURE9 pTexture = nullptr;
	TCHAR Path[256] = L"";
	wstring wsConvert = FilePath + FileName;

	wsprintf(Path, wsConvert.c_str());

	if (FAILED(D3DXCreateTextureFromFile(Device, Path, &pTexture)))
	{

		MsgBox(L"Path Err");
		return;
	}

	m_SearchItor = m_mapTextureContainer.find(eID);

	if (m_SearchItor == m_mapTextureContainer.end())
	{
		m_mapTextureContainer[eID] = vector<LPDIRECT3DTEXTURE9>();
	}

	m_mapTextureContainer[eID].push_back(pTexture);
}

vector<LPDIRECT3DTEXTURE9> C_ResourceMgr::GetTextureVector(E_TEXID eID)
{
	return m_mapTextureContainer[eID];
}
