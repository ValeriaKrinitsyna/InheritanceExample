#pragma once
#include "D1.h"
#include "D2.h"
#include <iostream>
using namespace std;

class D4 : public D2, private D1
{
	int e;
public:
	D4(int x, int y, int z, int i, int j);
	~D4();
};

