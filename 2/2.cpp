// 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "AnimalInheritance.h"

int main()
{
	setlocale(0, "Rus");
	// создание объектов и вывод информации о них
	animal("Паук", 0.003, 0.05).print();
	bird("Ворона", 0.3, 10, 0.1).print();
	fish("Рыба Молот", 150, 5, 0.5).print();
	cout << endl;
	system("pause");
	return 0;
}

