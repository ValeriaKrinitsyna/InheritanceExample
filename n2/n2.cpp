// n2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Game.h"


int main()
{
	setlocale(0, "Rus");
	MythicalAnimal unicorn("Единорог", 100, 90);
	HumanoidCharacter siren("Сирена", 60, 120);
	MagicCharacter phoenix("Феникс", 40, 100, "возрождение из пепла");
	MagicThing harp("Арфа", 30, "усыпление слушателей");
	unicorn.print();
	siren.print();
	phoenix.print();
	harp.print();
	cout << endl;
	system("pause");
    return 0;
}

