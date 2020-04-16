#pragma once
#include <iostream>
using namespace std;

class B
{
	int a;
public:
	B() { cout << "object of " << typeid(*this).name() << " was created" << endl; }
	B(int x) :B() { a = x; }
	~B() { cout << "object of " << typeid(*this).name() << " was destroyed" << endl; }
};

class D1 : public virtual B 
{
	int b;
public:
	D1(int x, int y) : B(y)
	{
		b = x;
		cout << "object of " << typeid(*this).name() << " was created" << endl;
	}
	~D1() { cout << "object of" << typeid(*this).name() << " was destroyed" << endl; }
};

class D2 : protected virtual B 
{
	int c;
public:
	D2(int x, int y) : B(y)
	{
		c = x;
		cout << "object of " << typeid(*this).name() << " was created" << endl;
	}
	~D2() { cout << "object of" << typeid(*this).name() << " was destroyed" << endl; }
};

class D3 : public D2 
{
	int d;
public:
	D3(int x, int y, int z) : D2(y, z)
	{
		d = x;
		cout << "object of " << typeid(*this).name() << " was created" << endl;
	}
	~D3() { cout << "object of" << typeid(*this).name() << " was destroyed" << endl; }
};

class D4 : protected D1, private D3 
{
	int e;
public:
	D4(int x, int y, int z, int i, int k, int l) : D1(y, z), D3(i, k, l)
	{
		e = x;
		cout << "object of " << typeid(*this).name() << " was created" << endl;
	}
	~D4() { cout << "object of" << typeid(*this).name() << " was destroyed" << endl; }
};

