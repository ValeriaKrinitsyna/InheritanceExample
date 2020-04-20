#pragma once
#include <iostream>
#include <string>
using namespace std;

class GameObject
{
private:
	string title;
	double mass; //kg
protected:
	GameObject() : mass(0.0) {}
	GameObject(const GameObject& obj) : title(obj.title), mass(obj.mass) {}
	GameObject(const string& _title, double _mass) : title(_title), mass(_mass) {}
	virtual ~GameObject() { cout << "Game object deleted" << endl << endl; }
	virtual void _print() const { cout << "title: " << title << ", mass: " << mass; }

public:

	void print() const
	{
		cout << typeid(*this).name() << " : (";
		_print();
		cout << ")" << endl;
	}
	double get_mass() const
	{
		return mass;
	}
};

class MythicalAnimal : public GameObject
{
private:
	double speed;
public:
	MythicalAnimal() : GameObject() {}
	MythicalAnimal(const MythicalAnimal& obj) : GameObject(obj), speed(obj.speed) {}
	MythicalAnimal(const string& _title, double _mass, double _speed)
		: GameObject(_title, _mass), speed(_speed) {}
	~MythicalAnimal() { cout << "Mythical animal deleted" << endl; }
	double get_speed() const
	{
		return speed;
	}
protected:

	void _print() const
	{
		GameObject::_print();
		cout << " , speed: " << speed;
	}
};

class HumanoidCharacter : public MythicalAnimal
{
private:
	double speed;
public:
	HumanoidCharacter() : MythicalAnimal() {}
	HumanoidCharacter(const HumanoidCharacter& obj) : MythicalAnimal(obj), speed(obj.speed) {}
	HumanoidCharacter(const string& _title, double _mass, double _speed)
		: MythicalAnimal(_title, _mass, _speed) {}
	~HumanoidCharacter() { cout << "Humanoid character deleted" << endl; }
	
protected:

	void _print() const
	{
		MythicalAnimal::_print();
		cout << " , speed: " << speed;
	}
};

class MagicCharacter : public HumanoidCharacter
{
private:
	string power;
public:
	MagicCharacter() : HumanoidCharacter() {}
	MagicCharacter(const MagicCharacter& obj) : HumanoidCharacter(obj), power(obj.power) {}
	MagicCharacter(const string& _title, double _mass, double _speed, string _power)
		: HumanoidCharacter(_title, _mass, _speed), power(_power) {}
	~MagicCharacter() { cout << "Magic character deleted" << endl; }

protected:
	void _print() const
	{
		HumanoidCharacter::_print();
		cout << ", power: " << power;
	}
};

class MagicThing : public GameObject
{
private:
	string use;
public:
	MagicThing() : GameObject() {}
	MagicThing(const MagicThing& obj) : GameObject(obj), use(obj.use) {}
	MagicThing(const string& _title, double _mass, string _use)
		: GameObject(_title, _mass), use(_use) {}
	~MagicThing() { cout << "Magic thing deleted" << endl; }
	string get_use() const
	{
		return use;
	}
protected:

	void _print() const
	{
		GameObject::_print();
		cout << " , use: " << use;
	}
};