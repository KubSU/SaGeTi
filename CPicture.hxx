#ifndef _PICTURE_H
#define _PICTURE_H
#include "IFunction.hxx"

typedef char** TPictureData;

class CGraph;

class CPicture
{
private:
	TPictureData _NewData;
	TPictureData _OldData;
	
	IFunction* _Function;
	CGraph* _Graph;
	
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
};

#endif