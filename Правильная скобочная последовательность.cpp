//Важно! Для реализации структуры данных использовать линейный список
#include <iostream>
using namespace std;

typedef struct Item {
	Item* next = nullptr;
	Item* prev = nullptr;
	char bracket;
} Item;

typedef Item* List;

int main()
{
	List line = new Item;
	char c;
	int count = 0;
	int flag = 0;
	while ((c = getchar()) != '\n')
	{
		if ((c == '(') || (c == '[') || (c == '{'))
		{
			line->bracket = c;
			line->next = new Item;
			line->next->prev = line;
			line = line->next;
			count++;
		}
		else
		{
			if ((count != 0)&&(line->prev != nullptr))
			{
				if (((c == ')') && (line->prev->bracket == '(')) || ((c == ']') && (line->prev->bracket == '[')) || ((c == '}') && (line->prev->bracket == '{')))
				{
					if (line->prev->prev == nullptr)
					{
						delete line;
						line = new Item;
						count = 1;
					}
					else
					{
						List t = line;
						line = line->prev;
						line->next = nullptr;
						delete t;
					}
					count--;
				}
				else
				{
					if (c == ' ')
					{
					}
					else
					{
						flag = 1;
					}
				}
			}
			else
			{
				if (c == ' ')
				{
				}
				else
				{
					flag = 1;
				}
			}
		}
	}
	if ((line->next == nullptr) && (line->prev == nullptr) && (flag == 0))
		cout << "yes" << '\n';
	else cout << "no" << '\n';
	return 0;
}