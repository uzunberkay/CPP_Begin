#ifndef TRIANGLE_H
#define TRIANGLE_H


#include<iostream>

using namespace std;

class Triangle {
	float sideA, sideB, sideC;

public:
	Triangle( float sideA,  float sideB,  float sideC);
	Triangle(const Triangle& oth);
	~Triangle();
	bool	isTriangle(float sideA, float sideB, float sideC);
	float	getSideA(void) const;
	float	getSideB(void) const;
	float	getSideC(void) const;
	void	setSideA(const float sideA);
	void	setSideB(const float sideB);
	void	setSideC(const float sideC);
	void	setValue(float sideA, float sideB, float sideC);
	bool	isEquilateral();
	bool	isScalene();
	bool	isIsosceles();
	void	trinagleType();
	float	calculateArea();

};

Triangle::Triangle(float a, float b, float c)
{
	while (!isTriangle( a, b, c))
	{
		cout << "Please enter the sides (a-b-c):" << endl;
		cin >> a >> b >> c;
	}

	this->sideA = a;
	this->sideB = b;
	this->sideC = c;
	cout << "Triangle created." << endl;

}
Triangle::~Triangle()
{
	cout << "Triangle destroyed." << endl;
}
Triangle::Triangle(const Triangle& oth)
{
	this->sideA = oth.sideA;
	this->sideB = oth.sideB;
	this->sideC = oth.sideC;

	cout << "Triangle copied to target." << endl;
	
}
bool Triangle::isTriangle(float sideA, float sideB, float sideC)
{
	/*
	* sideA :  |sideB - sideC| < sideA < sideB + sideC
	* sideB :  |sideA - sideC| < sideB < sideA + sideC
	* sideC :  |sideB - sideA| < sideC < sideB + sideA
	*/

	if (!((abs)(sideB - sideC) < sideA && sideA < sideB + sideC))
	{
		cout << "Invalid A" << endl;
		return false; 
	}
	if (!((abs)(sideA - sideC) < sideB && sideB < sideA + sideC))
	{
		cout << "Invalid B" << endl;
		return false;
	}
	if (!((abs)(sideB - sideA) < sideC && sideC < sideB + sideA))
	{
		cout << "Invalid C" << endl;
		return false;
	}

	return true;
}


float Triangle::getSideA(void) const {


	return this->sideA;
}

float Triangle::getSideB(void)const {
	return this->sideB;
}

float Triangle::getSideC(void) const
{
	return this->sideC;
}


void Triangle::setValue(float a, float b, float c)
{
	while (!isTriangle(a, b, c))
	{
		cout << "Please enter the sides (a-b-c):" << endl;
		cin >> a >> b >> c;
	}

	this->sideA = a;
	this->sideB = b;
	this->sideC = c;
}

bool Triangle::isEquilateral()
{
	return this->sideA == this->sideB && this->sideB == this->sideC;
}

bool Triangle::isIsosceles()
{
	if (isEquilateral())
		return true;		

	return this->sideA == this->sideB || this->sideA == this->sideC || this->sideB == this->sideC;
}

bool Triangle::isScalene()
{
	return !isEquilateral();
}

void Triangle::trinagleType()
{
	if (isEquilateral())
		cout << "Equilateral Triangle " << endl;
	else if (isIsosceles())
		cout << "Isosceles Triangle " << endl;
	else
		cout << "Scalene Triangle " << endl;
}

float Triangle::calculateArea()
{
	float area;
	if (isEquilateral()) {
		return  (pow(this->sideA, 2) * sqrt(3) / 4);
	}
	float s = (this->sideA + this->sideB + this->sideC) / 2;
	return sqrt(s * (s - this->sideA) * (s - this->sideB) * (s - this->sideC));
}

#endif // !TRIANGLE_H


