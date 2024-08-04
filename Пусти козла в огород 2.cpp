/*Козла пустили в огород. К несчастью для козла, его крепко-накрепко привязали к точке C крепчайшей альпинистской верёвкой длины L (То есть козёл может кушать травку, удалённую от точки C не более чем на L метров). И только одно скрасило жизнь бедного козла — недалеко от него виднеется грядка так любимых им ананасов, представляющая собой отрезок прямой с концами в точках A и B.
Хм… Интересно, на сколько козлу придётся растянуть крепчайшую альпинистскую верёвку, чтобы добраться хотя бы до одного ананасика? А чтобы съесть все ананасы?
Исходные данные
На входе находятся координаты точек А, B, С и длина верёвки L. Все числа целые, L ≥ 0, все координаты не превосходят по модулю 10000. Числа разделены пробелами или переводами строк.
Результат
В первой строке вывести минимальную длину, на которую козлу придётся растянуть верёвку, чтобы дотянуться до грядки с ананасами. Во второй строке вывести минимальную длину, на которую козлу придётся растянуть верёвку, чтобы добраться до всех ананасов с грядки. Все числа выводить с точностью до 2-х знаков после десятичной точки.*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int Ax, Ay, Bx, By, Cx, Cy;
	float L;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> L;
	pair<int, int> AB, BC, AC, BA;
	float dmin, dmax;
	float minr, maxr;
	BA.first = Ax - Bx;
	BA.second = Ay - By;
	AB.first = Bx - Ax;
	AB.second = By - Ay;
	BC.first = Cx - Bx;
	BC.second = Cy - By;
	AC.first = Cx - Ax;
	AC.second = Cy - Ay;
	float lAB, lBC, lCA;
	lAB = sqrt((Ax - Bx)*(Ax - Bx) + (Ay - By)*(Ay - By));
	lBC = sqrt((Bx - Cx)*(Bx - Cx) + (By - Cy)*(By - Cy));
	lCA = sqrt((Ax - Cx)*(Ax - Cx) + (Ay - Cy)*(Ay - Cy));
	float scal1 = BA.first*BC.first + BC.second*BA.second;
	float scal2 = AB.first*AC.first + AC.second*AB.second;
	if (scal1 >0 && scal2 >0)
	{
		float p = (lAB + lBC + lCA) / 2;
		float S = sqrt(p*(p - lAB)*(p - lBC)*(p - lCA));
		float h = S * 2 / lAB;
		dmin = h;
		dmax = max(lBC, lCA);
	}
	else
	{
		dmin = min(lBC, lCA);
		dmax = max(lBC, lCA);
	}
	if (dmin - L >= 0)
		minr = dmin - L;
	else
		minr = 0;
	if (dmax - L >= 0)
		maxr = dmax - L;
	else
		maxr = 0;
	printf_s("%.2f\n", minr);
	printf_s("%.2f\n", maxr);
}