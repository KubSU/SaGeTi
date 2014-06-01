#include "CPicture.hxx"
#include "CGraph.hxx"
#include "IModificator.hxx"
#include <cstring>
#include <cmath>
#include <thread>
#include <vector>

#define SIZE 600
#define HALF_SIZE SIZE / 2

CPicture::CPicture()
{
	_NewData = new char*[SIZE];
	for (int i = 0; i < SIZE; i++){
		_NewData[i] = new char[SIZE];
		memset(_NewData[i],0,SIZE);
		};
	
	_OldData = new char*[SIZE];
	for (int i = 0; i < SIZE; i++){
		_OldData[i] = new char[SIZE];
		memset(_OldData[i],0,SIZE);
	};
	
	_AvailableThreads = std::thread::hardware_concurrency();
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

void CPicture::ThreadUpdate(int start, int end)
{
	for (int i = start; i < end; i++)
		for (int j = 0; j < SIZE; j++)
			if (_Function->Function(_Modificator->GetTransformX(i - HALF_SIZE, j - HALF_SIZE),
										  _Modificator->GetTransformY(i - HALF_SIZE, j - HALF_SIZE)))
				_Graph->ApplyGraphToAr(i, j, _NewData, _OldData);
};

void CPicture::Update()
{
	std::vector<thread> threads;
	for (int i = 0; i < _AvailableThreads; i++)
		threads.push_back(std::thread(&CPicture::ThreadUpdate, this, SIZE / _AvailableThreads * i, SIZE / _AvailableThreads * (i + 1)));
	
	for (auto &th : threads)
		th.join();
	
	_SwapDataArrays();
};

void CPicture::ReadBackgroundFunctions(fstream& Stream){
	Stream >> FunctionCount;
	FunctionParameters = new TFunctionParameters[FunctionCount];
	for (int i = 0; i < FunctionCount; i++)
	{
		//============
		Stream >> FunctionParameters[i].x >> FunctionParameters[i].d >> FunctionParameters[i].c;
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
				if ((FunctionParameters2[0].A*sinf(FunctionParameters2[0].r*(i/10.0)-FunctionParameters2[0].phi)>j-550)&&
					(FunctionParameters2[1].A*sinf(FunctionParameters2[1].r*(i/10.0)-FunctionParameters2[1].phi)<j-100)&&
					((i)>FunctionParameters[k].x)&&
					((i)<FunctionParameters[k].x+FunctionParameters[k].d))
					_NewData[i][j] = FunctionParameters[k].c;
	}
	//============
	_SwapDataArrays();
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
