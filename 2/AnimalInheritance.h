#pragma once
#include <iostream>
#include <string>
using namespace std;

// �����, ����������� ��������
class creature
{
private:
	string title;
	double mass; //kg
protected:
	creature() : mass(0.0) {}
	creature(const creature& obj) : title(obj.title), mass(obj.mass) {}
	creature(const string& _title, double _mass) : title(_title), mass(_mass) {}
	// ���������� (�������� ��� �����������)
	virtual ~creature() { cout << "creature deleted" << endl << endl; }
	// ����������� ������� ��� ������ ���������� �� �������
	virtual void _print() const { cout << "title: " << title << ", mass: " << mass; }
	
public:

	// �������� ������� ��� ������ ���������� �� �������
	void print() const
	{
		cout << typeid(*this).name() << " : (";
		// ����� ����������� �������
		// �.�. ������� _print �����������, ���������� ��� �����
		// �� ������ �� �������� ������, �� � �� �����������,
		// � ����������� �� ����, ��� ������ ������� �������������� �����
		_print();
		cout << ")" << endl;
	}
	double get_mass() const
	{
		return mass;
	}
};

// ����� animal ����������� �� ������ creature
class animal : public creature
{
private:
	double speed; //m/s
public:
	animal() : creature() {}
	animal(const animal& obj) : creature(obj), speed(obj.speed) {}
	animal(const string& _title, double _mass, double _speed)
		: creature(_title, _mass), speed(_speed) {}
	~animal() { cout << "animal deleted" << endl; }
	double get_speed() const
	{
		return speed;
	}
protected:
	// ����������� ������� _print ���������������� � ����������� ������
	void _print() const
	{
		creature::_print();
		cout << " , speed: " << speed;
	}
};

// ����� bird ����������� �� ������ animal
class bird : public animal
{
private:
	double topfly; //km
public:
	bird() : animal() {}
	bird(const bird& obj) : animal(obj), topfly(obj.topfly) {}
	bird(const string& _title, double _mass, double _speed, double _topfly)
		: animal(_title, _mass, _speed), topfly(_topfly) {}
	~bird() { cout << "bird deleted" << endl; }
protected:
	// ����������� ������� _print ���������������� � ������ bird
	void _print() const
	{
		animal::_print();
		cout << ", topfly: " << topfly;
	}
};

// ����� fish ����������� �� ������ animal
class fish : public animal
{
private:
	double maxdeep; //km
public:
	fish() : animal() {}
	fish(const fish& obj) : animal(obj), maxdeep(obj.maxdeep) {}
	fish(const string& _title, double _mass, double _speed, double _maxdeep)
		: animal(_title, _mass, _speed), maxdeep(_maxdeep) {}
	~fish() { cout << "fish deleted" << endl; }

protected:
	// ����������� ������� _print ���������������� � ������ fish
	void _print() const
	{
		animal::_print();
		cout << ", maxdeep: " << maxdeep;
	}
};

// ����� predator ����������� �� animal
class predator : public animal
{
protected:
	predator() {}
public:
	~predator() {}
	// ����� ����������� ������� hunt ����� ����������
	// ����������� ����������� �������,
	// ������� �� ������� ����������� �� ������ (obj)
	virtual bool hunt(const animal& obj) = 0;
	// �.�. hunt ����� �����������, ����� predator �������� �����������
};

// ������������ ������������� ������������, �.�. ���� � � �����, � ������
class eagle : public bird, public predator
{
public:
	eagle() : bird() {}
	eagle(const eagle& obj) : bird(obj) {}
	eagle(double _mass, double _speed, double _topfly)
		: bird("����", _mass, _speed, _topfly) {}
	// ����������� ���� ������� hunt
	// �.�. hunt ����������, ����� eagle � ������������
	bool hunt(const animal& obj)
	{
		// ������� get_mass ����� ������������� ������� eagle �� ������ animal
		// � ����� ����� bird, � ����� ����� predator
		// ����� �������, ��� ��� ����������� ����� bird
		return obj.get_mass() < bird::get_mass()
			&& obj.get_speed() < bird::get_speed();
	}
};