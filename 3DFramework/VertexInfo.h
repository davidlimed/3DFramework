#pragma once
#include "stdafx.h"

struct S_VertexXYZ
{
	float fX;
	float fY;
	float fZ;

	DWORD dwColor;
public:
	void operator+(const S_VertexXYZ&)
	{
		fX += S_VertexXYZ().fX;
		fY += S_VertexXYZ().fY;
		fZ += S_VertexXYZ().fZ;

		dwColor += S_VertexXYZ().dwColor;
	}

	void operator=(const S_VertexXYZ&)
	{
		fX = S_VertexXYZ().fX;
		fY = S_VertexXYZ().fY;
		fZ = S_VertexXYZ().fZ;

		dwColor = S_VertexXYZ().dwColor;
	}
	
	void operator-(const S_VertexXYZ&)
	{
		fX -= S_VertexXYZ().fX;
		fY -= S_VertexXYZ().fY;
		fZ -= S_VertexXYZ().fZ;

		dwColor -= S_VertexXYZ().dwColor;
	}
};

struct S_VertexNormal
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vNormal;

	void operator=(const S_VertexNormal&)
	{
		vPos = S_VertexNormal().vPos;
		vNormal = S_VertexNormal().vNormal;
	}
};

struct S_VertexColor
{
	float fX;
	float fY;
	float fZ;
	float frhw;
	
	DWORD dwColor;

public:
	void operator+(const S_VertexColor&)
	{
		fX += S_VertexColor().fX;
		fY += S_VertexColor().fY;
		fZ += S_VertexColor().fZ;

		dwColor += S_VertexColor().dwColor;
	}

	void operator=(const S_VertexColor&)
	{
		fX = S_VertexColor().fX;
		fY = S_VertexColor().fY;
		fZ = S_VertexColor().fZ;

		dwColor = S_VertexColor().dwColor;
	}

	void operator-(const S_VertexColor&)
	{
		fX -= S_VertexColor().fX;
		fY -= S_VertexColor().fY;
		fZ -= S_VertexColor().fZ;

		dwColor -= S_VertexColor().dwColor;
	}
};
