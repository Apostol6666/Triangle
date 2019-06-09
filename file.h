#ifndef _FILE_H
#define _FILE_H

struct Point {
	double x, y;
};

struct Triangle {
	Point vertexes[3];
	double area;
};

// Подсчет числа точек во входном файле
int countPoints(const char* fileName);
// Чтение точек из входного файла
bool readPoints(const char* fileName, Point* pointArray, int maxPointNum);
// Вывод треугольников в выходной файл
bool writeTriangles(const char* fileName, const Triangle* trArray, int trNum);

void findAndInsert(Triangle* trArray, int length, const Triangle& triangle);

double calcAreaBySides(double a, double b, double c);

double calcTriangleArea(Triangle& tr);

double calcDistance(const Point& pa, const Point& pb);

void clearPoint(Point& p);

void clearTriangle(Triangle& tr);

#endif
