// n2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Game.h"
#include "string"
using namespace std;


int main()
{
	MythicalAnimal unicorn("Unicorn", 50, 120, 50, 100);
	Humanoid troll("Troll", 300, 60, 200, 3, 350);
	Wizard merlin("Merlin", 100, 100, 100, 5, 50, "magic");
	MagicThing harp("Harp", 150, "puts listeners to sleep");

	unicorn.print();
	unicorn.move(100, 100);
	unicorn.draw();
	unicorn.print();
	cout << endl;

	troll.print();
	troll.move(0, 0);
	troll.print();
	cout << endl;

	merlin.print();
	merlin.move(100, 100);
	merlin.draw();
	merlin.print();
	cout << endl;

	harp.print();

	system("pause");
    return 0;
}

