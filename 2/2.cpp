// 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "AnimalInheritance.h"

int main()
{
	setlocale(0, "Rus");
	// �������� �������� � ����� ���������� � ���
	animal("����", 0.003, 0.05).print();
	bird("������", 0.3, 10, 0.1).print();
	fish("���� �����", 150, 5, 0.5).print();
	cout << endl;
	system("pause");
	return 0;
}

