#pragma once
#include "stdafx.h"

template<typename T>
void SafeRelease(T * pInstance)
{
	if (!pInstance)
		return;
	
	delete pInstance;
	pInstance = nullptr;
}

class C_Finder
{
public:
	explicit C_Finder(const TCHAR* pTag) : m_pTag(pTag) {}
	~C_Finder(void) {}
public:
	template <typename T> bool operator () (T& Pair)
	{
		int nResult = lstrcmp(m_pTag, Pair.first);

		if (!nResult)
			return true;
		return false;
	}
private:
	const TCHAR*				m_pTag;
};
