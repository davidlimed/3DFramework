#pragma once

//Singleton create
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

//When make Class, Ben
#define CreateBen(ClassName)							\
			public:										\
				ClassName(const ClassName&) = delete;	\
				void operator=(const ClassName&) = delete;

//When create Class Macro
#define CreateObject(Instance, ClassName)	\
		Instance = new ClassName();			\
		if(FAILED(Instance->Init()))		\
		{									\
			return E_FAIL;					\
		}

//Device Macro
#define GraphicDevice(DeviceClass) DeviceClass::GetInstance()->GetDevice()
#define Sprite(DeviceClass)	DeviceClass::GetInstance()->GetSprite()
#define Font(DeviceClass) DeviceClass::GetInstance()->GetFont()

//GetTime
#define DeltaTime(TimeClass) TimeClass::GetInstance()->GetTime()

//ERR Macro
#define Exception(pPointer, Message) \
			if(!pPointer) \
			{	MessageBox(NULL, Message, L"System Err", MB_OK); return; }

#define MsgBox(UnicodeString)\
			MessageBox(NULL, UnicodeString, L"System Err", MB_OK);


