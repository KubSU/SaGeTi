#include "CGraph.hxx"

#define UNUSIFUL_EDGE 20

CGraph::CGraph(){
	
};
CGraph::~CGraph(){
	for (int i = 0; i < size; i++)
		delete [] ms[i];
	delete [] ms;
};
void CGraph::ApplyGraphToAr(int x,int y,TPictureData data,TPictureData olddata){
	for (int i = 0; i < 4; ++i) {
		int X = x+sm[i][0];
		int Y = y+sm[i][1];
		
		if ((ms[lovely_point-1][i]!=UNUSIFUL_EDGE)&&(Y>=0)&&(Y<600)&&(X>=0)&&(X<600)) {
			data[X][Y] = (olddata[x][y]+olddata[X][Y]+ms[lovely_point-1][i]) % 16;
		}
	}
};

void CGraph::ReadFromFile(std::fstream &Stream){
	
	// Getting length
	char temp[256];
	size = 0;
	Stream.getline(temp, 256, '\n');
	for (int i = 0; temp[i] != 0; i++)
		if (temp[i] == ' ')
			size++;
	size++;
	Stream.seekg(0);

	ms = new int*[size];
	for (int i = 0; i < size; ++i) {
		ms[i] = new int[size];
		for (int j = 0; j < size; ++j) {
			char t;
			Stream >> t;
			if (t == '-')
			{
				Stream.ignore();
				ms[i][j] = UNUSIFUL_EDGE;
			} 
			else 
			{
				Stream.seekg(Stream.tellg() - (std::streampos)1);
				Stream >> ms[i][j];
			}
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
