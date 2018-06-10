#include "stdafx.h"
#include "UI.h"

C_UI::C_UI()
{
}

C_UI::~C_UI()
{
}

C_Component * C_UI::GetCloneComponent()
{
	AddRefCnt();

	return this;
}

HRESULT C_UI::Init()
{
	return S_OK;
}

void C_UI::Update()
{
}

void C_UI::Release()
{
}
