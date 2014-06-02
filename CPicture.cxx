#include "CPicture.hxx"
#include "CGraph.hxx"
#include "IModificator.hxx"
#include "TimFunction.hxx"
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
			for (auto mod : _Modificators)
				if (_Function->Function(mod->GetTransformX(i - HALF_SIZE, j - HALF_SIZE),
										mod->GetTransformY(i - HALF_SIZE, j - HALF_SIZE)))
				{
					//_NewData[i][j] = 15;
					_Graph->ApplyGraphToAr(i, j, _NewData, _OldData);
				}
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
	for (int i = 0; i < FunctionCount; i++)
	{
		IBackgroundFunction* temp = new EllipseFunction();
		temp->ReadFromStream(Stream);
		_BackgroundFuncs.push_back(temp);
	}
	
};

void CPicture::_InitBackground()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			for (int k = 0; k < FunctionCount; k++)
				if (_BackgroundFuncs[k]->Function(i, j))
					_NewData[i][j] = _BackgroundFuncs[k]->Color;
	for (auto func : _BackgroundFuncs)
		delete func;
	_BackgroundFuncs.clear();
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
void CPicture::AddModificator(IModificator* Modificator)
{
	_Modificators.push_back(Modificator);
};
