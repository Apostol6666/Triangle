#include "file.h"
#include <fstream>
#include <math.h>
using namespace std;

int countPoints(const char* fileName)
{
	ifstream in(fileName);
	if (!in.is_open()) return -1;
	double x, y;
	int i;
	for (i = 0; ; i++)
	{
		in >> x >> y;
		if (in.fail()) break;
	}
	return i;
}

bool readPoints(const char* fileName, Point* pointArray, int maxPointNum)
{
	ifstream in(fileName);
	// Файл не открыт
	if (!in.is_open()) return -1;

	for (int i = 0; i < maxPointNum; i++)
	{
		in >> pointArray[i].x;
		in >> pointArray[i].y;
		if (in.fail())
			return false;
	}
	return true;
}

bool writeTriangles(const char* fileName, const Triangle* trArray, int trNum)
{
	ofstream out(fileName);
	if (!out.is_open())
		return false;
	for (int i = 0; i < trNum; i++) {
		out << "#" << i + 1 << ": " << trArray[i].area << endl; 
		for (int j = 0; j < trNum; j++) {
			out << "(" << trArray[i].vertexes[j].x << ";" << trArray[i].vertexes[j].y << ") " << endl;
		}
	}
	return true;
}
