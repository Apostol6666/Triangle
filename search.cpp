#include <iostream>
#include <math.h>
#include "file.h"

double calcDistance(const Point& pa, const Point& pb)
// const указывает, что содержимое не будет меняться
{
	return sqrt((pb.x - pa.x)*(pb.x - pa.x) +
		(pb.y - pa.y)*(pb.y - pa.y));
}

double calcTriangleArea(Triangle& tr)
{
	Point* v = tr.vertexes;
	double a = calcDistance(v[0], v[1]);
	double b = calcDistance(v[1], v[2]);
	double c = calcDistance(v[2], v[0]);
	return tr.area = calcAreaBySides(a, b, c);
}

double calcAreaBySides(double a, double b, double c)
{
	double p2 = (a + b + c) / 2.0;
	// Не забываем проверить, что корень извлечется
	if (p2 <= 0.0 || p2 <= a || p2 <= b || p2 <= c)
		return 0.0;
	return sqrt(p2*(p2 - a)*(p2 - b)*(p2 - c));
}

void findAndInsert(Triangle* trArray, int length, const Triangle& triangle)
{
	int pos;
	for (pos = length - 1; pos >= 0; pos--)
	{
		if (triangle.area <= trArray[pos].area)
			break;
	}
	pos++;
	if (pos == length)
		return;
	for (int m = length - 2; m >= pos; m--)
		trArray[m + 1] = trArray[m];
	    trArray[pos].area = triangle.area;
		for (int i = 0; i < 3; i++) {
			trArray[pos].vertexes[i] = triangle.vertexes[i];
		}
}

void searchLargestTriangles(const Point* pointArray, int pointNum, Triangle* trArray, int maxTrNum)
{
	if (maxTrNum <= 0)
		return;
	// Очистка треугольников
	for (int i = 0; i < maxTrNum; i++)
		clearTriangle(trArray[i]);

	Triangle triangle;
	// Перебор троек точек
	for (int i = 0; i < pointNum; i++)
	{
		triangle.vertexes[0] = pointArray[i];
		for (int j = i + 1; j < pointNum; j++)
		{
			triangle.vertexes[1] = pointArray[j];
			for (int k = j + 1; k < pointNum; k++)
			{
				triangle.vertexes[2] = pointArray[k];
				calcTriangleArea(triangle);
				findAndInsert(trArray, maxTrNum, triangle);
			}
		}
	}
}

void clearPoint(Point& p)
{
	p.x = p.y = 0.0;
}
void clearTriangle(Triangle& tr)
{
	for (int i = 0; i < 3; i++)
		clearPoint(tr.vertexes[i]);
	tr.area = 0.0;
}
