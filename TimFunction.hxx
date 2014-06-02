#include "IFunction.hxx"

class EllipseFunction : public IBackgroundFunction
{
public:
	EllipseFunction();
	~EllipseFunction();
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

