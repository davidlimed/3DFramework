#pragma once


template<typename T>
void SafeRelease(T * pInstance)
{
	if (!pInstance)
		return;
	
	delete pInstance;
	pInstance = nullptr;
}


