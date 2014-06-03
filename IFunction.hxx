#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <fstream>

using namespace std;

/// Интерфейс (базовый класс) функции перерасчета.
class IFunction
{
public:
	/// Деструктор (для корректного удаления)
	virtual ~IFunction(){};
	/*!
	 * @brief Считывает из потока.
	 * @param InputStream Поток ввода.
	 */
	virtual void ReadFromStream(fstream &InputStream) = 0;
	/*!
	 * @brief Проверяет, принадлежит ли точка графику.
	 * @param  X Координата X
	 * @param  Y Координата Y
	 * @return   true если принадлежит.
	 */
	virtual bool Function(float X, float Y) = 0;
};

/// Интерфейс функции подложки.
class IBackgroundFunction : public IFunction
{
public:
	/// Цвет функции подложки.
	int Color;
	/// Деструктор.
	virtual ~IBackgroundFunction(){};
};

#endif