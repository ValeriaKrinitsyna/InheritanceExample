#pragma once
#include "D1.h"
#include "D2.h"
#include <iostream>
using namespace std;

class D3 : private D1, public D2
{
	int d;
public:
	D3(int x, int y, int z, int i, int j);
	~D3();
};

