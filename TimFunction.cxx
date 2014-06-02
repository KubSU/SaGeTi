#include "TimFunction.hxx"
#include <cmath>

#define EPSILON 1.5

void EllipseFunction::ReadFromStream(fstream &InputStream)
{ 
	InputStream>>x0;
	InputStream>>y0;
	InputStream>>A;
	InputStream>>B;
	InputStream>>Color;
}

EllipseFunction::EllipseFunction()
{
	A = 150;
	B = 200;
	x0 = 0;
	y0 = 0;
}

EllipseFunction::~EllipseFunction()
{
}

bool EllipseFunction::Function(float X, float Y)
{
	float temp = pow(X - x0, 2) / (A * A) + pow(Y - y0, 2) / (B * B);
	return temp <= 1;
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
	return fabsf(sqrtf(2*P*(X-x0))-Y+y0) < EPSILON || fabsf(-sqrtf(2*P*(X-x0))-Y+y0) < EPSILON ||
		   fabsf(pow(Y - y0, 2) * 0.5 / P + x0 - X) < EPSILON;
	//return fabsf(pow(Y - y0, 2) - 2 * P * (X - x0)) < P;
}
