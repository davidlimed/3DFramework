#pragma once
#include "stdafx.h"
#include "Macro.h"

class C_MainCamera
{
CreateBen(C_MainCamera)
//View Matrix Element
private:
	D3DXMATRIX		m_matView;
	D3DXVECTOR3		m_vecPos;
	D3DXVECTOR3		m_vecAt;
	D3DXVECTOR3		m_vecUp;

//Projection Matrix Element
private:
	D3DXMATRIX		m_matProj;
	float			m_fFovY;
	float			m_fAspect;
	float			m_fNear;
	float			m_fFar;

private:
	float	m_fTime;
	float	m_fRunningTime;
	float	m_fInterval;
	float	m_fMovingSpeed;
	bool	m_bisVibration;

public:
	C_MainCamera();
	~C_MainCamera();

public:
	HRESULT Init();
	void Update();
	void Release();

public:
	void Vibration();

public:
	void SetInterval(float Interval);
	void SetTime(float time);

public:
	void SetTarget(D3DXVECTOR3 vecTargetPos);
	void SetPos(D3DXVECTOR3 vecEye);
	void SetUp(D3DXVECTOR3 vecUp);
	void SetViewElement(D3DXVECTOR3 Eye, D3DXVECTOR3 Up, D3DXVECTOR3 At);

public:
	void SetProjectionElement(float Fov, float Aspect, float Near, float Far);
	void SetFovY(float Fov);
	void SetAspect(float Aspect);
	void SetNear(float Near);
	void SetFar(float Far);
};