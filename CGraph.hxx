#ifndef _GRAPH_H
#define _GRAPH_H

#include <fstream>

typedef char** TPictureData;

/*!
 * @brief Представляет граф.
 */
class CGraph {
	int** ms;
	int mr[4][4];
	int lovely_point;
	int sm[4][2];
	int lovely_point_x;
	int lovely_point_y;
	int size;
public:
	/// Конструктор
	CGraph();
	/// Деструктор
	~CGraph();
	/*!
	 * @brief Применяет граф к рисунку.
	 * @param x       X координата применения
	 * @param y       Y координата применения
	 * @param data    Изменяемый рисунок.
	 * @param olddata Старый рисунок.
	 */
	void ApplyGraphToAr(int x,int y,TPictureData data, TPictureData olddata);
	/*!
	 * @brief Считывает граф из потока.
	 * @param Stream Поток ввода.
	 */
	void ReadFromFile(std::fstream &Stream);
};
#endif
