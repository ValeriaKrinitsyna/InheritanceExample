// n2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Game.h"


int main()
{
	setlocale(0, "Rus");
	MythicalAnimal unicorn("��������", 100, 90);
	HumanoidCharacter siren("������", 60, 120);
	MagicCharacter phoenix("������", 40, 100, "����������� �� �����");
	MagicThing harp("����", 30, "��������� ����������");
	unicorn.print();
	siren.print();
	phoenix.print();
	harp.print();
	cout << endl;
	system("pause");
    return 0;
}

