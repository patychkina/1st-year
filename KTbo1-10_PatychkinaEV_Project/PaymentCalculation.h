#pragma once
#include "Types.h"

/*! \defgroup PaymentCalculation Расчёт платежа
* \brief Модуль функций для поиска почасовой заработной платы
*/
///@{

/**
* \brief Функция проверяет наличие исключительных ситуаций
* \details Функция проверяет наличие образовательной программы в Catalog.txt и Reestr.txt, проверяет наличие образовательной программы у определенного преподавателя, а также проверяет работу преподавателя в определённый указанный срок
* \param name Фамилия и инициалы преподавателя
* \param tab_list Данные с Табеля
* \param reestr Данные с файла Reestr
* \param m Месяц расчётного периода
* \param y Год расчётного периода
* \param Q Количество строк в файле Reestr
* \param catalog Данные с файла Catalog
* \param Ncatalog Количество образовательных программ
* \param Ntab Количество строк в Табеле
* \return er Количество подходящих программ
*/
int error_checking(char *name, tab * tab_list, real_program *reestr, int m, int y, int Q, all_program *catalog, int Ncatalog, int Ntab);

/**
* \brief Функция заполняет данные по образовательным программам
* \param list Список программ
* \param name Фамилия и инициалы преподавателя
* \param tab_list Данные с Табеля
* \param reestr Данные с файла Reestr
* \param m Месяц расчётного периода
* \param y Год расчётного периода
* \param Q Количество строк в файле Reestr
* \param catalog Данные с файла Catalog
* \param Ncatalog Количество образовательных программ
* \param Ntab Количество строк в Табеле
* \param count_program Количество образовательных программ
* \param Vfot Коэффициент для расчёта фонда оплаты труда преподавателей
* \return Подпрограмма ничего не возвращает
*/
void full_list(tab_2 * list, char *name, tab * tab_list, real_program *reestr, int m, int y, int Q, all_program *catalog, int Ncatalog, int Ntab, int count_program, int Vfot);

/**
* \brief Функция ищет полное количество часов по определенной образовательной программе в данный период
* \param tab_line Данные Табеля
* \param Ntab Количество строк в Табеле
* \param line Список программ
* \param N Количество программ
* \return Подпрограмма ничего не возвращает
*/
void full_hours(tab *tab_line, int Ntab, tab_2 *line, int N);

/**
* \brief Функция ищет полное количество часов по определенной образовательной программе в данный период
* \param m_start Месяц начала
* \param y_start Год начала
* \param m_end Месяц конца
* \param y_end Год конца
* \param m Исходный месяц
* \param y Исходный год
* \return 0 - верно, 1 - ошибка
*/
int er_check_data(int m_start, int y_start, int m_end, int y_end, int m, int y);

///@}