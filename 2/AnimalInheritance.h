#pragma once
#include <iostream>
#include <string>
using namespace std;

// класс, описывающий существо
class creature
{
private:
	string title;
	double mass; //kg
protected:
	creature() : mass(0.0) {}
	creature(const creature& obj) : title(obj.title), mass(obj.mass) {}
	creature(const string& _title, double _mass) : title(_title), mass(_mass) {}
	// деструктор (объ€влен как виртуальный)
	virtual ~creature() { cout << "creature deleted" << endl << endl; }
	// виртуальна€ функци€ дл€ вывода информации об объекте
	virtual void _print() const { cout << "title: " << title << ", mass: " << mass; }
	
public:

	// открыта€ функци€ дл€ вывода информации об объекте
	void print() const
	{
		cout << typeid(*this).name() << " : (";
		// вызов виртуальной функции
		// т.к. функци€ _print виртуальна€, вызыватьс€ она будет
		// не только из текущего класса, но и из производных,
		// в зависимости от того, дл€ какого объекта осуществл€етс€ вызов
		_print();
		cout << ")" << endl;
	}
	double get_mass() const
	{
		return mass;
	}
};

// класс animal наследуетс€ от класса creature
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
	// виртуальна€ функци€ _print переопредел€етс€ в производном классе
	void _print() const
	{
		creature::_print();
		cout << " , speed: " << speed;
	}
};

// класс bird наследуетс€ от класса animal
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
	// виртуальна€ функци€ _print переопредел€етс€ в классе bird
	void _print() const
	{
		animal::_print();
		cout << ", topfly: " << topfly;
	}
};

// класс fish наследуетс€ от класса animal
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
	// виртуальна€ функци€ _print переопредел€етс€ в классе fish
	void _print() const
	{
		animal::_print();
		cout << ", maxdeep: " << maxdeep;
	}
};

// класс predator наследуетс€ от animal
class predator : public animal
{
protected:
	predator() {}
public:
	~predator() {}
	// чисто виртуальна€ функци€ hunt будет определ€ть
	// посредством производных классов,
	// удастс€ ли хищнику поохотитьс€ на жертву (obj)
	virtual bool hunt(const animal& obj) = 0;
	// т.к. hunt чисто виртуальна€, класс predator €вл€етс€ абстрактным
};

// используетс€ множественное наследование, т.к. орел Ц и птица, и хищник
class eagle : public bird, public predator
{
public:
	eagle() : bird() {}
	eagle(const eagle& obj) : bird(obj) {}
	eagle(double _mass, double _speed, double _topfly)
		: bird("ќрел", _mass, _speed, _topfly) {}
	// определение тела функции hunt
	// т.к. hunt определена, класс eagle Ц Ќ≈абстракный
	bool hunt(const animal& obj)
	{
		// функци€ get_mass может наследоватьс€ классом eagle из класса animal
		// и через класс bird, и через класс predator
		// нужно указать, что она наследуетс€ через bird
		return obj.get_mass() < bird::get_mass()
			&& obj.get_speed() < bird::get_speed();
	}
};