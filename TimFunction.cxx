#include "TimFunction.hxx"
#include <cmath>

#define EPSILON 5.0

void TimFunction::ReadFromStream(fstream &InputStream)
{ 
	InputStream>>A;
	InputStream>>B;
	InputStream>>C;
		if ( A==0 && B==0 && C!=0)
	{
		//Error >_<
	}
}

TimFunction::TimFunction()
{
}

TimFunction::~TimFunction()
{
}

bool TimFunction::Function(float X, float Y)
{
	return fabsf(-A*fabsf(X)+B*Y+C) < EPSILON;
}


void LineFunction::ReadFromStream(fstream &InputStream)
{ 
	InputStream>>A;
	InputStream>>B;
	InputStream>>C;
	InputStream>>Color;
}

LineFunction::LineFunction()
{
	A = 1;
	B = 2;
	C = 0;
}

LineFunction::~LineFunction()
{
}

bool LineFunction::Function(float X, float Y)
{
 	return A*X+B*Y+C <= 5;
}

