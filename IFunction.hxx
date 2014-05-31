#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <fstream>

using namespace std;

class IFunction
{
public:
	virtual void ReadFromStream(fstream &InputStream) = 0;
	virtual bool Function(float X, float Y) = 0;
};
#endif