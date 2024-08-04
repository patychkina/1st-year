/*Для моделирования различных объектов часто применяются так называемые клеточные поля. 
В простейшем случае – это прямоугольные таблицы, характеризующие некоторую область, 
а в каждой ячейке таблицы записывается какая-либо информация об исследуемом объекте. 
В биологии для моделирования распространения вирусов на плоской области в каждой ячейке 
помечается наличие вируса, а его распространение осуществляется в соседние ячейки по вертикали 
и горизонтали за одну единицу времени. В начальный момент времени в исследуемую область проникли 
несколько вирусов. Напишите программу, которая найдёт время заражения всей исследуемой прямоугольной области.

Входные данные
Первая строка входного файла INPUT.TXT содержит два натуральных числа n и m - размеры таблицы 
(количество строк и столбцов соответственно). Известно, что 1 ≤ n, m ≤ 3000. Во второй строке 
вначале записано одно число k – количество проникших вирусов, а далее записаны 2k чисел – номера 
строк и столбцов первых заражённых ячеек yi, xi (1 ≤ k ≤ 10, 1 ≤ yi ≤ n, 1 ≤ xi ≤ m).

Выходные данные
В выходной файл OUTPUT.TXT выведите одно число – время заражения всей области.*/
#include <iostream>
#include <vector>
#include <queue>
#define maxN 3002
#define maxM 3002
using namespace std;

queue<pair<int,int>> Q;
vector <vector <bool>> visited(maxN, vector<bool> (maxM, false));
vector <pair<int, int>> infected_first(11);


int BFS(int N, int M, int k, vector <pair<int, int>> &infected_first)
{
	int second = 0;
	for (int i = 0; i < k; i++)
	{
		visited[infected_first[i].first][infected_first[i].second] = 1;
		Q.push(pair<int, int>(infected_first[i].first, infected_first[i].second));
	}
	pair<int,int> u;
	while (!Q.empty())
	{
		int count_Q = Q.size();
		for (int i = 0; i < count_Q; i++)
		{
			u = Q.front();
			Q.pop();
			if (!visited[u.first][u.second])
			{
				visited[u.first][u.second] = 1;
			}
			if (u.first - 1 > 0 && u.first - 1 <= N && u.second > 0 && u.second <= M && visited[u.first - 1][u.second] ==false)
			{
				visited[u.first-1][u.second] = 1;
				Q.push(pair<int, int>(u.first - 1, u.second));
			}
			if (u.first + 1 > 0 && u.first + 1 <= N && u.second > 0 && u.second <= M && visited[u.first + 1][u.second] == false)
			{
				visited[u.first + 1][u.second] = 1;
				Q.push(pair<int, int>(u.first + 1, u.second));
			}
			if (u.first > 0 && u.first <= N && u.second - 1 > 0 && u.second - 1 <= M && visited[u.first][u.second - 1] == false)
			{
				visited[u.first][u.second -1 ] = 1;
				Q.push(pair<int, int>(u.first, u.second-1));
			}
			if (u.first > 0 && u.first <= N && u.second + 1 > 0 && u.second + 1 <= M && visited[u.first][u.second + 1] == false)
			{
				visited[u.first][u.second + 1] = 1;
				Q.push(pair<int, int>(u.first, u.second + 1));
			}
		}
		second++;
	}
	return second;
}


int main()
{
	int N, M;
	int k, x, y;
	cin >> N >> M;
	cin >> k;
	vector <pair<int, int>> infected_first(k);
	int max_second = 0;
	for (int i = 0; i < k; i++)
		cin >> infected_first[i].first >> infected_first[i].second;
	max_second = BFS(N, M, k, infected_first) - 1;
	cout << max_second << endl;
}