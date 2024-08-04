/*Дано натуральное число N. Необходимо представить его в виде суммы точных кубов, 
содержащей наименьшее число слагаемых. Программа должна вывести это число слагаемых.

Входные данные
Программа получает на вход натуральное число N, не превосходящее 106.

Выходные данные
Программа должна вывести единственное натуральное число.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int N;
	cin >> N;
	vector <int> min_count_cube(N + 1);
	min_count_cube[0] = 0;
	min_count_cube[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		min_count_cube[i] = INT32_MAX;
		for (int j = 1; (j*j*j) <= i; j++)
		{
			min_count_cube[i] = min(min_count_cube[i], min_count_cube[i - (j*j*j)]+1);
		}
	}
	cout << min_count_cube[N] << endl;
}