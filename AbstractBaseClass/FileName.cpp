#include<iostream>
using namespace std;
#define delimiter "\n--------------------------------------------------------------\n"
class Vehicle
{
	int speed;
public:
	virtual void move() = 0;
};
class GroundVehicle :public Vehicle{};
class AirVehicle :public Vehicle 
{
	int height;
public:
	virtual void take_off() = 0;
	virtual void landing() = 0;
};
class car :public GroundVehicle 
{
public:
	void move()
	{
		cout << "Car drives on 4 wheels" << endl;
	}
};

class Bike :public GroundVehicle
{
public:
	void move()
	{
		cout << "Bike drives on 2 wheels" << endl;
	}
};

class Plane :public AirVehicle
{
public:
	void move() 
	{
		cout << "Самолет летит на высокой скорости, и преодадевает большие расстояния"<< endl;
	}
	void take_off()
	{
		cout << "Для взлета нужна ВПП"<<endl;

	}
	void landing()
	{
		cout << "Для посадки тоже нужна ВПП"<< endl;
	}

};
class Helicopter :public AirVehicle
{
public:
	void move()
	{
		cout << "Летает на небольшой высоте и небольшие расстояния, и очень маневренный" << endl;
	}
	void take_off()
	{
		cout << "Взлетает откуда угодно, разгона не требуется" << endl;
	}
	void landing()
	{
		cout << "Преземлится так же можно куда угодно" << endl;
	
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;
	//GroundVehicle gv;
	car bmw;
	bmw.move();
	cout << delimiter;
	Bike harley_davidson;
	harley_davidson.move();

	cout << delimiter;
	Plane boing;
	boing.take_off();
	boing.move();
	boing.landing();

	cout << delimiter;
	Helicopter black_hawk;
	black_hawk.take_off();
	black_hawk.move();
	black_hawk.landing();
}