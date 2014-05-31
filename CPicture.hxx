#ifndef _PICTURE_H
#define _PICTURE_H

typedef char** TPictureData; 

class CPicture
{
public:
	CPicture();
	~CPicture();
	TPictureData GetData();	
};

#endif