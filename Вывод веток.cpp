/*Для полученного дерева выведите список всех вершин, имеющих только одного ребёнка, в порядке возрастания.

Входные данные
Вводится последовательность целых чисел,оканчивающаяся нулем. Построить по ней дерево.

Выходные данные
Выведите список требуемых вершин.*/
#include <iostream>
#include <set>
using namespace std;

typedef struct Node
{
	int data;
	Node *right = nullptr;
	Node *left = nullptr;
} * Tree;

void TreeInsort(Tree &tree, int p);

void OneChild(Tree &tree, set <int> &list);

int main()
{
	Tree tree = NULL;
	int x;
	set <int> list;
	cin >> x;
	while (x != 0)
	{
		TreeInsort(tree, x);
		cin >> x;
	}
	OneChild(tree, list);
	for (auto i : list)
		cout << i << endl;
}

void TreeInsort(Tree &tree, int p)
{
	if (tree == nullptr)
	{
		tree = new Node;
		tree->data = p;
	}
	else
	{
		if (p == tree->data)
			return;
		else
		{
			if (p > tree->data)
				TreeInsort(tree->right, p);
			else
			{
				if (p < tree->data)
					TreeInsort(tree->left, p);
			}
		}
	}
}

void OneChild(Tree &tree, set <int> &list)
{
	if (tree == nullptr)
		return;
	else
	{
		if (((tree->left == nullptr) && (tree->right != nullptr)) || ((tree->left != nullptr) && (tree->right == nullptr)))
			list.insert(tree->data);
		OneChild(tree->left, list);
		OneChild(tree->right, list);
	}
}