#pragma once
#include <iostream>
#include <string>
using namespace std;

class GameObject
{
private:
	string title;
protected:
	GameObject(const GameObject& obj) : title(obj.title) {}
	GameObject(const string& _title) : title(_title) {}
	virtual ~GameObject() { cout << "Game object deleted" << endl << endl; }
	virtual void _print() const { cout << "title: " << title; }

public:
	virtual void draw() = 0; //prints the new location of an object
	void print() const
	{
		cout << typeid(*this).name() << " : (";
		_print();
		cout << ")" << endl;
	}
};

class Creature : public GameObject
{
private:
	int strength;
	int x;
	int y;
public:
	Creature(const string& _title, int _strength) :GameObject(_title), strength(_strength), x(0), y(0) {}
	Creature(const Creature& obj) :
		GameObject(obj), strength(obj.strength), x(obj.x), y(obj.y) {}
	Creature(const string& _title, int _strength, int _x, int _y) :
		GameObject(_title), strength(_strength), x(_x), y(_y) {}
	void _move(int X, int Y)
	{
		x = X;
		y = Y;
	}
	int getX() { return x; }
	int getY() { return y; }
	~Creature() { cout << "Creature deleted" << endl; }
protected:
	virtual void move(int, int) = 0;
	void  _print()const
	{
		GameObject::_print();
		cout << ", strength: " << strength << ", x: " << x << ", y: " << y;
	}
};


class MythicalAnimal : public Creature
{
private:
	int speed;
public:
	MythicalAnimal(const string& _title,  int _strength, int _speed) :Creature(_title, _strength), speed(_speed) {}
	MythicalAnimal(const MythicalAnimal& obj) : Creature(obj), speed(obj.speed) {}
	MythicalAnimal(const string& _title, int _strength, int _speed, int _x, int _y)
		: Creature(_title, _strength, _x, _y), speed(_speed) {}
	~MythicalAnimal() { cout << "Mythical animal deleted" << endl; }
	void move(int X, int Y)
	{
		Creature::_move(X, Y);
	}
	void draw()
	{
		cout << "Mythical animal is on: (" << getX() << " ; " << getY() << ")" << endl;
	}
protected:
	void _print()const
	{
		Creature::_print();
		cout << ", speed: " << speed;
	}
};

class Humanoid : public Creature
{
private:
	int age;
	int speed;
public:
	Humanoid(const string& _title, int _strength, int _speed, int _age) : Creature(_title, _strength), speed(_speed), age(_age) {}
	Humanoid(const Humanoid& obj) : Creature(obj), speed(obj.speed), age(obj.age) {}
	Humanoid(const string& _title, int _strength, int _x, int _y, int _speed, int _age) :
		Creature(_title, _strength, _x, _y), speed(_speed), age(_age) {}
	~Humanoid() { cout << "Humanoid deleted" << endl; }
	void move(int X, int Y)
	{
		Creature::_move(X, Y);
	}
	void draw()
	{
		cout << "Humanoid is on: (" << getX() << " ; " << getY() << ")\n";
	}
protected:

	void _print()const
	{
		Creature::_print();
		cout << ", speed: " << speed << ", age: " << age;
	}
};

class Wizard : public Humanoid
{
private:
	string power;
public:
	Wizard(const string& _title, int _strength, int _speed, int _age, string _power) : Humanoid(_title, _strength, _speed, _age), power(_power) {}
	Wizard(const Wizard& obj) : Humanoid(obj), power(obj.power) {}
	Wizard(const string& _title, int _strength, int _x, int _y, int _speed, int _age, string _power) :
		Humanoid(_title, _strength, _x, _y, _speed, _age), power(_power) {}
	~Wizard() { cout << "Wizard deleted" << endl; }
	void move(int X, int Y) 
	{
		Humanoid::_move(X, Y);
	}
	void draw() 
	{
		cout << "Wizard is on: (" << getX() << " ; " << getY() << ")\n";
	}
protected:

	void _print()const
	{
		Creature::_print();
		cout << ", power: " << power;
	}
};

class MagicThing : public GameObject
{
private:
	int cost;
	string use;
public:
	MagicThing(const MagicThing& obj) :GameObject(obj), cost(obj.cost), use(obj.use) {}
	MagicThing(const string& _title, int _cost, string _use) : GameObject(_title), cost(_cost), use(_use) {}
	~MagicThing() { cout << "Magic thing deleted\n"; }
	void draw() override {}
protected:
	void _print()const
	{
		GameObject ::_print();
		cout << ", cost: " << cost << ", use: " << use;
	}
};