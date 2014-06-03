#ifndef _PICTURE_H
#define _PICTURE_H
#include "IFunction.hxx"
#include <vector>


struct TFunctionParameters {
	float x0, y0, A, B;
	int color;
};

typedef char** TPictureData;

class CGraph;
class IModificator;

/*!
 * @brief Класс изображения.
 * @detail В нем происходит перерасчет изображения.
 */
class CPicture
{
private:
	TPictureData _NewData;
	TPictureData _OldData;
	
	IFunction* _Function;
	CGraph* _Graph;
	std::vector<IModificator*> _Modificators;
	
	int _AvailableThreads;
	
	int FunctionCount;
	std::vector<IBackgroundFunction*> _BackgroundFuncs;
	void _InitBackground();
	void _SwapDataArrays();
public:
	/// Конструктор
	CPicture();
	/// Деструктор
	~CPicture();
	/// Метод инициализации.
	void Init();
	/// Возвращает расчитанное изображение.
	TPictureData GetData();
	/*!
	 * @brief Перерасчитывает изображение.
	 *
	 * Создает n потоков ThreadUpdate() где n - количество ядер процессора.
	 */
	void Update();
	/*!
	 * @brief Перерасчитывает часть изображения
	 * @param start Начальная координата.
	 * @param end   Конечная координата.
	 */
	void ThreadUpdate(int start, int end);
	/*!
	 * @brief Устанавливает функцию расчета.
	 * @param Function Объект функции.
	 */
	void SetFunction(IFunction* Function);
	/*!
	 * @brief Задает граф для расчета.
	 * @param Graph Объект графа.
	 */
	void SetGraph(CGraph* Graph);
	/*!
	 * @brief Считывает функции задающие фон.
	 * @param Stream Поток ввода.
	 */
	void ReadBackgroundFunctions(fstream& Stream);
	/*!
	 * @brief Добавляет модификатор, используемый при перерасчете.
	 * @param Modificator Объект модификатора.
	 */
	void AddModificator(IModificator* Modificator);
};

#endif
