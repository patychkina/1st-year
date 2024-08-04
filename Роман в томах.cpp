/*В романе N глав. В i-той главе ai страниц. Требуется издать роман в K томах так,
 чтобы объем самого «толстого» тома был минимален. В каждом томе главы располагаются по порядку своих номеров.

Требуется написать программу, которая найдет количество страниц в самом «толстом» томе.

Входные данные
Входной текстовый файл INPUT.TXT содержит в первой строке число N (1 ≤ N ≤ 100). 
Во второй строке через пробел записаны N чисел – количество страниц в каждой главе.
 Количество страниц в романе не превышает 32767. В третьей строке записано число K (1 ≤ K ≤ N).

Выходные данные
Выходной файл OUTPUT.TXT должен содержать количество страниц в самом «толстом» томе.*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N;
	vector <int> arr(N);
    int max = 0, min = 0;
	for (int i = 0; i < N; i++)
    {	
        cin >> arr[i];
        max+=arr[i];
    }
	cin >> K;
	while (min < max)
	{
		int mid = (min + max) / 2;
		int count_v = 0, count_p = 0;
		int fl = 0;
		for (int i = 0; (i < N)&&(fl==0); i++)
		{
			if (count_p + arr[i] <= mid)
				count_p += arr[i];
			else
			{
				count_v++;
				count_p = arr[i];
			}
			if (arr[i] > mid)
			{
				fl = 1;
				min = mid+1;
			}
		}
		if (fl != 1)
		{
			count_v++;
			if (count_v <= K)
				max = mid;
			else
				min = mid+1;
		}
	}
	cout << max;
}