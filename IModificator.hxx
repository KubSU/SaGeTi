#ifndef _MODIFICATOR_H
#define _MODIFICATOR_H
/*!
 * @brief Интерфейс модификатора.
 * @details Используется для трансформации графика функции.
 */
class IModificator
{
protected:
	float _Param;	
public:
	/// Возвращает трансформацию по X.
	virtual float GetTransformX(float x, float y) 
	{
		return x;
	};

	/// Возвращает трансформацию по Y.
	virtual float GetTransformY(float x, float y) 
	{
		return y;
	};
	
	/// Изменяет трансформацию на приращение.
	void ChangeParam(float dParam)
	{
		_Param += dParam;
	};
	/// Деструктор
	virtual ~IModificator(){};
};

#endif