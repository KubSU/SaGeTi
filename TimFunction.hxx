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

class LineFunction : public IBackgroundFunction
{
public:
	LineFunction();
 	~LineFunction();
	void ReadFromStream(fstream &InputStream);
	bool Function(float X, float Y);
private:
	float A,B,C; 

};


