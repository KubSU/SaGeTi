#include "IFunction.hxx"

class TimFunction : public IFunction
{
public:
	TimFunction();
	~TimFunction();
	void ReadFromStream(fstream &InputStream);
	bool Function(float X, float Y);
private:
	float A,B,C; 

};

class SanFunction : public IFunction
{
public:
	SanFunction();
	~SanFunction();
	void ReadFromStream(fstream &InputStream);
	bool Function(float X, float Y);
private:
	float x0,y0,A,B; 

};

class JorFunction : public IFunction
{
public:
	JorFunction();
	~JorFunction();
	void ReadFromStream(fstream &InputStream);
	bool Function(float X, float Y);
private:
	float x0,y0,P; 

};

