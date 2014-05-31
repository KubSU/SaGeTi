#ifndef _PICTURE_H
#define _PICTURE_H

typedef char** TPictureData; 

class CPicture
{
private:
	TPictureData _NewData;
	TPictureData _OldData;
	
	void _InitBackground();
	void _SwapDataArrays();
public:
	CPicture();
	~CPicture();
	TPictureData GetData();
	void Update();
};

#endif