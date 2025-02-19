#pragma once


#include<iostream>

using namespace std;

class baseClass {

protected:
	int x;

public:
	void setX(int x)
	{
		this->x = x;
	}
	int  getX()const { return this->x; }
	void print()
	{
		cout << "X : " << this->x << endl;
	}
	baseClass(int mainX = 0)
	{
		cout << "Base class constructor worked" << endl;
	}
	~baseClass()
	{
		cout << "Base class deconstructor worked" << endl;
	}
	baseClass(const baseClass& oth)
	{
		this->x = oth.x;
		cout << "Base class copy constructor worked." << endl;	
	}
};

class derivedClass :public baseClass {
public:
	int y;
	void setY(int y)
	{
		this->y = y;
	}
	int	getY()const {
		return this->y;
	}
	void printY()
	{
		cout << "Y : " << this->y << endl;
	}

	derivedClass(int mainX = 0, int mainY = 0)
	{
		this->x = mainX;
		this->y = mainY;

		cout << "Derived class constructor worked." << endl;
	}
	~derivedClass()
	{
		cout << "Derived class destructor worked." << endl;
	}
	derivedClass(const derivedClass& oth)
	{
		this->x = oth.x;
		this->y = oth.y;
		cout << "Derived class copy constructor worked." << endl;
	}
};