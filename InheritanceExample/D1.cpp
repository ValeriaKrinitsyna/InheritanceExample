#include "stdafx.h"
#include "D1.h"


D1::D1(int x, int y) : B(y)
{
	b = x;
	cout << "object of " << typeid(*this).name() << " was created\n";
}


D1::~D1()
{
	cout << "object of " << typeid(*this).name() << " was destroyed\n";
}
