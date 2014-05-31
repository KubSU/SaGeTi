#include "TimFunction.hxx"
#include <cmath>

#define EPSILON 0.6

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
	A = 1;
	B = 1;
	C = 0;
}

TimFunction::~TimFunction()
{
}

bool TimFunction::Function(float X, float Y)
{
	float res = A*fabsf(X)+B*Y+C;
	return fabsf(res) < EPSILON;
}

void SanFunction::ReadFromStream(fstream &InputStream)
{ 
	InputStream>>x0;
	InputStream>>y0;
	InputStream>>A;
	InputStream>>B;
		if ( A==0 || B==0 )
	{
		//Error >_<
	}
}

SanFunction::SanFunction()
{
	A = 100;
	B = 160;
	x0 = 0;
	y0 = 0;
}

SanFunction::~SanFunction()
{
}

bool SanFunction::Function(float X, float Y)
{
	int y = y0+sqrtf(-B*B*(((X-x0)*(X-x0)/(A*A))-1));
	return y==Y;

}

void JorFunction::ReadFromStream(fstream &InputStream)
{ 
	InputStream>>x0;
	InputStream>>y0;
	InputStream>>P;
}

JorFunction::JorFunction()
{
	x0 = 1;
	y0 = 1;
	P = 1;
}

JorFunction::~JorFunction()
{
}

bool JorFunction::Function(float X, float Y)
{
	return fabsf((Y-y0)*(Y-y0)-2*P*(X-x0)) < EPSILON;
	

}