#pragma once
#include "Types.h"

/*! \defgroup AllTeacher Список учителей табеля
* \brief Модуль функций для работы со всеми преподавателями файла
*/
///@{

/**
* \brief Функция проверяет наличие исключительных ситуаций
* \param tab_list Данные с Табеля
* \param N Количество строк в Табеле
* \return count_teacher Количество уникальных преподавателей
*/
int find_count_teacher(tab *tab_list, int N);

/**
* \brief Подпрограмма заполняет данные преподавателей
* \param tab_list Данные с Табеля
* \param N Количество строк в Табеле
* \param teachers Список преподавателей
* \return Подпрограмма ничего не возвращает
*/
void fill_in(tab *tab_list, int N, all_teach *teachers);

/**
* \brief Подпрограмма сортирует преподавателей по алфавиту
* \param teachers Список преподавателей
* \param N Количество преподавателей
* \return Подпрограмма ничего не возвращает
*/
void sort_FIO(all_teach *teachers, int N);

///@}
