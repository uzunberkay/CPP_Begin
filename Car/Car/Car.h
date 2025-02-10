#ifndef CAR_H
#define CAR_H

#include<iostream>

using namespace std;


class Car {
	string brand, model;
	int speed;

public:
	Car(const string brand , const string model , const int speed);
	~Car();
	Car(const Car& oth);
	string	getBrand(void)const;
	string	getModel(void)const;
	int	getSpeed(void)const;
	void	setBrand(const string brand);
	void	setSpeed(const int speed);
	void	setModel(const string model);
	void	hizlandir(const int speed);
	void	yavaslat(const int speed);

};

Car::Car(const string brand, const string model, const int speed)
{
	this->brand = brand;
	this->model = model;
	this->speed = speed;

	cout << "Constructor worked! " << endl;

}

Car::~Car()
{
	cout << "Deconstructor worked ! " << endl;
}

Car::Car(const Car& oth)
{
	this->brand = oth.brand;
	this->speed = oth.speed;
	this->model = oth.model;

	cout << "Copied to target" << endl;
}


int	Car::getSpeed(void)const
{
	return this->speed;

}
void	Car::setBrand(const string brand)
{
	this->brand = brand;
}
void	Car::setSpeed(const int speed)
{
	this->speed = speed;
}
void	Car::setModel(const string model)
{
	this->model = model;
}
void	Car::hizlandir(const int speed)
{
	this->speed += speed;
}
void	Car::yavaslat(const int speed)
{
	if (!speed && !(this->speed - speed))
		return;
	this->speed -= speed;
}





#endif