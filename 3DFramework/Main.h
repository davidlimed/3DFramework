#pragma once

#include "stdafx.h"

class C_Main
{
public:
	C_Main();
	~C_Main();
public:
	C_Main(const C_Main&) = delete;
	void operator=(const C_Main&) = delete;

	
public:
	HRESULT Awake();
	HRESULT Init();
	
	VOID	Update();
	VOID	LastUpdate();
	
	VOID	Render();
	VOID	LastRender();

public:
	VOID	Release();

};