/*Напишите программу, которая составляет из цифр введённой строки число-палиндром максимальной длины (которое читается одинаково слева направо и справа налево). Если таких чисел несколько, нужно вывести минимальное из них. Все имеющиеся цифры использовать не обязательно, но количество цифр в ответе должно быть максимально возможным.

Входные данные
Входная строка содержит цифры (по крайней мере, одну) и, возможно, другие символы.

Выходные данные
Программа должна вывести число-палиндром максимальной длины, которое можно составить из цифр входной строки.*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string line, answer, result;
	getline(cin, line);
	map <char, int> count;
	bool first_flag = true;
	bool flag = true;
	int size_line = line.size();
	for (int i = 0; i < size_line; i++)
	{
		if (line[i] >= '1'&&line[i] <= '9')
			count[line[i]]++;
		if (line[i] == '0')
			count['=']++;
	}
	for (auto it = count.begin(); it != count.end()&&first_flag; it++)
	{
		if ((it->first != '=') && (it->second - 2 >= 0))			
		{
			answer += it->first;
			it->second = it->second - 2;
			first_flag = false;
		}
	}
	int x = count['='];
	count.erase(count.find('='));
	count.insert(make_pair('0', x));
	if (first_flag == false)
	{
		for (auto it = count.begin(); it != count.end(); it++)
		{
			if (it->second - 2 >= 0)
			{
				int h = it->second / 2;
				while (h)
				{
					answer += it->first;
					it->second = it->second - 2;
					h--;
				}
			}
		}
	}
	auto it = count.begin();
	while (flag && it!=count.end())
	{
		if (it->second > 0)
		{
			answer += it->first;
			flag = false;
		}
		it++;
	}
	result = answer;
	int size;
	if (flag)
		size = answer.size();
	else
		size = answer.size() - 1;
	for (int i = size - 1; i >= 0; i--)
	{
		result += answer[i];
	}
	cout << result << endl;
}