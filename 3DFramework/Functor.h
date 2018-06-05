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

class CTagFinder
{
public:
	explicit CTagFinder(const TCHAR* pTag) : m_pTag(pTag) {}
	~CTagFinder(void) {}
public:
	template <typename T> bool operator () (T& Pair)
	{
		int iResult = lstrcmp(m_pTag, Pair.first);

		if (0 == iResult)
			return true;
		return false;
	}
private:
	const TCHAR*				m_pTag;
};
