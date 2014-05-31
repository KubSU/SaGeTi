#include <fstream>

using namespace std;

class IFunction
{
public:
	virtual void ReadFromStream(fstream &InputStream) = 0;
	virtual bool Function(float X, float Y) = 0;
};