//Важно! Для реализации структуры данных использовать линейный список
#include <iostream>
using namespace std;

typedef struct Item {
	Item* next = nullptr;
	Item* prev = nullptr;
	int number;
} Item;
typedef Item* List;

int main()
{
	int N;
	int execute;
	int book;
	cin >> N;
	List left = new Item;
	List right = left;
	int n = N;
	int s = N;
	while (N)
	{
		cin >> execute;
		if (execute == 1)
		{
			cin >> book;
			if ((left->next == nullptr) && (left->prev == nullptr) && (s == n))
			{
				left->number = book;
				s--;
			}
			else
			{
				List p = new Item;
				p->number = book;
				left->prev = p;
				p->next = left;
				left = p;
			}
		}
		if (execute == 2)
		{
			cin >> book;
			if ((right->next == nullptr) && (right->prev == nullptr) && (s == n))
			{
				right->number = book;
				s--;
			}
			else
			{
				List p = right;
				p->next = new Item;
				p->next->number = book;
				p->next->prev = p;
				p = p->next;
				p->prev->next = p;
				right = p;
			}
		}
		if (execute == 3)
		{
			List p = left;
			cout << left->number << ' ';
			if (left->next != nullptr)
			{
				List t = left;
				left = left->next;
				left->prev = nullptr;
				delete t;
			}
			else
			{
				delete left;
				left = new Item;
				right = left;
				s = n;
			}
		}
		if (execute == 4)
		{
			List p = right;
			cout << p->number << ' ';
			if (p->prev!=nullptr)
			{
				List t = p;
				p=p->prev;
				p->next = nullptr;
				delete t;
				right = p;
			}
			else
			{
				if ((p->next == nullptr) && (p->prev == nullptr))
				{
					delete right;
					right = new Item;
					left = right;
					s = n;
				}
			}
		}
		N--;
	}
	return 0;
}