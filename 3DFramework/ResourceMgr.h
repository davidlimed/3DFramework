#pragma once
#include "stdafx.h"
#include "Macro.h"
#include "Structs.h"

class C_ResourceMgr
{
DeclareSingleton(C_ResourceMgr)
public:
	enum E_TEXID {ePlayer};

private:
	typedef map<wstring, vector<LPDIRECT3DTEXTURE9>>::value_type ValueType;

private:
	S_TextureInfo * m_pTexInfo;
	map<E_TEXID, vector<LPDIRECT3DTEXTURE9>> m_mapTextureContainer;
	map<E_TEXID, vector<LPDIRECT3DTEXTURE9>>::iterator m_SearchItor;

private:
	C_ResourceMgr();
public:
	~C_ResourceMgr();

public:
	void AddTexture(E_TEXID eID,const wstring &FilePath, const wstring &FileName, UINT nCount = 0);
	void AddMesh() {}
	void AddBuffer() {}

public:
	vector<LPDIRECT3DTEXTURE9> GetTextureVector(E_TEXID eID);
	
};