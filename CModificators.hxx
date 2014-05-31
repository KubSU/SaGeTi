#ifndef _MODIFICATORS_H
#define _MODIFICATORS_H

#include "IModificator.hxx"
#include <cmath>

class CMoveRightModificator : public IModificator
{
public:
	CMoveRightModificator()
	{
		_Param = 0;
	};

	~CMoveRightModificator();
	
	float GetTransformX(float x, float y) 
	{
		return x + _Param;
	};
};

class CMoveUpModificator : public IModificator
{
public:
	CMoveUpModificator()
	{
		_Param = 0;
	};

	~CMoveUpModificator();
	
	float GetTransformY(float x, float y) 
	{
		return y + _Param;
	};
};

class CStretchXModificator : public IModificator
{
public:
	CStretchXModificator()
	{
		_Param = 1;
	};

	~CStretchXModificator();
	
	float GetTransformX(float x, float y) 
	{
		return x * _Param;
	};
};

class CStretchYModificator : public IModificator
{
public:
	CStretchYModificator()
	{
		_Param = 1;
	};

	~CStretchYModificator();
	
	float GetTransformY(float x, float y) 
	{
		return y * _Param;
	};
};

class CRotationModificator : public IModificator
{
public:
	CRotationModificator()
	{
		_Param = 0;
	};

	~CRotationModificator();
	
	float GetTransformX(float x, float y) 
	{
		return x * cosf(_Param) - y * sinf(_Param);
	};

	float GetTransformY(float x, float y) 
	{
		return y * cosf(_Param) + x * sinf(_Param);
	};
};


#endif