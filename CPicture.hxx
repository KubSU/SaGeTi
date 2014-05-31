#ifndef _PICTURE_H
#define _PICTURE_H
#include "IFunction.hxx"


struct TFunctionParameters {
	//==============
	float x,d,c;
	//==============
};

//==============
struct TFunctionParameters2 {
	
	float A, phi, r;
};
//==============

typedef char** TPictureData;

class CGraph;

class CPicture
{
private:
	TPictureData _NewData;
	TPictureData _OldData;
	
	IFunction* _Function;
	CGraph* _Graph;
	
	int FunctionCount;
	TFunctionParameters* FunctionParameters;
	//=============
	TFunctionParameters2 FunctionParameters2[2];
	//=============
	void _InitBackground();
	void _SwapDataArrays();
public:
	CPicture();
	~CPicture();
	void Init();
	TPictureData GetData();
	void Update();
	void SetFunction(IFunction* Function);
	void SetGraph(CGraph* Graph);
	void ReadBackgroundFunctions(fstream& Stream);
};

#endif
