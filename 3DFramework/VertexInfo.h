#pragma once
#include "stdafx.h"

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
};
