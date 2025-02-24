﻿//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Индивидуальное задание №2
//Проектирование и реализация машины Тьюринга
//КТбо1-10, Патычкина Елизавета Вадимовна

#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Структура хранения команды из системы команд
struct command
{
	int state_start;//начальное состояние
	char symbol_start;//начальный символ
	char position;//направление движения головки
	int state_finish;//конечное состояние(новое)
	char symbol_finish;//конечный символ(новый)
};

//Структура хранения машины Тьюринга
struct M_T
{
	int position;//коэффициент положения головки
	int state;//состояние машины Тьюринга
	string ribbon;//лента
	char symbol;//текущий обрабатываемый символ
};
                           
void input_sistem(vector <struct command>& cs);

int check(string line);

void CharacterProcessing(vector<command> cs, struct M_T& MT);

int main()
{
	vector <struct command> command_system;
	input_sistem(command_system);
	setlocale(LC_ALL, "Russian");
	string ribbon, answer;
	struct M_T MT;
	do
	{
		cout << "Введите два числа в системе счисления с основанием 3, разделенных символом #: ";
		cin >> MT.ribbon;
		if (check(MT.ribbon) == 0)
		{
			cout << "Строка введена неверно." << endl;
		}
		else
		{
			MT.ribbon.push_back(' ');
			MT.ribbon = ' ' + MT.ribbon;
			MT.position = 1;
			MT.symbol = MT.ribbon[MT.position];
			MT.state = 1;
			int fl = 1;
			while (MT.state)
			{
				if (fl)
				{
					cout << MT.ribbon << endl;
					for (int i = 0; i < MT.position; i++)
					{
						cout << ' ';
					}
					cout << '^' << endl;
					cout << "Текущее состояние машины Тьюринга: " << 'q' << MT.state << endl;
					fl = 0;
				}
				else
				{
					MT.symbol = MT.ribbon[MT.position];
					CharacterProcessing(command_system, MT);
					cout << MT.ribbon << endl;
					for (int i = 0; i < MT.position; i++)
					{
						cout << ' ';
					}
					cout << '^' << endl;
					cout << "Текущее состояние машины Тьюринга: " << 'q' << MT.state << endl;
				}
			}
		}
		cout << "Хотите ввести новое слово?" << '\n' << "Если да, нажмите Y, иначе любой другой символ." << endl;
		cin >> answer;
	} while (answer == "Y");
}

//Входные параметры: vector <struct command>& cs - систома команд машины Тьюринга
//Функция: заполняет систему команд статическими значениями
//Выходные параметры: функция ничего не возвращает
void input_sistem(vector <struct command>& cs)
{
	cs.push_back({ 1,'0', 'L', 1, '0' });
	cs.push_back({ 1,'1', 'L', 1, '1' });
	cs.push_back({ 1,'2', 'L', 1, '2' });
	cs.push_back({ 1,' ', 'R', 2, '=' });
	cs.push_back({ 2,'0', 'R', 2, '0' });
	cs.push_back({ 2,'1', 'R', 2, '1' });
	cs.push_back({ 2,'2', 'R', 2, '2' });
	cs.push_back({ 2,'=', 'R', 2, '=' });
	cs.push_back({ 2,'#', 'L', 3, '#' });
	cs.push_back({ 2,'a', 'L', 3, 'a' });
	cs.push_back({ 2,'b', 'L', 3, 'b' });
	cs.push_back({ 2,'c', 'L', 3, 'c' });
	cs.push_back({ 3,'0', 'R', 4, 'a' });
	cs.push_back({ 3,'1', 'R', 5, 'b' });
	cs.push_back({ 3,'2', 'R', 6, 'c' });
	cs.push_back({ 3,'=', 'R', 23, '=' });
	cs.push_back({ 4,'#', 'R', 7, '#' });
	cs.push_back({ 4,'a', 'R', 4, 'a' });
	cs.push_back({ 4,'b', 'R', 4, 'b' });
	cs.push_back({ 4,'c', 'R', 4, 'c' });
	cs.push_back({ 5,'#', 'R', 12, '#' });
	cs.push_back({ 5,'a', 'R', 5, 'a' });
	cs.push_back({ 5,'b', 'R', 5, 'b' });
	cs.push_back({ 5,'c', 'R', 5, 'c' });
	cs.push_back({ 6,'#', 'R', 17, '#' });
	cs.push_back({ 6,'a', 'R', 6, 'a' });
	cs.push_back({ 6,'b', 'R', 6, 'b' });
	cs.push_back({ 6,'c', 'R', 6, 'c' });
	cs.push_back({ 7,'0', 'R', 7, '0' });
	cs.push_back({ 7,'1', 'R', 7, '1' });
	cs.push_back({ 7,'2', 'R', 7, '2' });
	cs.push_back({ 7,'a', 'L', 8, 'a' });
	cs.push_back({ 7,'b', 'L', 8, 'b' });
	cs.push_back({ 7,'c', 'L', 8, 'c' });
	cs.push_back({ 7,' ', 'L', 8, ' ' });
	cs.push_back({ 8,'0', 'L', 9, 'a' });
	cs.push_back({ 8,'1', 'L', 10, 'b' });
	cs.push_back({ 8,'2', 'L', 11, 'c' });
	cs.push_back({ 8,'#', 'L', 9, '#' });
	cs.push_back({ 9,'0', 'L', 9, '0' });
	cs.push_back({ 9,'1', 'L', 9, '1' });
	cs.push_back({ 9,'2', 'L', 9, '2' });
	cs.push_back({ 9,'=', 'L', 9, '=' });
	cs.push_back({ 9,'#', 'L', 9, '#' });
	cs.push_back({ 9,'a', 'L', 9, 'a' });
	cs.push_back({ 9,'b', 'L', 9, 'b' });
	cs.push_back({ 9,'c', 'L', 9, 'c' });
	cs.push_back({ 9,' ', 'R', 2, '0' });
	cs.push_back({ 9,'*', 'L', 22, '2' });
	cs.push_back({ 10,'0', 'L', 10, '0' });
	cs.push_back({ 10,'1', 'L', 10, '1' });
	cs.push_back({ 10,'2', 'L', 10, '2' });
	cs.push_back({ 10,'=', 'L', 10, '=' });
	cs.push_back({ 10,'#', 'L', 10, '#' });
	cs.push_back({ 10,'a', 'L', 10, 'a' });
	cs.push_back({ 10,'b', 'L', 10, 'b' });
	cs.push_back({ 10,'c', 'L', 10, 'c' });
	cs.push_back({ 10,' ', 'L', 22, '2' });
	cs.push_back({ 10,'*', 'L', 22, '1' });
	cs.push_back({ 11,'0', 'L', 11, '0' });
	cs.push_back({ 11,'1', 'L', 11, '1' });
	cs.push_back({ 11,'2', 'L', 11, '2' });
	cs.push_back({ 11,'=', 'L', 11, '=' });
	cs.push_back({ 11,'#', 'L', 11, '#' });
	cs.push_back({ 11,'a', 'L', 11, 'a' });
	cs.push_back({ 11,'b', 'L', 11, 'b' });
	cs.push_back({ 11,'c', 'L', 11, 'c' });
	cs.push_back({ 11,' ', 'L', 22, '1' });
	cs.push_back({ 11,'*', 'L', 22, '0' });
	cs.push_back({ 12,'0', 'R', 12, '0' });
	cs.push_back({ 12,'1', 'R', 12, '1' });
	cs.push_back({ 12,'2', 'R', 12, '2' });
	cs.push_back({ 12,'a', 'L', 13, 'a' });
	cs.push_back({ 12,'b', 'L', 13, 'b' });
	cs.push_back({ 12,'c', 'L', 13, 'c' });
	cs.push_back({ 12,' ', 'L', 13, ' ' });
	cs.push_back({ 13,'0', 'L', 14, 'a' });
	cs.push_back({ 13,'1', 'L', 15, 'b' });
	cs.push_back({ 13,'2', 'L', 16, 'c' });
	cs.push_back({ 13,'#', 'L', 14, '#' });
	cs.push_back({ 14,'0', 'L', 14, '0' });
	cs.push_back({ 14,'1', 'L', 14, '1' });
	cs.push_back({ 14,'2', 'L', 14, '2' });
	cs.push_back({ 14,'=', 'L', 14, '=' });
	cs.push_back({ 14,'#', 'L', 14, '#' });
	cs.push_back({ 14,'a', 'L', 14, 'a' });
	cs.push_back({ 14,'b', 'L', 14, 'b' });
	cs.push_back({ 14,'c', 'L', 14, 'c' });
	cs.push_back({ 14,' ', 'R', 2, '1' });
	cs.push_back({ 14,'*', 'R', 2, '0' });
	cs.push_back({ 15,'0', 'L', 15, '0' });
	cs.push_back({ 15,'1', 'L', 15, '1' });
	cs.push_back({ 15,'2', 'L', 15, '2' });
	cs.push_back({ 15,'=', 'L', 15, '=' });
	cs.push_back({ 15,'#', 'L', 15, '#' });
	cs.push_back({ 15,'a', 'L', 15, 'a' });
	cs.push_back({ 15,'b', 'L', 15, 'b' });
	cs.push_back({ 15,'c', 'L', 15, 'c' });
	cs.push_back({ 15,' ', 'R', 2, '0' });
	cs.push_back({ 15,'*', 'L', 22, '2' });
	cs.push_back({ 16,'0', 'L', 16, '0' });
	cs.push_back({ 16,'1', 'L', 16, '1' });
	cs.push_back({ 16,'2', 'L', 16, '2' });
	cs.push_back({ 16,'=', 'L', 16, '=' });
	cs.push_back({ 16,'#', 'L', 16, '#' });
	cs.push_back({ 16,'a', 'L', 16, 'a' });
	cs.push_back({ 16,'b', 'L', 16, 'b' });
	cs.push_back({ 16,'c', 'L', 16, 'c' });
	cs.push_back({ 16,' ', 'L', 22, '2' });
	cs.push_back({ 16,'*', 'L', 22, '1' });
	cs.push_back({ 17,'0', 'R', 17, '0' });
	cs.push_back({ 17,'1', 'R', 17, '1' });
	cs.push_back({ 17,'2', 'R', 17, '2' });
	cs.push_back({ 17,'a', 'L', 18, 'a' });
	cs.push_back({ 17,'b', 'L', 18, 'b' });
	cs.push_back({ 17,'c', 'L', 18, 'c' });
	cs.push_back({ 17,' ', 'L', 18, ' ' });
	cs.push_back({ 18,'0', 'L', 19, 'a' });
	cs.push_back({ 18,'1', 'L', 20, 'b' });
	cs.push_back({ 18,'2', 'L', 21, 'c' });
	cs.push_back({ 18,'#', 'L', 19, '#' });
	cs.push_back({ 19,'0', 'L', 19, '0' });
	cs.push_back({ 19,'1', 'L', 19, '1' });
	cs.push_back({ 19,'2', 'L', 19, '2' });
	cs.push_back({ 19,'=', 'L', 19, '=' });
	cs.push_back({ 19,'#', 'L', 19, '#' });
	cs.push_back({ 19,'a', 'L', 19, 'a' });
	cs.push_back({ 19,'b', 'L', 19, 'b' });
	cs.push_back({ 19,'c', 'L', 19, 'c' });
	cs.push_back({ 19,' ', 'R', 2, '2' });
	cs.push_back({ 19,'*', 'R', 2, '1' });
	cs.push_back({ 20,'0', 'L', 20, '0' });
	cs.push_back({ 20,'1', 'L', 20, '1' });
	cs.push_back({ 20,'2', 'L', 20, '2' });
	cs.push_back({ 20,'=', 'L', 20, '=' });
	cs.push_back({ 20,'#', 'L', 20, '#' });
	cs.push_back({ 20,'a', 'L', 20, 'a' });
	cs.push_back({ 20,'b', 'L', 20, 'b' });
	cs.push_back({ 20,'c', 'L', 20, 'c' });
	cs.push_back({ 20,' ', 'R', 2, '1' });
	cs.push_back({ 20,'*', 'R', 2, '0' });
	cs.push_back({ 21,'0', 'L', 21, '0' });
	cs.push_back({ 21,'1', 'L', 21, '1' });
	cs.push_back({ 21,'2', 'L', 21, '2' });
	cs.push_back({ 21,'=', 'L', 21, '=' });
	cs.push_back({ 21,'#', 'L', 21, '#' });
	cs.push_back({ 21,'a', 'L', 21, 'a' });
	cs.push_back({ 21,'b', 'L', 21, 'b' });
	cs.push_back({ 21,'c', 'L', 21, 'c' });
	cs.push_back({ 21,' ', 'R', 2, '0' });
	cs.push_back({ 21,'*', 'L', 22, '2' });
	cs.push_back({ 22,' ', 'R', 2, '*' });
	cs.push_back({ 23,'0', 'R', 23, '0' });
	cs.push_back({ 23,'1', 'R', 23, '1' });
	cs.push_back({ 23,'2', 'R', 23, '2' });
	cs.push_back({ 23,'=', 'R', 23, '=' });
	cs.push_back({ 23,'#', 'R', 23, '#' });
	cs.push_back({ 23,'a', 'R', 23, 'a' });
	cs.push_back({ 23,'b', 'R', 23, 'b' });
	cs.push_back({ 23,'c', 'R', 23, 'c' });
	cs.push_back({ 23,' ', 'L', 24, ' ' });
	cs.push_back({ 24,'0', 'L', 24, '0' });
	cs.push_back({ 24,'1', 'L', 24, '1' });
	cs.push_back({ 24,'2', 'L', 24, '2' });
	cs.push_back({ 24,'=', 'L', 24, '=' });
	cs.push_back({ 24,'#', 'L', 24, '#' });
	cs.push_back({ 24,'a', 'L', 24, '0' });
	cs.push_back({ 24,'b', 'L', 24, '1' });
	cs.push_back({ 24,'c', 'L', 24, '2' });
	cs.push_back({ 24,' ', 'R', 25, ' ' });
	cs.push_back({ 25,'0', 'R', 25, ' ' });
	cs.push_back({ 25,'1', 'N', 0, '1' });
	cs.push_back({ 25,'2', 'N', 0, '2' });
	cs.push_back({ 25,' ', 'R', 25, ' ' });
	cs.push_back({ 25,'=', 'L', 26, '=' });
	cs.push_back({ 26,' ', 'N', 0, '0' });
}

//Входные параметры: string line - входная строка, введенная пользователем
//Функция: проверяет коректность введенной строки согласно требованиям в условии
//Выходные параметры: функция возвращает 1, если введенная стрка корректна
//                                       0, если строка введена с ошибками
int check(string line)
{
	int flag1 = 1;
	int flag2 = 1;
	int count = 0, count1 = 0, count2 = 0;
	for (int c = 0; (c < line.size()) && (flag2); c++)
	{
		if (flag1 == 1)
		{
			if ((line[c] == '0') || (line[c] == '1') || (line[c] == '2') || (line[c] == '#'))
			{
				if ((line[c] == '0') || (line[c] == '1') || (line[c] == '2'))
					count1 = count1 * 10 + (line[c] - 48);
				if (line[c] == '#')
					flag1 = 0;
			}
			else
			{
				flag2 = 0;
			}
		}
		else
		{
			if ((line[c] == '0') || (line[c] == '1') || (line[c] == '2'))
			{
				count2 = count2 * 10 + (line[c] - 48);
			}
			else
			{
				flag2 = 0;
			}
		}
	}
	if (count2 > count1)
		flag2 = 0;
	return flag2;
}

//Входные параметры: vector <struct command>& cs - систома команд машины Тьюринга
//                   struct M_T& MT - структура машины Тьюринга, содержащая строку, коэффициент положения головки, текущий символ и состояние
//Функция: обрабатывает символ, меняет состояние и совершает движение вправо/влево, в зависимости от системы команд машины Тьюринга
//Выходные параметры: функция ничего не возвращает
void CharacterProcessing(vector<struct command> cs, struct M_T& MT)
{
	int fl = 1;
	for (auto i = cs.begin(); (i != cs.end()) && (fl); i++)
	{
		if (MT.state == i->state_start && MT.symbol == i->symbol_start)
		{
			MT.state = i->state_finish;
			MT.ribbon[MT.position] = i->symbol_finish;
			MT.symbol = i->symbol_finish;
			if (i->position == 'R')
			{
				MT.position++;
				if (MT.position == MT.ribbon.size())
				{
					MT.ribbon = MT.ribbon + ' ';
				}
			}
			if (i->position == 'L')
			{
				if (MT.position == 0)
				{
					MT.ribbon = ' ' + MT.ribbon;
				}
				else
				{
					MT.position--;
				}
			}
			fl = 0;
		}
	}
} 