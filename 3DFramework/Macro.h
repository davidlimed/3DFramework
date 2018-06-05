#pragma once

#define DeclareSingleton(ClassName)			\
private:									\
	static ClassName* m_pInstance;			\
public:										\
	static ClassName* GetInstance()			\
	{										\
	if(!m_pInstance)						\
	m_pInstance = new ClassName;			\
	return m_pInstance;						\
	}										\
	void Release()							\
	{										\
	if(m_pInstance)							\
		{									\
		delete m_pInstance;					\
		m_pInstance = nullptr;				\
		}									\
	}										

#define	ImplementSingleton(ClassName)					\
			ClassName* ClassName::m_pInstance = nullptr;

#define GraphicDevice	C_Device::GetInstance()->GetDevice()

#define Sprite(DeviceClass)					\
			DeviceClass::GetInstance()->GetSprite();

#define Font(DeviceClass)					\
			DeviceClass::GetInstance()->GetFont();

