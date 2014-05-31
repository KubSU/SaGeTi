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
	A = 150;
	B = 200;
	x0 = 0;
	y0 = 0;
}

SanFunction::~SanFunction()
{
}

bool SanFunction::Function(float X, float Y)
{
	
	return 
		((fabsf(-Y+y0+sqrtf(-B*B*(((X-x0)*(X-x0)/(A*A))-1))))<EPSILON)||
		((fabsf(-X+x0+sqrtf(-A*A*(((Y-y0)*(Y-y0)/(B*B))-1))))<EPSILON)||
		((fabsf(-Y+y0-sqrtf(-B*B*(((X-x0)*(X-x0)/(A*A))-1))))<EPSILON)||
		((fabsf(-X+x0-sqrtf(-A*A*(((Y-y0)*(Y-y0)/(B*B))-1))))<EPSILON);

}

void JorFunction::ReadFromStream(fstream &InputStream)
{ 
	InputStream>>x0;
	InputStream>>y0;
	InputStream>>P;
}

JorFunction::JorFunction()
{
	x0 = -50;
	y0 = -50;
	P = 1;
}

JorFunction::~JorFunction()
{
}

bool JorFunction::Function(float X, float Y)
{
	return 
		fabsf(sqrtf(2*P*(X-x0))-Y+y0)<EPSILON||
		fabsf(-sqrtf(2*P*(X-x0))-Y+y0)<EPSILON;

}
