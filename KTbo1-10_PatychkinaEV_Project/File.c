/**
* \file File.c
* \brief Реализация функций для расчёта платежа
* \author Патычкина Е.В.
* \date Дата последней модификации - 07.01.2023
*/

#include "File.h"

void name_file1(char *fname, int fm, int fy)
{
	fname[0] = 't';
	fname[1] = 'a';
	fname[2] = 'b';
	fname[3] = '_';
	fname[4] = fm + 48;
	fname[5] = '_';
	fname[6] = fy / 1000 + 48;
	fname[7] = fy / 100 % 10 + 48;
	fname[8] = fy % 100 / 10 + 48;
	fname[9] = fy % 10 + 48;
	fname[10] = '.';
	fname[11] = 't';
	fname[12] = 'x';
	fname[13] = 't';
	fname[14] = '\0';
}

void name_file2(char *fname, int fm, int fy)
{
	fname[0] = 't';
	fname[1] = 'a';
	fname[2] = 'b';
	fname[3] = '_';
	fname[4] = fm / 10 + 48;
	fname[5] = fm % 10 + 48;
	fname[6] = '_';
	fname[7] = fy / 1000 + 48;
	fname[8] = fy / 100 % 10 + 48;
	fname[9] = fy % 100 / 10 + 48;
	fname[10] = fy % 10 + 48;
	fname[11] = '.';
	fname[12] = 't';
	fname[13] = 'x';
	fname[14] = 't';
	fname[15] = '\0';
}