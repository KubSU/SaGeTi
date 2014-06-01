#ifndef _PICTURE_H
#define _PICTURE_H
#include "IFunction.hxx"
#include "CModificators.hxx"

struct TFunctionParameters {
	//==============
	float x,c;
	int d;
	//==============
};

//==============
struct TFunctionParameters2 {
	
	float A, phi, r;
};
//==============

typedef char** TPictureData;

class CGraph;
class IModificator;

class CPicture
{
private:
	TPictureData _NewData;
	TPictureData _OldData;
	
	IFunction* _Function;
	CGraph* _Graph;
	IModificator* _Modificator1;
	IModificator* _Modificator2;
	
	int _AvailableThreads;
	
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
	void ThreadUpdate(int start, int end);
	void SetFunction(IFunction* Function);
	void SetGraph(CGraph* Graph);
	void ReadBackgroundFunctions(fstream& Stream);
	void SetModificators();
};

#endif
