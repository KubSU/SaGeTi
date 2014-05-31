#include "TimFunction.hxx"
#include <cmath>

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

bool TimFunction::Function(float X, float Y)
{
	return fabsf(A*fabsf(X)+B*Y+C)<0.06;
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

bool SanFunction::Function(float X, float Y)
{
	return fabsf((X-x0)*(X-x0)/(A*A)+(Y-y0)*(Y-y0)/(B*B))<1.06;

}

void JorFunction::ReadFromStream(fstream &InputStream)
{ 
	InputStream>>x0;
	InputStream>>y0;
	InputStream>>P;
}

bool JorFunction::Function(float X, float Y)
{
	return fabsf((Y-y0)*(Y-y0)-2*P*(X-x0))<0.06;
	

}