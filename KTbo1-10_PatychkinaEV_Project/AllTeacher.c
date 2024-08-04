/**
* \file AllTeacher.c
* \brief Реализация функций для работы со списком преподавателей
* \author Патычкина Е.В.
* \date Дата последней модификации - 07.01.2023
*/

#define _CRT_SECURE_NO_WARNINGS
#include "AllTeacher.h"
#include "Types.h"
#include <string.h>

int find_count_teacher(tab *tab_list, int N)
{
	int count_teacher = 0;
	for (int i = 0; i < N; i++)
	{
		int fl = 0;
		for (int j = 0; j < i; j++)
		{
			if (strcmp(tab_list[i].F_I_O, tab_list[j].F_I_O) == 0)
				fl = 1;
		}
		if (fl == 0)
			count_teacher++;
	}
	return count_teacher;
}

void fill_in(tab *tab_list, int N, all_teach *teachers)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int fl = 0;
		for (int j = 0; j < i; j++)
		{
			if (strcmp(tab_list[i].F_I_O, tab_list[j].F_I_O) == 0)
				fl = 1;
		}
		if (fl == 0)
		{
			strcpy(teachers[count].F_I_O, tab_list[i].F_I_O);
			count++;

		}
	}
}

void sort_FIO(all_teach *teachers, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (strcmp(teachers[j].F_I_O, teachers[j + 1].F_I_O) > 0)
			{
				all_teach P = teachers[j];
				teachers[j] = teachers[j + 1];
				teachers[j + 1] = P;
			}
		}
	}
}