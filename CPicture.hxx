typedef unsigned short int** TPictureData; 

class CPicture
{
public:
	CPicture();
	~CPicture();
	TPictureData GetData();	
};