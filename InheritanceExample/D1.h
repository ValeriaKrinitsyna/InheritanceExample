#pragma once
#include "B.h"
#include <iostream>
using namespace std;

class D1 : public B
{ 
	int b;
public:
	D1(int x, int y);
	~D1();
};

