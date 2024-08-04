//ЮФУ, ИКТИБ, МОП ЭВМ
//Программирование и основы теории алгоритмов
//Индивидуальное задание №1
//Проектирование и реализацияконечного распознавателя
//КТбо1-10, Патычкина Елизавета Вадимовна

#include <iostream>
#include <vector>
#include <map>
#include <string>
#define row 8
#define column 3
using namespace std;

void machine_insert(int m[row][column], map <int, char> &YN);

bool check(string line);

int СharacterProcessing(int t[row][column], char c, int state);

struct machine
{
	int table[row][column];
	map <int, char> YN;
	int state_start = 0;
	int state_finish = 0;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	struct machine mymachine;
	string answer;
	string line;
	machine_insert(mymachine.table, mymachine.YN);
	do
	{
		cout << "Введите входное слово: ";
		cin >> line;
		if (check(line) == false)
		{
			cout << "Строка содержит символы, которые не соответствуют алфавиту автомата." << endl;
		}
		else
		{
			for (int i = 0; i < line.size(); i++)
			{
				mymachine.state_finish = СharacterProcessing(mymachine.table, line[i], mymachine.state_start);
				cout << line[i] << ' ' << 'q' << mymachine.state_start << ' ' << "->" << 'q' << mymachine.state_finish << endl;
				mymachine.state_start = mymachine.state_finish;
			}
			int FinalState = mymachine.state_finish;
			if (mymachine.YN[FinalState] == 'Y')
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		mymachine.state_start = 0;
		cout << "Хотите ввести новое слово?" << '\n' << "Если да, нажмите Y, иначе любой другой символ." << endl;
		cin >> answer;
	} while (answer == "Y");
}

//Входные параметры: int m[row][column] - таблица переходов
//                   map <int, char> &YN - ссылка на структуру map с допускающими/недопускающими состояниями
//Функция: заполняет таблицу переходов и структуру  допускающими/недопускающими состониями
//Выходные параметры: функция ничего не возвращает
void machine_insert(int m[row][column], map <int, char> &YN)
{
	m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = 3;
	m[1][0] = 0;
	m[1][1] = 4;
	m[1][2] = 5;
	m[2][0] = 4;
	m[2][1] = 0;
	m[2][2] = 6;
	m[3][0] = 5;
	m[3][1] = 6;
	m[3][2] = 0;
	m[4][0] = 2;
	m[4][1] = 1;
	m[4][2] = 7;
	m[5][0] = 3;
	m[5][1] = 7;
	m[5][2] = 1;
	m[6][0] = 7;
	m[6][1] = 3;
	m[6][2] = 2;
	m[7][0] = 6;
	m[7][1] = 5;
	m[7][2] = 4;
	YN[0] = 'N';
	YN[1] = 'N';
	YN[2] = 'N';
	YN[3] = 'N';
	YN[4] = 'N';
	YN[5] = 'N';
	YN[6] = 'N';
	YN[7] = 'Y';
}

//Входные параметры: string line - введенная пользователем строка(слово)
//Функция: проверяет строку на верность введенных символов
//Выходные параметры: функция возвращает ИСТИНА, если все символы удовлетворяют алфавиту автомата
//                            возвращает ЛОЖЬ, если хотя бы один символ не удовлетворяют алфавиту автомата
bool check(string line)
{
	for (int i = 0; i < line.size(); i++)
	{
		if ((line[i] == '0') || (line[i] == '1') || (line[i] == '2'))
		{
		}
		else
			return false;
	}
	return true;
}

//Входные параметры: int t[row][column] - таблица переходов
//                   char c - рассматриваемый символ строки
//                   int state - текущее начальное состояние
//Функция: обраатывает один символ входной строки, определяет новое сотояние, 
//         определяет конечное состояние
//Выходные параметры: int t[state][num] - новое конечное состояние
int СharacterProcessing(int t[row][column], char c, int state)
{
	int num;
	if (c == '0')
		num = 0;
	else
	{
		if (c == '1')
			num = 1;
		else
		{
			if (c == '2')
				num = 2;
		}
	}
	return t[state][num];
}