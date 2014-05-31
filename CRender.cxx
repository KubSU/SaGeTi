#include "CRender.hxx"
#include "glfw3.h"


struct TPixel{
	char r,g,b;
};


void CRender::DrawPicture(CPicture *pPicture)
{
	TPictureData pd;
	pd = pPicture->GetData();
	TPixel* data = new TPixel[600*600];

	for (int i = 0; i < 600*600; ++i)
	{
		data[i] = 
	}


	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	 
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, 600, 600, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	delete []data;

	glDeleteTextures(1,&textureID);

};