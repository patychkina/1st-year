/*Напишите программу, которая вводит две символьные строки и находит все латинские буквы. 
которых нет ни в одной из них. Заглавные и строчные буквы не различаются.

Входные данные
На вход программе подаются две символьные строки.

Выходные данные
Программа должна вывести в одной строке в алфавитном порядке все латинские буквы, 
которые не встречаются ни в одной из двух входных строк. Все буквы должны быть заглавными. 
Если ни одной такой буквы нет, нужно вывести число 0.*/

#include <iostream>
#include <set>
using namespace std;

void input_line(set <char> &line)
{
	char c;
	while ((c = getchar()) != '\n')
	{
		if ((c >= 65) && (c <= 90))
			line.insert(c);
		else
		{
			c -= 32;
			line.insert(c);
		}
	}
}

int main()
{
	set <char> line1;
	set <char> line2;
	set <char> alphabet;
	int count = 0;
	for (char b = 'A'; b <= 'Z'; b++)
		alphabet.insert(b);
	input_line(line1);
	input_line(line2);
	for (auto c : alphabet)
	{
		if ((line1.count(c) == 0) && (line2.count(c) == 0))
		{
			cout << c;
			count++;
		}
	}
	if (count == 0)
		cout << '0';
	cout << endl;
}