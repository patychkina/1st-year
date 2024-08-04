//Важно! При решении рекомендуется использовать стек, реализованный в виде списка.
#include <iostream>
using namespace std;

typedef struct StackItem {
	StackItem* next = nullptr;
	int number;
} *Stack;

int main()
{
	Stack line = new StackItem;
	char c;
	int count = 0;
	int varible = 0;
	int flag = 0;
	cin >> c;
	do
	{
		if (count == 0)
		{
			if ((c >= '0') and (c <= '9'))
			{
				varible = varible * 10 + (c - 48);
			}
			if ((c == ' ') or (c == '\n'))
			{
				line->number = varible;
				varible = 0;
				count++;
			}
		}
		else
		{
			if ((c >= '0') and (c <= '9'))
			{
				varible = varible * 10 + (c - 48);
				flag = 0;
			}
			if (((c == ' ') or (c == '\n')) and (flag == 0))
			{
				Stack p = new StackItem;
				p->next = line;
				line = p;
				line->number = varible;
				varible = 0;
			}
			if (c == '+')
			{
				varible += line->number;
				Stack p = line;
				line = line->next;
				delete p;
				varible += line->number;
				line->number = varible;
				varible = 0;
				c = getchar();
				flag = 1;
			}
			if (c == '-')
			{
				varible += (line->number)*(-1);
				Stack p = line;
				line = line->next;
				delete p;
				varible += line->number;
				line->number = varible;
				varible = 0;
				c = getchar();
				flag = 1;
			}
			if (c == '*')
			{
				varible = 1;
				varible *= line->number;
				Stack p = line;
				line = line->next;
				delete p;
				varible *= line->number;
				line->number = varible;
				varible = 0;
				c = getchar();
				flag = 1;
			}
		}
		if (c != '\n')
			c = getchar();
	} while (c != '\n');
	cout << line->number;
	return 0;
}