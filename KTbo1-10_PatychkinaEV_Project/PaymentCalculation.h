#pragma once
#include "Types.h"

/*! \defgroup PaymentCalculation ������ �������
* \brief ������ ������� ��� ������ ��������� ���������� �����
*/
///@{

/**
* \brief ������� ��������� ������� �������������� ��������
* \details ������� ��������� ������� ��������������� ��������� � Catalog.txt � Reestr.txt, ��������� ������� ��������������� ��������� � ������������� �������������, � ����� ��������� ������ ������������� � ����������� ��������� ����
* \param name ������� � �������� �������������
* \param tab_list ������ � ������
* \param reestr ������ � ����� Reestr
* \param m ����� ���������� �������
* \param y ��� ���������� �������
* \param Q ���������� ����� � ����� Reestr
* \param catalog ������ � ����� Catalog
* \param Ncatalog ���������� ��������������� ��������
* \param Ntab ���������� ����� � ������
* \return er ���������� ���������� ��������
*/
int error_checking(char *name, tab * tab_list, real_program *reestr, int m, int y, int Q, all_program *catalog, int Ncatalog, int Ntab);

/**
* \brief ������� ��������� ������ �� ��������������� ����������
* \param list ������ ��������
* \param name ������� � �������� �������������
* \param tab_list ������ � ������
* \param reestr ������ � ����� Reestr
* \param m ����� ���������� �������
* \param y ��� ���������� �������
* \param Q ���������� ����� � ����� Reestr
* \param catalog ������ � ����� Catalog
* \param Ncatalog ���������� ��������������� ��������
* \param Ntab ���������� ����� � ������
* \param count_program ���������� ��������������� ��������
* \param Vfot ����������� ��� ������� ����� ������ ����� ��������������
* \return ������������ ������ �� ����������
*/
void full_list(tab_2 * list, char *name, tab * tab_list, real_program *reestr, int m, int y, int Q, all_program *catalog, int Ncatalog, int Ntab, int count_program, int Vfot);

/**
* \brief ������� ���� ������ ���������� ����� �� ������������ ��������������� ��������� � ������ ������
* \param tab_line ������ ������
* \param Ntab ���������� ����� � ������
* \param line ������ ��������
* \param N ���������� ��������
* \return ������������ ������ �� ����������
*/
void full_hours(tab *tab_line, int Ntab, tab_2 *line, int N);

/**
* \brief ������� ���� ������ ���������� ����� �� ������������ ��������������� ��������� � ������ ������
* \param m_start ����� ������
* \param y_start ��� ������
* \param m_end ����� �����
* \param y_end ��� �����
* \param m �������� �����
* \param y �������� ���
* \return 0 - �����, 1 - ������
*/
int er_check_data(int m_start, int y_start, int m_end, int y_end, int m, int y);

///@}