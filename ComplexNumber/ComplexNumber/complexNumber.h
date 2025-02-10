#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>

using namespace std;

class complexNumber
{
private:
	int real, img;
public:
	complexNumber(int r = 0 , int i = 0);
	~complexNumber();
	complexNumber(const complexNumber& oth);
	int getReal()const;
	int getImag()const;
	void setValue(int r = 0, int i = 0);
	complexNumber addComplex(const complexNumber& oth);
	complexNumber multiplyComplex(const complexNumber& oth);
	complexNumber subtractComplex(complexNumber& oth);
	complexNumber multiplyConstant(int constant);
	void		  multiplyMinus();
	void		  displayComplex();




};

complexNumber::complexNumber(int r, int i)
{
	this->real	= r;
	this->img	= i;
	cout << "Complex number  created." << endl;


}

complexNumber::~complexNumber()
{
	cout << "Complex Number destroyed." << endl;
}

complexNumber::complexNumber(const complexNumber& oth)
{
	this->real = oth.real;
	this->img  = oth.img;
	cout << "Complex Number copied to target" << endl;
}

int complexNumber::getReal()const { return this->real; }
int complexNumber::getImag()const { return this->img; }
void complexNumber::setValue(int r, int i) {
	this->real = r;
	this->img = i;
}
void complexNumber::displayComplex()
{
	this->img >= 0 ? cout << this->real << "+" << this->img <<"i"<< endl : cout << this->real << this->img <<"i" << endl;

}

complexNumber complexNumber::addComplex(const complexNumber& oth)
{
	complexNumber result;
	result.real = this->real + oth.real;
	result.img = this->img + oth.img;

	return result;
}

complexNumber complexNumber::subtractComplex(complexNumber& oth)
{
	complexNumber result;
	oth.multiplyMinus();
	result = addComplex(oth);
	return result;
}

void complexNumber::multiplyMinus()
{
	this->real *= -1;
	this->img *= -1;
}

complexNumber complexNumber::multiplyConstant(int constant)
{
	complexNumber result;
	result.real = this->real * constant;
	result.img = this->img * constant;


	return result;
}

complexNumber complexNumber::multiplyComplex(const complexNumber& oth)
{
	complexNumber result;
	result.real = this->real * oth.real - this->img * oth.img;
	result.img = this->real * oth.img + this->img * oth.real;


	return result;
}

#endif