/*Принц Винсент получил карту дорог страны Лимония. Теперь ему требуется определить кратчайший маршрут из города A ,
 где он находится, в город B , где его ждёт невеста. Помогите Винсенту – напишите программу, которая решает эту задачу.

Входные данные
В первой строке вводится количество городов N ( 1 ≤ N ≤ 1000 ). В следующих N строках записано по N чисел, 
разделённых пробелами – элементы весовой матрицы графа, который описывает схему дорог между городами: 
положительное число означает расстояние между городами, ноль говорит о том, что дороги нет. 
В следующей строке вводятся номера начальной и конечной точек (городов), A и B . Нумерация городов начинается с единицы.

Выходные данные
Программа должна вывести в первой строчке длину кратчайшего маршрута. 
Во второй строчке выводится последовательность городов, начиная с города A и заканчивая городом B , 
через которые нужно ехать принцу. Если дороги между заданными городами вообще нет, нужно вывести число 0.*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define INF 1000000
using namespace std;

void found_road(vector <vector<int>> &rt, int A, int B, stack <int> &S);

int main()
{
	int N;
	int A, B;
	cin >> N;
	stack <int> line;
	vector <vector<int>> roads_len(N + 1, vector<int>(N + 1, INF));
	vector <vector<int>> road_transition(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int x;
			cin >> x;
			if (x != 0)
				roads_len[i][j] = x;
		}
	}
	cin >> A >> B;
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int road = roads_len[i][j];
				roads_len[i][j] = min(roads_len[i][j], roads_len[i][k] + roads_len[k][j]);
				if (road != roads_len[i][j])
					road_transition[i][j] = k;
			}
		}
	}
	if (roads_len[A][B] == INF)
		cout << '0' << endl;
	else
	{
		cout << roads_len[A][B] << endl;
		line.push(B);
		found_road(road_transition, A, B , line);
		while (!line.empty())
		{
			cout << line.top() << ' ';
			line.pop();
		}
		cout << endl;
	}
}

void found_road(vector <vector<int>> &rt, int A, int B, stack <int> &S)
{
	if (rt[A][B] != INF)
	{
		found_road(rt, rt[A][B], B, S);
		found_road(rt, A, rt[A][B], S);
	}
	else
		S.push(A);
}