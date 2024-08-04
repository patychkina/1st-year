/*Требуется найти в связном графе остовное дерево минимально веса.

Входные данные
Первая строка входного файла содержит два натуральных числа n и m - количество вершин и ребер графа соответственно 
(1≤n≤20000, 0≤m≤100000). Следующие m строк содержат описание ребер по одному на строке. Ребро номер i описывается 
тремя натуральными числами bi, ei и wi - номера концов ребра и его вес соответственно (1≤bi,ei≤n, 0≤wi≤100000).

Граф является связным.

Выходные данные
Выведите единственное целое число - вес минимального остовного дерева.*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<set<pair<int, int>>> AdjacencyList(N + 1);
	vector <bool> ostov(N + 1, false);
	vector<int> len(N + 1, INT32_MAX);
	set <pair<int, int>> SpaspanningTree;
	for (int i = 0; i < M; i++)
	{
		int b, e, w;
		cin >> b >> e >> w;
		AdjacencyList[b].insert(pair<int, int>(w, e));
		AdjacencyList[e].insert(pair<int, int>(w, b));
	}
	len[1] = 0;
	ostov[1] = true;
	SpaspanningTree.insert(pair<int, int>(0, 1));
	while (!SpaspanningTree.empty())
	{
		int u = SpaspanningTree.begin()->second;
		SpaspanningTree.erase(SpaspanningTree.begin());
		ostov[u] = true;
		for (auto it = AdjacencyList[u].begin(); it != AdjacencyList[u].end(); it++)
		{
			if (ostov[it->second] == false && it->first < len[it->second])
			{
				len[it->second] = it->first;
				SpaspanningTree.insert(pair<int, int>(it->first, it->second));
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
		answer += len[i];
	cout << answer << endl;
}