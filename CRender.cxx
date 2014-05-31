#include "CRender.hxx"
#include "glfw3.h"


struct TPixel{
	GLubyte r,g,b;
	TPixel(){};
	TPixel(char nr, char ng, char nb){r=nr;b=nb;g=ng;}
};

inline TPixel GetColor(char color){
	switch(color){
		case 0:
		return TPixel(0,0,0);
		break;
		case 1:
		return TPixel(0,0,128);
		break;
		case 2:
		return TPixel(0,128,0);
		break;
		case 3:
		return TPixel(0,128,128);
		break;
		case 4:
		return TPixel(128,0,0);
		break;
		case 5:
		return TPixel(128,0,128);
		break;
		case 6:
		return TPixel(128,128,0);
		break;
		case 7:
		return TPixel(128,128,128);
		break;
		case 8:
		return TPixel(64,64,64);
		break;
		case 9:
		return TPixel(0,0,255);
		break;
		case 10:
		return TPixel(0,255,0);
		break;
		case 11:
		return TPixel(0,255,255);
		break;
		case 12:
		return TPixel(255,0,0);
		break;
		case 13:
		return TPixel(255,0,255);
		break;
		case 14:
		return TPixel(255,255,0);
		break;
		case 15:
		return TPixel(255,255,255);
		break;
	}
	return TPixel();
};

CRender::CRender()
{
	
};

CRender::~CRender()
{
	
};

void CRender::DrawPicture(CPicture *pPicture)
{
	TPictureData pd;
	pd = pPicture->GetData();
	TPixel* data = new TPixel[600*600];

	int count = 0;
	for (int i = 0; i < 600; ++i)
		for (int j = 0; j < 600; ++j)
		{
			data[i+(599-j)*600] = GetColor(pd[i][j]);
			if (pd[i][j] != 0 )
			{
				count++;
			} 	
		};
	glDrawPixels(600, 600, GL_RGB, GL_UNSIGNED_BYTE, data);
	glFinish();

	delete []data;
};