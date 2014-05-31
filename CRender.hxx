#ifndef _RENDER_H
#define _RENDER_H

#include "CPicture.hxx"

class CRender
{
public:
	CRender();
	~CRender();

	void DrawPicture(CPicture *pPicture);
};

#endif