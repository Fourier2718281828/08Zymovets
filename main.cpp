#include <iostream>
#include "Array.h"
using std::cout;
using std::endl;
using std::string;

//************************************************************
//��������� � ���������� ������������ ���� ������ ��������� 
//������ � ��������� ���� Array<n,T>, ������������ ���������
//���� ������� ������� ��� ����� ������� �� ��� ������.
//�������� ���������� �����, ������� ������� ���������� 
//�������� ��� ������ ����� ������ � ����.
//Developed by Ruslan Zymovets (IPZ, group 1)
//on March 27
//Version 1.0
//************************************************************


int main(void)
{
	Array<10, double> a;
	Array<1, double> b;
	//Array<0, double> c;
	//Array<10, double&> f;
	
	for (size_t i = 0; i < a.size() - 2; ++i)
	{
		a[i] = i;
	}

	cout << a << endl;
	
	return 0;
}