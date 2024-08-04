///Важно! Для реализации структуры данных использовать линейный список
#include <iostream>
using namespace std;

typedef struct Item {
	Item* next = nullptr; 
	int data;
} Item;
typedef Item* List;

int main()
{
	List s1 = new Item;
	List s2 = new Item;
	int count = 0;
	List p1 = s1;
	for (int i = 1; i <= 4; i++)
	{
		cin >> p1->data;
		p1->next = new Item;
		p1 = p1->next;
	}
	cin >> p1->data;
	List p2= s2;
	for (int i = 1; i <= 4; i++)
	{
		cin >> p2->data;
		p2->next = new Item;
		p2 = p2->next;
	}
	cin >> p2->data;
	while ((s1 != NULL) && (s2 != NULL) && (count < 1000000))
	{
		if ((((s1->data) > (s2->data)) && ((s1->data != 9) || (s2->data != 0)))||((s1->data==0)&&(s2->data==9)))
		{
			p1->next = new Item;
			p1 = p1->next;
			p1->data = s1->data;
			p1->next = new Item;
			p1 = p1->next;
			p1->data = s2->data;
		}
		else
		{
			p2->next = new Item;
			p2 = p2->next;
			p2->data = s1->data;
			p2->next = new Item;
			p2 = p2->next;
			p2->data = s2->data;
		}

		List varible = s1;
		s1 = s1->next;
		delete varible;
		varible = s2;
		s2 = s2->next;
		delete varible;
		count++;
	}

	if ((s1 != NULL) && (s2 != NULL))
		cout << "botva"<<'\n';
	else
	{
		if (s1 == NULL)
			cout << "second " << count << '\n';
		else
			cout << "first " << count << '\n';
	}
	return 0;
}