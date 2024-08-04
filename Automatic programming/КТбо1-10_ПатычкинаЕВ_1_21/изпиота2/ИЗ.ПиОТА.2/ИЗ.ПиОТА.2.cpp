/*Южный Федеральный Университет
Институт компьютерных технологий и информационной информации
Кафедра математического обеспечения и применения ЭВМ
Программирование и основы теории алгоритмов
Индивидуальное задание №2. Проектирование и реализация машины Тьюринга
ФИО КТбо1-
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
using namespace std;

HANDLE hConsole;

/*Структура для хранения значения структуры map по заданному ключу
*char new_symbol; - новый символ, на который будет заменяться текущий
*int new_state; - новое состояние
*char head_movement; - движение головки ленты машины Тьринга
*/
struct struct_for_command{
	char new_symbol;
	int new_state;
	char head_movement;
};

/*Структура для хранения ленты машины Тьюринга
* int head_position_symbol_number; - порядок символа, на который указывает головка
* string line; - лента машины Тьюринга, представленная в виде строки
* int now_state; - текущее состояние 
* char now_symbol; - символ, на который указывает головка
*/
struct struct_for_Turing_machine {
	int head_position_symbol_number;
	string line;
	int now_state;
	char now_symbol;
};

/*Функция инициалицирует систему команд
* ничего не возвращает
* получает адрес струкруты для хранения системы команд
*/
void insert_command_system(map<pair<int, char>, struct struct_for_command> & command_system){
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(1, '0'), { '0', 1, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(1, '1'), { '1', 1, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(1, '2'), { '2', 1, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(1, ' '), { '=', 2, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(2, '0'), { '0', 2, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(2, '1'), { '1', 2, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(2, '2'), { '2', 2, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(2, 'x'), { 'x', 3, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(2, 'y'), { 'y', 3, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(2, 'z'), { 'z', 3, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(2, '='), { '=', 2, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(2, '#'), { '#', 3, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(3, '0'), { 'x', 4, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(3, '1'), { 'y', 11, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(3, '2'), { 'z', 17, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(3, '='), { '=', 23, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(4, 'x'), { 'x', 4, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(4, 'y'), { 'y', 4, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(4, 'z'), { 'z', 4, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(4, '#'), { '#', 5, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(5, '0'), { '0', 5, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(5, '1'), { '1', 5, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(5, '2'), { '2', 5, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(5, 'x'), { 'x', 6, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(5, 'y'), { 'y', 6, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(5, 'z'), { 'z', 6, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(5, ' '), { ' ', 6, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(6, '0'), { 'x', 7, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(6, '1'), { 'y', 8, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(6, '2'), { 'z', 9, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(6, '#'), { '#', 7, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, '0'), { '0', 7, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, '1'), { '1', 7, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, '2'), { '2', 7, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, 'x'), { 'x', 7, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, 'y'), { 'y', 7, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, 'z'), { 'z', 7, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, '#'), { '#', 7, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, '='), { '=', 7, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, '!'), { '2', 10, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(7, ' '), { '0', 2, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, '0'), { '0', 8, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, '1'), { '1', 8, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, '2'), { '2', 8, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, 'x'), { 'x', 8, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, 'y'), { 'y', 8, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, 'z'), { 'z', 8, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, '#'), { '#', 8, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, '='), { '=', 8, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, '!'), { '1', 10, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(8, ' '), { '2', 10, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, '0'), { '0', 9, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, '1'), { '1', 9, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, '2'), { '2', 9, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, 'x'), { 'x', 9, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, 'y'), { 'y', 9, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, 'z'), { 'z', 9, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, '#'), { '#', 9, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, '='), { '=', 9, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, '!'), { '0', 10, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(9, ' '), { '1', 10, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(10, ' '), { '!', 2, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(11, 'x'), { 'x', 11, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(11, 'y'), { 'y', 11, 'R'}));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(11, 'z'), { 'z', 11, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(11, '#'), { '#', 12, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(12, '0'), { '0', 12, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(12, '1'), { '1', 12, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(12, '2'), { '2', 12, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(12, 'x'), { 'x', 13, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(12, 'y'), { 'y', 13, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(12, 'z'), { 'z', 13, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(12, ' '), { ' ', 13, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(13, '0'), { 'x', 14, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(13, '1'), { 'y', 15, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(13, '2'), { 'z', 16, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(13, '#'), { '#', 14, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, '0'), { '0', 14, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, '1'), { '1', 14, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, '2'), { '2', 14, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, 'x'), { 'x', 14, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, 'y'), { 'y', 14, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, 'z'), { 'z', 14, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, '#'), { '#', 14, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, '='), { '=', 14, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, '!'), { '0', 2, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(14, ' '), { '1', 2, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, '0'), { '0', 15, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, '1'), { '1', 15, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, '2'), { '2', 15, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, 'x'), { 'x', 15, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, 'y'), { 'y', 15, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, 'z'), { 'z', 15, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, '#'), { '#', 15, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, '='), { '=', 15, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, '!'), { '2', 10, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(15, ' '), { '0', 2, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, '0'), { '0', 16, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, '1'), { '1', 16, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, '2'), { '2', 16, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, 'x'), { 'x', 16, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, 'y'), { 'y', 16, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, 'z'), { 'z', 16, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, '#'), { '#', 16, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, '='), { '=', 16, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, '!'), { '1', 10, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(16, ' '), { '2', 10, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(17, 'x'), { 'x', 17, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(17, 'y'), { 'y', 17, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(17, 'z'), { 'z', 17, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(17, '#'), { '#', 18, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(18, '0'), { '0', 18, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(18, '1'), { '1', 18, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(18, '2'), { '2', 18, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(18, 'x'), { 'x', 19, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(18, 'y'), { 'y', 19, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(18, 'z'), { 'z', 19, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(18, ' '), { ' ', 19, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(19, '0'), { 'x', 20, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(19, '1'), { 'y', 21, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(19, '2'), { 'z', 22, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(19, '#'), { '#', 20, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, '0'), { '0', 20, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, '1'), { '1', 20, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, '2'), { '2', 20, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, 'x'), { 'x', 20, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, 'y'), { 'y', 20, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, 'z'), { 'z', 20, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, '#'), { '#', 20, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, '='), { '=', 20, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, '!'), { '1', 2, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(20, ' '), { '2', 2, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, '0'), { '0', 21, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, '1'), { '1', 21, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, '2'), { '2', 21, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, 'x'), { 'x', 21, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, 'y'), { 'y', 21, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, 'z'), { 'z', 21, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, '#'), { '#', 21, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, '='), { '=', 21, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, '!'), { '0', 2, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(21, ' '), { '1', 2, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, '0'), { '0', 22, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, '1'), { '1', 22, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, '2'), { '2', 22, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, 'x'), { 'x', 22, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, 'y'), { 'y', 22, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, 'z'), { 'z', 22, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, '#'), { '#', 22, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, '='), { '=', 22, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, '!'), { '2', 10, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(22, ' '), { '0', 2, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(23, '0'), { '0', 23, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(23, '1'), { '1', 23, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(23, '2'), { '2', 23, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(23, 'x'), { '0', 23, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(23, 'y'), { '1', 23, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(23, 'z'), { '2', 23, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(23, '#'), { '#', 23, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(23, ' '), { ' ', 24, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(24, '0'), { '0', 24, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(24, '1'), { '1', 24, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(24, '2'), { '2', 24, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(24, 'x'), { 'x', 24, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(24, 'y'), { 'y', 24, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(24, 'z'), { 'z', 24, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(24, '#'), { '#', 24, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(24, '='), { '=', 24, 'L' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(24, ' '), { ' ', 25, 'R' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(25, '0'), { ' ', 25, 'R' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(25, '1'), { '1', 0, 'N' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(25, '2'), { '2', 0, 'N' }));
	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(25, '='), { '=', 26, 'L' }));

	command_system.insert(pair< pair<int, char>, struct struct_for_command>(pair<int, char>(26, ' '), { '0', 0, 'N' }));
}

/*Функция проверяет правильность введенной строки
* возващает истину или ложь в зависимости от правильности ввода соотвественно
* получает адрес введенной строки
*/
bool input_string_validation(string &line){
	int size = line.size();
	bool symbols = true;
	bool quantity_first = false;
	bool quantity_second = false;
	bool first_number = true;
	int first_count = 0;
	int second_count = 0;
	int i = 0;
	for (i; i < size && first_number; ++i) {
		if (line[i] == '0' || line[i] == '1' || line[i] == '2') {
			first_count = first_count * 10 + line[i] - '0';
			quantity_first = true;
		}
		else {
			if (line[i] == '#') {
				first_number = false;
			}
			else {
				symbols = false;
				return false;
			}
		}
	}
	for (i; i < size; ++i) {
		if (line[i] == '0' || line[i] == '1' || line[i] == '2') {
			second_count = second_count * 10 + line[i] - '0';
			quantity_second = true;
		}
		else {
			symbols = false;
			return false;
		}
	}
	if ((first_count >= second_count) && quantity_first && quantity_second) {
		return true;
	}
	else {
		return false;
	}
}

/*Функция обрабатывает один шаг
* ничего не возвращет
* получает систему команд, структуру для хранения ленты машины Тьюринга 
*/
void one_step(map<pair<int, char>, struct struct_for_command> command_system, struct_for_Turing_machine &Turing_machine){
	char old_symbol = Turing_machine.now_symbol;
	int old_state = Turing_machine.now_state;
	char new_symbol = command_system[pair <int, char>(Turing_machine.now_state, Turing_machine.now_symbol)].new_symbol;
	int new_state = command_system[pair <int, char>(Turing_machine.now_state, Turing_machine.now_symbol)].new_state;
	Turing_machine.now_state = new_state;
	Turing_machine.line[Turing_machine.head_position_symbol_number] = new_symbol;
	if (Turing_machine.head_position_symbol_number == Turing_machine.line.size()) {
		Turing_machine.line += ' ';
	}
	if (command_system[pair <int, char>(old_state, old_symbol)].head_movement == 'N') {}
	else {
		if (command_system[pair <int, char>(old_state, old_symbol)].head_movement == 'R') {
			Turing_machine.head_position_symbol_number++;
		}
		else {
			if (command_system[pair <int, char>(old_state, old_symbol)].head_movement == 'L') {
				if (Turing_machine.head_position_symbol_number == 0) {
					Turing_machine.line = ' ' + Turing_machine.line;
				}
				else {
					Turing_machine.head_position_symbol_number--;
				}
			}
		}
		if (Turing_machine.line[0] != ' ') {
			Turing_machine.line = ' ' + Turing_machine.line;
			Turing_machine.head_position_symbol_number++;
		}
		if (Turing_machine.line[1] == ' ') {
			Turing_machine.line.erase(Turing_machine.line.begin());
			Turing_machine.head_position_symbol_number--;
		}
	}
	Turing_machine.now_symbol = Turing_machine.line[Turing_machine.head_position_symbol_number];
}

int main(){
	setlocale(LC_ALL, "Russian");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	map<pair<int, char>, struct struct_for_command> command_system;
	struct_for_Turing_machine Turing_machine;
	char choice;
	string line;
	do{
		cout << "Через символ # введите два числа в системе счисления с основанием 3: ";
		cin >> line;
		if (input_string_validation(line)){
			insert_command_system(command_system);
			Turing_machine.now_symbol = line[0];
			Turing_machine.line = ' ' + line + ' ';
			Turing_machine.now_state = 1;
			Turing_machine.head_position_symbol_number = 1;
			bool first_step = true;
			do {
				if (first_step) {
					cout << 'q' << Turing_machine.now_state << ' ';
					for (int i = 0; i < Turing_machine.head_position_symbol_number; ++i) {
						cout << Turing_machine.line[i];
					}
					SetConsoleTextAttribute(hConsole, 12);
					cout << Turing_machine.line[Turing_machine.head_position_symbol_number];
					SetConsoleTextAttribute(hConsole, 7);
					for (int i = Turing_machine.head_position_symbol_number + 1; i < Turing_machine.line.size(); ++i) {
						cout << Turing_machine.line[i];
					}
					cout << endl;
					first_step = false;
				}
				one_step(command_system, Turing_machine);
				cout << 'q' << Turing_machine.now_state << ' ';
				for (int i = 0; i < Turing_machine.head_position_symbol_number; ++i) {
					cout << Turing_machine.line[i];
				}
				SetConsoleTextAttribute(hConsole, 12);
				cout << Turing_machine.line[Turing_machine.head_position_symbol_number];
				SetConsoleTextAttribute(hConsole, 7);
				for (int i = Turing_machine.head_position_symbol_number + 1; i < Turing_machine.line.size(); ++i) {
					cout << Turing_machine.line[i];
				}
				cout << endl;
			} while (Turing_machine.now_state != 0);
		}
		else{
			cout << "Неверная входная строка." << endl;
		}
		cout << "Нажмите 'e' для выхода, или нажмите любую кнопку чтобы продолжить" << endl;
		cin >> choice;
	} while (choice != 'e');
}