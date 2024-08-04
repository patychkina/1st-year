//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Индивидуальное задание №3
//Реализация и анализ примитивно-рекурсивной функции
//КТбо1-10, Патычкина Елизавета Вадимовна

#include <iostream>
#include <string>
using namespace std;

//Функция производит вычисление функции от двух переменных f (x1, x2) = x1! * x2
//Входные значения : unsigned long long x1 - первая переменная функции
//                   unsigned long long x2 - вторая переменная функции
//Функция выводит аналитическую запись, возвращает значение функции для входных параметров x1 и x2 и выводит последовательность производимых действий
unsigned long long def(unsigned long long x1, unsigned long long x2)
{
	if (x1 == 0)
	{
		cout << "f (0, " << x2 << ") = g (0, " << x2 << ") = " << x2 << endl;
		return x2;
	}
	else
	{
		int recursive_return = def(x1 - 1, x2);
		int function_value = recursive_return * x1;
		cout << "f (" << x1 << ", " << x2 << ") = h (" << x1 - 1 << ", f (" << x1 - 1 << ", " << x2 << "), " << x2 << ") = h (" << x1 - 1 << ", " << recursive_return << ", " << x2 << ") = " << function_value << endl;
		return function_value;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string answer;
	unsigned long long x1, x2;
	cout << "f (x1, x2) = x1! * x2" << endl;
	do
	{
		cout << "Введите значения переменных x1 и x2 соответственно: ";
		cin >> x1 >> x2;
		def(x1, x2);
		cout << "Хотите ввести новое слово?" << '\n' << "Если да, нажмите Y, иначе любой другой символ." << endl;
		cin >> answer;
	} while (answer == "Y");
}