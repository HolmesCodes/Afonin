#include <iostream>
#include <string>
#include "Windows.h"
using namespace std;

//первое наследование и переопределение конструктора/деструктора
class A
{
public:
	A() 
	{
		cout << "Выделена динамическая память A" << endl;
	};
	A(string msg) {
		this->msg = msg;
	}
	void Print() 
	{
		cout << msg << endl;
	};
	virtual ~A() {
		cout << "Освобождена динамическая память A" << endl;
	}

private:
	string msg;
};
class B: public A
{
public:
	B()
	{
		cout << "Выделена динамическая память B" << endl;
	};
	~B() override {
		cout << "Освобождена динамическая память B" << endl;
	}

private:

};
//классы оружия и использования его
class Weapon {
public:
	virtual void Shoot() = 0;
};
class Gun : public Weapon {
public:
	 void Shoot()override
	 {
		cout << "BANG!"<<endl;
	}
};
class SubmachineGun:public Gun {
public:
	  void Shoot() override {
		cout << "BANG!BANG!BANG!BANG!"<<endl;
	}
};
class Bazooka :public Weapon {
public:
	void Shoot() override {
		cout << "BADABUM!" << endl;
	}
};
class Knife :public Weapon {
public:
	void Shoot() override {
		cout << "VJUH!!!" << endl;
	}
};
class Player {
public:
	void Shoot(Weapon* weapon) {
		weapon->Shoot();
	}
};
//класс Human, где делегирующий конструктор
class Human {
public:
	Human(string Name) {
		this->Name = Name;
		this->Weigth = 0;
		this->Age = 0;
	}
	Human(string Name, int Age) :Human(Name) {
		this->Age = Age;
	}
	Human(string Name, int Age, int Weigth) :Human(Name, Age) {
		this->Weigth = Weigth;
	}
	string Name;
	int Weigth;
	int Age;
private:
};
//вызов виртуального метода базового класса
class Msg {
public:
	Msg(string msg) {
		this->msg = msg;
	}
	virtual string GetMsg() {
		return msg;
	}
private:
	string msg;
};
class BraketMsg : public Msg {
public:
	BraketMsg(string msg) :Msg(msg) {

	}
	string GetMsg() override {
		return "[" + ::Msg::GetMsg() + "]";
	}
};
class Printer {
public:
	void Print(Msg* msg) {
		cout << msg->GetMsg() << endl;
	}
private:
};
//множественное наследование. Вызов конструкторов и деструкторов. "ctor + tab" - для экономии времени
class Car {
public:
	string str = "Поле класса машина";
	void Drive() {
		cout << "Я еду!" << endl;
	}
	void Use() {
		cout << "Я еду!" << endl;
	}
	Car()
	{
		cout << "Вызван конструктор Car" << endl;
	}
	~Car()
	{
		cout << "Вызван деструктор Car" << endl;
	}
};
class Airplane {
public:
	string str = "Поле класса самолет";
	void Fly() {
		cout << "Я лечу!" << endl;
	}
	void Use() {
		cout << "Я лечу!" << endl;
	}
	Airplane()
	{
		cout << "Вызван конструктор Airplane" << endl;
	}
	~Airplane()
	{
		cout << "Вызван деструктор Airplane" << endl;
	}

};
class FlyingCar :public Car, public Airplane {
public:
	FlyingCar()
	{
		cout << "Вызван конструктор FlyingCar" << endl;
	}
	~FlyingCar()
	{
		cout << "Вызван деструктор FlyingCar" << endl;
	}
};
//интерфейсы. в с++ они через костыли, но в java они есть
class IBicycle {
public:
	void virtual TwistTheWheel() = 0;
	void virtual Ride() = 0;
};
class BicucleHuman {
public:
	void RideOn(IBicycle & bicycle) {
		cout<<"Крутим руль" << endl;
		bicycle.TwistTheWheel();
		cout << "Поехали" << endl;
		bicycle.Ride();
		cout << "Едем" << endl;
	}
};
class SimpleBicycle :public IBicycle {
public:
	void TwistTheWheel() override {
		cout << "метод TwistTheWheel у SimpleBicycle" << endl;
	}
	void Ride() override {
		cout << "метод Ride у SimpleBicycle" << endl;
	}
};
class SportBicycle:public IBicycle {
public:
	void TwistTheWheel() override {
		cout << "метод TwistTheWheel у SportBicycle" << endl;
	}
	void Ride() override {
		cout << "метод Ride у SportBicycle" << endl;
	}
};
//обычное многоступенчатое наследование. Component вызывается 2 раза, поскольку у двух нследников наследие от Component
class Component {
public:
	Component(string companyName) {
		cout << "конструктор Component" << endl;
		this->companyName = companyName;
	}
	string companyName;
};
class GRU :public Component {
public:
	GRU(string companyName) : Component(companyName)
	{
		cout << "конструктор GRU" << endl;
	}
};
class Memory :public Component {
public:
	Memory(string companyName) : Component(companyName)
	{
		cout << "конструктор Memory" << endl;
	}
};
class GraphicCard :public GRU, public Memory {
public:
	GraphicCard(string GRUcompanyName, string MemorycompanyName):GRU(GRUcompanyName), Memory(MemorycompanyName)
	{
		cout << "конструктор GraphicCard" << endl;
	}
};
//ромбовидное, виртуальное наследование. Character вызывается 1 раз и он один на оба класса Orc и Warrior => 1 общий предок
class Character {
public:
	Character() {
		cout << "вызвался конструктор Character" << endl;
	}
	int HP;
};
class Orc : public virtual Character {
public:
	Orc() {
		cout << "вызвался конструктор Orc" << endl;
	}
};
class Warrior : public virtual Character {
public:
	Warrior() {
		cout << "вызвался конструктор Warrior" << endl;
	}
};
class OrcWarrior : public Orc, public Warrior {
public:
	OrcWarrior() {
		cout << "вызвался конструктор OrcWarrior" << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*A* bptr = new B;
	delete bptr;

	Gun gun;
	SubmachineGun submachineGun;
	Bazooka bazooka;
	Knife knife;
	Player player;
	player.Shoot(&submachineGun);
	
	Human h("Mikhail",19,57);

	Printer printer;
	BraketMsg braketMsg("Mikhail");
	printer.Print(&braketMsg);

	Car car;
	Airplane airplane;
	car.Drive();
	airplane.Fly();
	FlyingCar flyingCar;
	Car* ptrC = &flyingCar;
	Airplane* ptrA = &flyingCar;
	((Car)flyingCar).Use();//приведение типов
	BicucleHuman bicucleHuman;
	SimpleBicycle simpleBicycle;
	SportBicycle sportBicycle;
	bicucleHuman.RideOn(sportBicycle);

	GraphicCard graphicCard("AMD","Sumsung");
	OrcWarrior orcWarrior;*/



	return 0;
}
