#ifndef _PICTURE_H
#define _PICTURE_H
#include "IFunction.hxx"

typedef char** TPictureData; 

class CPicture
{
private:
	TPictureData _NewData;
	TPictureData _OldData;
	
	IFunction* _Function;
	
	
	void _InitBackground();
	void _SwapDataArrays();
public:
	CPicture();
	~CPicture();
	TPictureData GetData();
	void Update();
	void SetFunction(IFunction* Function);
};

#endif