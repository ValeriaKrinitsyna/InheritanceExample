#include "stdafx.h"
#include "D3.h"


D3::D3(int x, int y) : D2(x, y)
{
	d = x;
	cout << "object of " << typeid(*this).name() << " was created\n";
}


D3::~D3()
{
	cout << "object of " << typeid(*this).name() << " was destroyed\n";
}
