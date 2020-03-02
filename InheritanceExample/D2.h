#pragma once
#include "B.h"
#include <iostream>
using namespace std;

class D2 : private B
{
	int c;
public:
	D2(int x, int y);
	~D2();
};

