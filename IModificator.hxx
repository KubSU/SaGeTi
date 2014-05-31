#ifndef _MODIFICATOR_H
#define _MODIFICATOR_H

class IModificator
{
protected:
	float _Param;	
public:
	virtual float GetTransformX(float x, float y) 
	{
		return x;
	};

	virtual float GetTransformY(float x, float y) 
	{
		return y;
	};
	
	void ChangeParam(float dParam)
	{
		_Param += dParam;
	};

	virtual ~IModificator(){};
};

#endif