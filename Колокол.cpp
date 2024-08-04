/*Требуется написать программу, которая в массиве из n целых чисел наименьший элемент поместит на первое место,
 наименьший из оставшихся – на последнее, следующий по величине – на второе место, следующий – на предпоследнее
  и так далее – до середины массива.

Входные данные
Во входном файле INPUT.TXT записано в первой строке число n (1 ≤ n ≤ 30000). 
Во второй строке записаны через пробел элементы массива, числа по абсолютной величине не большие 32767.

Выходные данные
В единственную строку выходного файла OUTPUT.TXT нужно вывести элементы полученного массива, 
разделенные одним пробелом.
*/

#include <iostream>
using namespace std;

void qsort(int *arr, int size) {
	int i = 0;
	int j = size - 1;
	int mid = arr[size / 2];
	do {
		while (arr[i] < mid)
			i++;
		while (arr[j] > mid)
			j--;
		if (i <= j) {
			int p = arr[i];
			arr[i] = arr[j];
			arr[j] = p;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		qsort(arr, j + 1);
	if (i < size)
		qsort(&arr[i], size - i);
}

int main()
{
	int *arr;
	int *new_arr;
	int n;
	cin >> n;
	arr = new int[n];
	new_arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	qsort(arr, n);
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			new_arr[i / 2] = arr[i];
		else
			new_arr[n - (i / 2) - 1] = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << new_arr[i];
		if (i != (n - 1))
			cout << ' ';
		else
			cout << '\n';
	}
	delete arr;
	delete new_arr;
}