#include "CPicture.hxx"

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
	
};

void CPicture::_InitBackground()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (_Function->Function(i - HALF_SIZE, j - HALF_SIZE))
				_NewData[i][j] = 15;
			else
				_NewData[i][j] = 0;
	
	_SwapDataArrays();
};

void CPicture::_SwapDataArrays()
{
	TPictureData temp = _OldData;
	_OldData = _NewData;
	_NewData = temp;
};

void CPicture::SetFunction(IFunction *Function)
{
	_Function = Function;
}
