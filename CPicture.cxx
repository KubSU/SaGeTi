#include "CPicture.hxx"
#include "CGraph.hxx"
#include "IModificator.hxx"
#include <cstring>
#include <cmath>

#define SIZE 600
#define HALF_SIZE SIZE / 2

CPicture::CPicture()
{
	_NewData = new char*[SIZE];
	for (int i = 0; i < SIZE; i++)
		_NewData[i] = new char[SIZE];
	
	_OldData = new char*[SIZE];
	for (int i = 0; i < SIZE; i++)
		_OldData[i] = new char[SIZE];
	
	FunctionParameters = 0;
	FunctionCount = 0;
};

void CPicture::Init()
{
	_InitBackground();
}

CPicture::~CPicture()
{
	for (int i = 0; i < SIZE; i++)
		delete [] _NewData[i];
	delete [] _NewData;
	
	for (int i = 0; i < SIZE; i++)
		delete [] _OldData[i];
	delete [] _OldData;
};

TPictureData CPicture::GetData()
{
	return _OldData;
};

void CPicture::Update()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (_Function->Function(_Modificator->GetTransformX(i - HALF_SIZE, j - HALF_SIZE), _Modificator->GetTransformY(i - HALF_SIZE, j - HALF_SIZE)))
				_Graph->ApplyGraphToAr(i, j, _NewData, _OldData);
	_SwapDataArrays();
};

void CPicture::ReadBackgroundFunctions(fstream& Stream){
	Stream >> FunctionCount;
	FunctionParameters = new TFunctionParameters[FunctionCount];
	for (int i = 0; i < FunctionCount; i++)
	{
		//============
		Stream >> FunctionParameters[i].x;
		Stream >> FunctionParameters[i].d >> FunctionParameters[i].c;
		//============
	}
	//===========
	Stream >> FunctionParameters2[1].A >> FunctionParameters2[1].phi >> FunctionParameters2[1].r;
	Stream >> FunctionParameters2[0].A >> FunctionParameters2[0].phi >> FunctionParameters2[0].r;
	//===========
	
};

void CPicture::_InitBackground()
{
	//============
	for (int k = 0; k < FunctionCount; k++)
	{
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				if ((FunctionParameters2[0].A*sinf(FunctionParameters2[0].r*(j)-FunctionParameters2[0].phi)>i-500)&&
					(FunctionParameters2[1].A*sinf(FunctionParameters2[1].r*(j)-FunctionParameters2[1].phi)<i-400))
					_NewData[i][j] = FunctionParameters[k].c;
	}
	_SwapDataArrays();
	//============
};

void CPicture::_SwapDataArrays()
{
	for (int i = 0; i < SIZE; i++)
		memcpy(_OldData[i], _NewData[i], SIZE);
};

void CPicture::SetFunction(IFunction *Function)
{
	_Function = Function;
};

void CPicture::SetGraph(CGraph* Graph)
{
	_Graph = Graph;
};
void CPicture::SetModificator(IModificator* Modificator)
{
	_Modificator = Modificator;
};
