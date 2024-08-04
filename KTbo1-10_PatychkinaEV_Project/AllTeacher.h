#pragma once
#include "Types.h"

/*! \defgroup AllTeacher ������ �������� ������
* \brief ������ ������� ��� ������ �� ����� ��������������� �����
*/
///@{

/**
* \brief ������� ��������� ������� �������������� ��������
* \param tab_list ������ � ������
* \param N ���������� ����� � ������
* \return count_teacher ���������� ���������� ��������������
*/
int find_count_teacher(tab *tab_list, int N);

/**
* \brief ������������ ��������� ������ ��������������
* \param tab_list ������ � ������
* \param N ���������� ����� � ������
* \param teachers ������ ��������������
* \return ������������ ������ �� ����������
*/
void fill_in(tab *tab_list, int N, all_teach *teachers);

/**
* \brief ������������ ��������� �������������� �� ��������
* \param teachers ������ ��������������
* \param N ���������� ��������������
* \return ������������ ������ �� ����������
*/
void sort_FIO(all_teach *teachers, int N);

///@}
