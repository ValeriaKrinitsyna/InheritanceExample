#pragma once
#include "D1.h"
#include "D2.h"
#include <iostream>
using namespace std;

class D3 : public D2
{
	int d;
public:
	D3(int i, int j);
	~D3();
};

