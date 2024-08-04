/*В дощечке в один ряд вбиты гвоздики. Любые два гвоздика можно соединить ниточкой. 
Требуется соединить некоторые пары гвоздиков ниточками так, чтобы к каждому гвоздику была привязана хотя бы одна ниточка, 
а суммарная длина всех ниточек была минимальна.

Входные данные
В первой строке входных данных записано число N
 — количество гвоздиков (2≤N≤100). В следующей строке заданы N
 чисел — координаты всех гвоздиков (неотрицательные целые числа, не превосходящие 10000).

Выходные данные
Выведите единственное число — минимальную суммарную длину всех ниточек.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector <int> nails(N);
	vector <int> nails_count(N);
	for (int i = 0; i < N; i++)
		cin >> nails[i];
	sort(nails.begin(), nails.end());
	nails_count[1] = nails[1] - nails[0];
	if (N == 3)
		nails_count[2] = (nails[1] - nails[0]) + (nails[2] - nails[1]);
	if (N == 4)
		nails_count[3] = (nails[1] - nails[0]) + (nails[3] - nails[2]);
	if (N > 4)
	{
		for (int i = 2; i < N - 1; i++)
		{
			if (i == 2)
				nails_count[i] = (nails[1] - nails[0]) + (nails[2] - nails[1]);
			else
				nails_count[i] = min(nails_count[i - 1] - nails[i - 1] + nails[i], nails_count[i - 2] - nails[i - 1] + nails[i]);
		}
		nails_count[N - 1] = min(nails_count[N - 3], nails_count[N - 2]) + (nails[N - 1] - nails[N - 2]);
	}
	cout << nails_count[N - 1] << endl;
}