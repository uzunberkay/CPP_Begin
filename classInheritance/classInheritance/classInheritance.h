#pragma once


#include<iostream>

using namespace std;



class baseClass {

private:
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
};