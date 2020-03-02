// InheritanceExample.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "B.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"
#include "D4.h"
#include <iostream>
using namespace std;


int main()
{
	D3 temp(100, 200, 300, 400, 500);
	D4 temp1(1, 2, 3, 4, 5);
	system("pause");
    return 0;
}

