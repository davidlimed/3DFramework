#pragma once
#include "stdafx.h"
#include "Macro.h"
#include "Texture.h"
#include "Structs.h"

class C_ResourceMgr
{
DeclareSingleton(C_ResourceMgr)
private:
	S_TextureInfo * m_pTexInfo;
	map<wstring, C_Texture* > m_mapTex;
	
private:
	C_ResourceMgr();
public:
	~C_ResourceMgr();

	
};