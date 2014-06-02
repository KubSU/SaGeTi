#ifndef _PICTURE_H
#define _PICTURE_H
#include "IFunction.hxx"
#include <vector>


struct TFunctionParameters {
	float x0, y0, A, B;
	int color;
};

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
	std::vector<IModificator*> _Modificators;
	
	int _AvailableThreads;
	
	int FunctionCount;
	std::vector<IBackgroundFunction*> _BackgroundFuncs;
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
	void AddModificator(IModificator* Modificator);
};

#endif
