#include "CRender.hxx"
#include "glfw3.h"


struct TPixel{
	char r,g,b;
	TPixel(){};
	TPixel(char nr, char ng, char nb){r=nr;b=nb;g=ng;}
};

inline TPixel GetColor(char color){
	switch(color){
		case 0:
		return TPixel(0,0,0);
		break;
		case 1:
		return TPixel(0,0,0.5);
		break;
		case 2:
		return TPixel(0,0.5,0);
		break;
		case 3:
		return TPixel(0,0.5,0.5);
		break;
		case 4:
		return TPixel(0.5,0,0);
		break;
		case 5:
		return TPixel(0.5,0,0.5);
		break;
		case 6:
		return TPixel(0.5,0.5,0);
		break;
		case 7:
		return TPixel(0.5,0.5,0.5);
		break;
		case 8:
		return TPixel(0.25,0.25,0.25);
		break;
		case 9:
		return TPixel(0,0,1);
		break;
		case 10:
		return TPixel(0,1,0);
		break;
		case 11:
		return TPixel(0,1,1);
		break;
		case 12:
		return TPixel(1,0,0);
		break;
		case 13:
		return TPixel(1,0,1);
		break;
		case 14:
		return TPixel(1,1,0);
		break;
		case 15:
		return TPixel(1,1,1);
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

	for (int i = 0; i < 600; ++i)
		for (int j = 0; j < 600; ++j)
			{
				data[i*600+j] = GetColor(pd[i][j]);
			};

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	 
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, 600, 600, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glTexCoord2f(0,0);
	glVertex3f(0,0,0);
	glTexCoord2f(0,1);
	glVertex3f(0,1,0);
	glTexCoord2f(1,1);
	glVertex3f(1,1,0);
	glTexCoord2f(1,0);
	glVertex3f(1,0,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDeleteTextures(1,&textureID);

	delete []data;

};