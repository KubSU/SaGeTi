#ifndef _GRAPH_H
#define _GRAPH_H

#include <fstream>

typedef char** TPictureData;

class CGraph {
	int** ms;
	int mr[4][4];
	int lovely_point;
	int sm[4][2];
	int lovely_point_x;
	int lovely_point_y;
	int size;
public:
	CGraph();
	~CGraph();
	void ApplyGraphToAr(int x,int y,TPictureData data, TPictureData olddata);
	void ReadFromFile(std::fstream &Stream);
};
#endif
