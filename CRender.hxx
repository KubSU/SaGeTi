#ifndef _RENDER_H
#define _RENDER_H

#include "CPicture.hxx"

struct TPixel{
	char r,g,b;
	TPixel(){};
	TPixel(char nr, char ng, char nb){r=nr;b=nb;g=ng;}
};

/// Класс отрисовщика.
class CRender
{
private:
	int _AvailableThreads;
	void _ThreadUpdate(TPixel* data, TPictureData picture, int start, int end);
public:
	/// Конструктор
	CRender();
	/// Деструктор
	~CRender();
	/*!
	 * Отрисовывает изображение.
	 * @param pPicture Объект изображения.
	 */
	void DrawPicture(CPicture *pPicture);
};

#endif