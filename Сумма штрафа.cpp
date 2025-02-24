/*Новый градоначальник города Глупова решил с целью пополнения бюджета и экономии горючего провести кампанию борьбы с левым уклоном и левыми рейсами. Для этого он запретил водителям выполнять левые повороты, установив штраф за каждый поворот налево в размере одного миллиона (разворот поворотом налево не считается).

От тяжелого прошлого Глупову достались улицы, которые могут пересекаться под любыми углами. Градоначальник приказал установить компьютерную систему тотальной слежки, которая следит за каждым автомобилем, записывая его координаты каждый раз, когда тот меняет направление движения (включая начальную и конечную точки пути).

Требуется написать программу, вычисляющую по записанной последовательности координат автомобиля штраф, который должен быть взыскан с водителя.

Входные данные
В первой строке вводится целое число N - количество записанных пар координат (1 <= N <= 1000). В каждой из следующих N строк записана очередная из этих пар (вещественные числа).

Выходные данные
Выведите суммарный штраф водителя в миллионах. */
#include <iostream>
#include <vector>
using namespace std;

float vector_prod(pair <float, float> a, pair<float, float> b)
{
	return a.first*b.second - a.second*b.first;
}

int main()
{
	int N;
	int count_fine = 0;
	cin >> N;
	vector <pair<float, float>> xy(N);
	for (int i = 0; i < N; i++)
		cin >> xy[i].first >> xy[i].second;
	for (int i = 2; i < N; i++)
	{
		pair<float, float> xy1, xy2, xy3;
		xy1 = xy[i - 2];
		xy2 = xy[i - 1];
		xy3 = xy[i];
		if ((vector_prod(xy1, xy3) + vector_prod(xy2, xy1) + vector_prod(xy3, xy2)) < 0)
			count_fine++;
	}
	cout << count_fine << endl;
}