/**
* \mainpage Индивидуальное задание 2022/2023
* \authors КТбо1-10 Патычкина Е.В.
* \date 07.01.2023
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Types.h"
#include "File.h"
#include "PaymentCalculation.h"
#include "AllTeacher.h"

int main()
{
	FILE *fcatalog, *freestr, *fin, *ftab, *fout;
	fcatalog = fopen("Catalog.txt", "r");
	freestr = fopen("Reestr.txt", "r");
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	int k_fot;
	int k_nach;
	int k_sfd;
	int N;
	int Q;
	int count_rows_input = 0;
	int error = 0;
	int N_tab;
	fscanf(fcatalog, "%d %d %d %d", &k_fot, &k_nach, &k_sfd, &N);
	fscanf(freestr, "%d", &Q);

	input *teacher = (input *)calloc(1, sizeof(input));
	fscanf(fin, "%s %s %d.%d", &teacher[0].sum, &teacher[0].F_I_O, &teacher[0].m, &teacher[0].y);

	all_program *programs = (all_program *)calloc(N, sizeof(all_program));
	real_program *real_programs = (real_program *)calloc(N, sizeof(real_program));
	for (int i = 0; i < N; i++)
	{
		fscanf(fcatalog, "%s %d %d", &programs[i].short_name, &programs[i].full_hours, &programs[i].audit_hours);
		fgets(programs[i].full_name, 272, fcatalog);
	}

	for (int i = 0; i < Q; i++)
	{
		fscanf(freestr, "%s %d.%d %d.%d %d %d %d", &real_programs[i].short_name, &real_programs[i].m_start, &real_programs[i].y_start, &real_programs[i].m_end, &real_programs[i].y_end, &real_programs[i].price, &real_programs[i].count_pupils, &real_programs[i].count_groups);
	}

	if (strcmp(teacher->F_I_O, "*") != 0)
	{
		int count_program = 0;
		char fname[16];
		if (teacher->m >= 10)
			name_file2(fname, teacher->m, teacher->y);
		else
			name_file1(fname, teacher->m, teacher->y);
		ftab = fopen(fname, "r");
		if (ftab == NULL)
		{
			fprintf(fout, "%s %d.%d Error\nTOTAL %s 0.00", teacher->F_I_O, teacher->m, teacher->y, teacher->F_I_O);
		}
		else
		{
			fscanf(ftab, "%d", &N_tab);
			tab *tab_list = (tab *)calloc(N_tab, sizeof(tab));
			for (int i = 0; i < N_tab; i++)
				fscanf(ftab, "%s %s %d", &tab_list[i].F_I_O, &tab_list[i].short_name, &tab_list[i].hours);

			if (strcmp(teacher->sum, "Sum") != 0)
				error = 1;
			if (error == 0)
			{
				count_program = error_checking(teacher->F_I_O, tab_list, real_programs, teacher->m, teacher->y, Q, programs, N, N_tab);
				if (count_program == 0)
					error = 1;
			}
			if (error == 0)
			{
				tab_2 *list_program = (tab_2 *)calloc(count_program, sizeof(tab_2));
				full_list(list_program, teacher->F_I_O, tab_list, real_programs, teacher->m, teacher->y, Q, programs, N, N_tab, count_program, k_fot);
				full_hours(tab_list, N_tab, list_program, count_program);

				fprintf(fout, "%s %d.%d %d\n", teacher->F_I_O, teacher->m, teacher->y, count_program);
				float S = 0;
				for (int i = 0; i < count_program; i++)
				{
					fprintf(fout, "%s %d (from %d) %.2f %.2f\n", list_program[i].short_name, list_program[i].hours, list_program[i].all_hours, list_program[i].P / 100, list_program[i].P / 100 * list_program[i].hours);
					S += list_program[i].P*list_program[i].hours;
				}
				if (S != 0)
					fprintf(fout, "TOTAL %s %.2f", teacher->F_I_O, S / 100);
				else
					fprintf(fout, "%s %d.%d Error\nTOTAL %s 0.00", teacher->F_I_O, teacher->m, teacher->y, teacher->F_I_O);
				free(list_program);
				list_program = NULL;
			}
			else
			{
				fprintf(fout, "%s %d.%d Error\nTOTAL %s 0.00", teacher->F_I_O, teacher->m, teacher->y, teacher->F_I_O);
			}
			free(tab_list);
			tab_list = NULL;
		}
		fclose(ftab);
	}

	if (strcmp(teacher->F_I_O, "*") == 0)
	{
		int count_teacher = 0;
		char fname[16];
		if (teacher->m >= 10)
			name_file2(fname, teacher->m, teacher->y);
		else
			name_file1(fname, teacher->m, teacher->y);
		ftab = fopen(fname, "r");
		if (ftab == NULL)
		{
			fprintf(fout, "0 0.00");
		}
		else
		{
			float full_sum = 0;
			fscanf(ftab, "%d", &N_tab);
			tab *tab_list = (tab *)calloc(N_tab, sizeof(tab));
			for (int i = 0; i < N_tab; i++)
				fscanf(ftab, "%s %s %d", &tab_list[i].F_I_O, &tab_list[i].short_name, &tab_list[i].hours);
			if (strcmp(teacher->sum, "Sum") != 0)
				error = 1;
			if (error == 0)
				count_teacher = find_count_teacher(tab_list, N_tab);
			all_teach *teachers = (all_teach *)calloc(count_teacher, sizeof(all_teach));

			fill_in(tab_list, N_tab, teachers);
			sort_FIO(teachers, count_teacher);

			for (int i = 0; i < count_teacher; i++)
			{
				teachers[i].count_program = error_checking(teachers[i].F_I_O, tab_list, real_programs, teacher->m, teacher->y, Q, programs, N, N_tab);
				if (teachers[i].count_program == 0)
					teachers[i].error = 1;
				else
					teachers[i].error = 0;
				if (teachers[i].error == 0)
				{
					teachers[i].tab = (tab_2 *)calloc(teachers[i].count_program, sizeof(tab_2));
					full_list(teachers[i].tab, teachers[i].F_I_O, tab_list, real_programs, teacher->m, teacher->y, Q, programs, N, N_tab, teachers[i].count_program, k_fot);
					full_hours(tab_list, N_tab, teachers[i].tab, teachers[i].count_program);

					for (int j = 0; j < teachers[i].count_program; j++)
						full_sum += teachers[i].tab[j].P*teachers[i].tab[j].hours;
				}
			}
			fprintf(fout, "%d %.2f\n", count_teacher, full_sum / 100);
			for (int i = 0; i < count_teacher; i++)
			{
				if (teachers[i].error != 0)
					fprintf(fout, "%s %d.%d Error\nTOTAL %s 0.00\n", teachers[i].F_I_O, teacher->m, teacher->y, teachers[i].F_I_O);
				else
				{
					fprintf(fout, "%s %d.%d %d\n", teachers[i].F_I_O, teacher->m, teacher->y, teachers[i].count_program);
					float S = 0;
					for (int j = 0; j < teachers[i].count_program; j++)
					{
						fprintf(fout, "%s %d (from %d) %.2f %.2f\n", teachers[i].tab[j].short_name, teachers[i].tab[j].hours, teachers[i].tab[j].all_hours, teachers[i].tab[j].P / 100, teachers[i].tab[j].P / 100 * teachers[i].tab[j].hours);
						S += teachers[i].tab[j].P*teachers[i].tab[j].hours;
					}
					if (S != 0)
						fprintf(fout, "TOTAL %s %.2f\n", teachers[i].F_I_O, S / 100);
					else
						fprintf(fout, "%s %d.%d Error\nTOTAL %s 0.00 \n", teachers[i].F_I_O, teacher->m, teacher->y, teachers[i].F_I_O);
				}
				fprintf(fout, "--------------------\n");
			}
			for (int i = 0; i < count_teacher; i++)
			{
				free(teachers[i].tab);
				teachers[i].tab = NULL;
			}
			free(tab_list);
			tab_list = NULL;
			free(teachers);
			teachers = NULL;
		}
		fclose(ftab);
	}
	//-------------------------------------------------------------------------------------------
	assert(er_check_data(1, 2020, 2, 2022, 11, 2021) == 0);
	assert(er_check_data(1, 2020, 2, 2020, 1, 2020) == 0);
	assert(er_check_data(10, 2020, 2, 2021, 11, 2021) == 1);
	assert(er_check_data(2, 2022, 11, 2022, 11, 2021) == 1);
	//-------------------------------------------------------------------------------------------
	free(teacher);
	teacher = NULL;
	free(programs);
	programs = NULL;
	real_programs = NULL;
	fclose(fcatalog);
	fclose(freestr);
	fclose(fin);

	return 0;
}