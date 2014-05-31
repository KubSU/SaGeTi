#include "CGraph.hxx"

#define UNUSIFUL_EDGE 20

CGraph::CGraph(){
	
};
CGraph::~CGraph(){
	
};
void CGraph::ApplyGraphToAr(int x,int y,TPictureData data,TPictureData olddata){
	for (int i = 0; i < 4; ++i) {
		if (ms[lovely_point][i]!=UNUSIFUL_EDGE) {
			data[x+sm[i][0]][y+sm[i][1]] = (olddata[x][y]+olddata[x+sm[i][0]][y+sm[i][1]]+ms[lovely_point][i]) % 16;
		}
	}
};

void CGraph::ReadFromFile(std::fstream &Stream){
	
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			Stream >> ms[i][j];
		}
	}
	
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			Stream >> mr[i][j];
		}
	}
	
	Stream >> lovely_point;
	
	for (int i = 0; i<4; ++i) {
		int j;
		for (j = 0; j < 4; ++j) {
			if (mr[i][j]==lovely_point) {
				lovely_point_x = i;
				lovely_point_y = j;
			}
		}
		if (j<4) {
			break;
		}
	}
	
	for (int i = 0; i<4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (mr[i][j]!=0) {
				sm[mr[i][j]-1][0] = i - lovely_point_x;
				sm[mr[i][j]-1][1] = j - lovely_point_y;
			}
		}
	}
	
};
