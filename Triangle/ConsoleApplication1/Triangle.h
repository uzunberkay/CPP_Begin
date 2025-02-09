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

#endif // !TRIANGLE_H


