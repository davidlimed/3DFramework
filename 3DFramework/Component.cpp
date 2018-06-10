#include "stdafx.h"
#include "Component.h"

C_Component::C_Component():
	m_uRefCnt(1)
{
}

C_Component::~C_Component()
{
}

C_Component * C_Component::GetCloneComponent()
{
	return nullptr;
}

void C_Component::AddRefCnt()
{
	++m_uRefCnt;
}
