#pragma once
#include "stdafx.h"

struct S_VertexXYZ
{
	float fX;
	float fY;
	float fZ;

	DWORD dwColor;
};

struct S_VertexNormal
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vNormal;
};

struct S_VertexTex
{
	D3DXVECTOR3 vPos;
	DWORD		dwColor;
	float		fU, fV;
};

struct S_VertexNorTex
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vNormal;
	float		fU, fV;
};

struct S_VertexColor
{
	float fX;
	float fY;
	float fZ;
	float frhw;
	
	DWORD dwColor;
};
