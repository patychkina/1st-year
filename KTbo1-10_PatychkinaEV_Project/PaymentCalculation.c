/**
* \file PaymentCalculation.c
* \brief Реализация функций для расчёта платежа
* \author Патычкина Е.В.
* \date Дата последней модификации - 07.01.2023
*/

#define _CRT_SECURE_NO_WARNINGS
#include "PaymentCalculation.h"
#include <string.h>
#include "Types.h"

static int counting(int T, int N, int Ngr, int Vfot, int Saud);

int er_check_data(int m_start, int y_start, int m_end, int y_end, int m, int y);

int error_checking(char *name, tab * tab_list, real_program *reestr, int m, int y, int Q, all_program *catalog, int Ncatalog, int Ntab)
{
	int er = 0;
	for (int i = 0; i < Ntab; i++)
	{
		for (int j = 0; j < Ncatalog; j++)
		{
			for (int k = 0; k < Q; k++)
			{
				int data = er_check_data(reestr[k].m_start, reestr[k].y_start, reestr[k].m_end, reestr[k].y_end, m, y);
				if ((strcmp(name, tab_list[i].F_I_O) == 0) && (data == 0) && (strcmp(tab_list[i].short_name, reestr[k].short_name) == 0) && (strcmp(catalog[j].short_name, reestr[k].short_name) == 0))
					er++;
			}
		}
	}
	return er;
}

void full_list(tab_2 * list, char *name, tab * tab_list, real_program *reestr, int m, int y, int Q, all_program *catalog, int Ncatalog, int Ntab, int count_program, int Vfot)
{
	int t = 0;
	for (int i = 0; i < Ntab; i++)
	{
		for (int j = 0; j < Ncatalog; j++)
		{
			for (int k = 0; k < Q; k++)
			{
				int data = er_check_data(reestr[k].m_start, reestr[k].y_start, reestr[k].m_end, reestr[k].y_end, m, y);
				if ((strcmp(name, tab_list[i].F_I_O) == 0) && (data == 0) && (strcmp(tab_list[i].short_name, reestr[k].short_name) == 0) && (strcmp(catalog[j].short_name, reestr[k].short_name) == 0))
				{
					list[t].hours = tab_list[i].hours;
					list[t].T = reestr[k].price;
					list[t].N = reestr[k].count_pupils;
					list[t].Ngr = reestr[k].count_groups;
					list[t].Saud = catalog[j].audit_hours;
					strcat(list[t].short_name, catalog[j].short_name);
					list[t].P = (float)counting(list[t].T, list[t].N, list[t].Ngr, Vfot, list[t].Saud);
					t++;
				}
			}
		}
	}
}

void full_hours(tab *tab_line, int Ntab, tab_2 *line, int N)
{
	for (int j = 0; j < N; j++)
	{
		line[j].all_hours = 0;
	}
	for (int i = 0; i < Ntab; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (strcmp(tab_line[i].short_name, line[j].short_name) == 0)
				line[j].all_hours += tab_line[i].hours;
		}
	}
}

static int counting(int T, int N, int Ngr, int Vfot, int Saud)
{
	float p;
	p = (float)(T * N*Vfot);
	p = p / (float)100;
	p = p / (float)Ngr;
	p = p / (float)Saud;
	p = (int)(p * 100);

	return p;
}

int er_check_data(int m_start, int y_start, int m_end, int y_end, int m, int y)
{
	int er = 0;
	int res = y * 12 + m;
	int res_start = y_start * 12 + m_start;
	int res_end = y_end * 12 + m_end;
	if ((res >= res_start) && (res <= res_end))
		er = 0;
	else er = 1;
	return er;
}
