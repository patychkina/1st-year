/*Заданы координаты трех вершин прямоугольника. Необходимо определить координаты четвертой вершины.

Входные данные
Во входном файле INPUT.TXT записаны через пробел координаты трех вершин прямоугольника в произвольном порядке в формате x1 y1 x2 y2 x3 y3. Все числа целые, не превосходящие 1000 по абсолютной величине.

Выходные данные
В выходной файл OUTPUT.TXT нужно вывести через пробел координаты четвертой вершины прямоугольника.*/
#include <iostream>
#include <vector>
using namespace std;

bool scalar_prod(pair<int, int> a, pair<int, int> b, pair<int, int> c);

int main()
{
	vector <pair<int, int>> xy(4);
	for (int i = 0; i < 3; i++)
	{
		cin >> xy[i].first >> xy[i].second;
	}
	if (scalar_prod(xy[0],xy[1],xy[2]))
	{
		xy[3].first = xy[2].first + xy[1].first - xy[0].first;
		xy[3].second = xy[2].second + xy[1].second - xy[0].second;
	}
	else
	{
		if (scalar_prod(xy[1],xy[0],xy[2]))
		{
			xy[3].first = xy[0].first + xy[2].first - xy[1].first;
			xy[3].second = xy[0].second + xy[2].second - xy[1].second;
		}
		else
		{
			xy[3].first = xy[0].first + xy[1].first - xy[2].first;
			xy[3].second = xy[0].second + xy[1].second - xy[2].second;
		}
	}
	cout << xy[3].first << ' ' << xy[3].second << endl;
}

bool scalar_prod(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	return ((b.first - a.first)*(c.first - a.first) + (b.second - a.second)*(c.second - a.second)==0);
}