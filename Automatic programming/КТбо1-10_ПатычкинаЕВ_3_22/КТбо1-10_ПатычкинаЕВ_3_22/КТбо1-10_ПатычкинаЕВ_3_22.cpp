//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Индивидуальное задание №4
//Проектирование и реализация нормального алгоритма Маркова
//КТбо1-10, Патычкина Елизавета Вадимовна

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

HANDLE hConsole;

//Структура хранения команды из системы команд
struct substitution
{
	int number;//Номер команды
	string start;//Первая часть подстановки
	string finish;//Вторая часть подстановки
	bool stop;////Переменная, хранящая конец работы нормального алгоритма Маркова
};

//Структура хранения нормального алгоритма Маркова
struct n_a_m
{
	string line;//Текущая строка
	int position;//Номер позиции первого символа первой встретящийся подстановки
	bool stop;//Переменная, хранящая конец работы нормального алгоритма Маркова
};

//Входные параметры: string line - входная строка, введенная пользователем
//Функция: проверяет корректность введенной строки согласно требованиям в условии
//Выходные параметры: функция возвращает true, если введенная строка корректна
//    
bool check(string line);

//Входные параметры: vector <struct substitution> ss - система подстановок
//Функция: инициализирует систему подстановок 
//Выходные параметры: функция ничего не возвращает
void insert_substitution_system(vector <struct substitution>& ss);

//Входные параметры: string line - входная строка, введенная пользователем
//                   struct n_a_m nam - структура хранения нормального алгоритма Маркова
//Функция: выбирает и реализуют подстановки для текущего слова и выводит результат шага
//Выходные параметры: функция ничего не возвращает
void function_choice_realization(vector <struct substitution>& ss, struct n_a_m& nam);

int main()
{
	setlocale(LC_ALL, "Russian");
	string line, answer;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		cout << "Введите число в системе счисления с основанием 2: ";
		cin >> line;
		if (check(line) == false)
		{
			cout << "Число введено неверно." << endl;
		}
		else
		{
			vector <struct substitution> substitution_system;
			struct n_a_m NAM;
			NAM.line = " "+line;
			NAM.stop = false;
			insert_substitution_system(substitution_system);
			while (!NAM.stop)
				function_choice_realization(substitution_system, NAM);
		}
		cout << "Хотите ввести число ещё раз?" << '\n' << "Если да, нажмите Y, иначе любой другой символ." << endl;
		cin >> answer;
	} while (answer == "Y");
}

bool check(string line)
{
	for (int i = 0; i < line.size(); i++)
	{
		if (i == 0 && line[i] == '0')
			return false;
		if (line[i] != '0' && line[i] != '1')
			return false;
	}
	return true;
}

void insert_substitution_system(vector <struct substitution>& ss)
{
	ss.push_back({ 1, "*0", "0*", false });
	ss.push_back({ 2, "*1", "1*", false });
	ss.push_back({ 3, "*", "!", false });
	ss.push_back({ 4, "000!", "!0", false });
	ss.push_back({ 5, "001!", "!1", false });
	ss.push_back({ 6, "010!", "!2", false });
	ss.push_back({ 7, "011!", "!3", false });
	ss.push_back({ 8, "100!", "!4", false });
	ss.push_back({ 9, "101!", "!5", false });
	ss.push_back({ 10, "110!", "!6", false });
	ss.push_back({ 11, "111!", "!7", false });
	ss.push_back({ 12, "10!", "!2", false });
	ss.push_back({ 13, "11!", "!3", false });
	ss.push_back({ 14, "1!", "!1", false });
	ss.push_back({ 15, "!", "", true });
	ss.push_back({ 16, " ", "*", false });
}

void function_choice_realization(vector <struct substitution>& ss, struct n_a_m& nam)
{
	bool flag1 = true;
	for (int i = 0; (i < ss.size()) && flag1; i++)
	{
		if (nam.line.find(ss[i].start) != -1)
		{
			flag1 = false;
			bool flag2 = true;
			int count;
			nam.stop = ss[i].stop;
			for (int j = 0; (j < nam.line.size()) && flag2; j++)
			{
				count = 0;
				for (int k = 0; k < ss[i].start.size(); k++)
				{
					if (nam.line[j + k] == ss[i].start[k])
						count++;
				}
				if (count == ss[i].start.size())
				{
					flag2 = false;
					nam.position = j;
				}
			}
			cout << "(" << ss[i].number << ") ";
			for (int k = 0; k < nam.position; k++)
				cout << nam.line[k];
			SetConsoleTextAttribute(hConsole, 12);
			for (int k = nam.position; k < nam.position + count; k++)
				cout << nam.line[k];
			SetConsoleTextAttribute(hConsole, 7);
			for (int k = nam.position + count; k < nam.line.size(); k++)
				cout << nam.line[k];
			nam.line.replace(nam.position, ss[i].start.size(), ss[i].finish);
			cout << " -> ";
			for (int k = 0; k < nam.line.size(); k++)
				cout << nam.line[k];
			cout << endl;
			if (ss[i].stop)
				cout << "Результат: " << nam.line << endl;
		}
	}
}