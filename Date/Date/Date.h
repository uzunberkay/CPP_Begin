#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date {
	int year, month, day;
	const int monthDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const string monthString[12] = { "January","February","March","April","May","June","July","August","September","October","November","December"};

public:
	Date(int d = 1, int m = 1, int y = 1900);
	Date(const Date& oth);
	~Date();
	void setDate(int d = 1, int m = 1, int y = 1800);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void increaseDay();
	long compareDate(const Date& oth);
	void displayDate();
};

void Date::displayDate()
{
	cout << this->day << "/" << monthString[this->month -1 ] << "/" << this->year << endl;
}

Date::Date(int d, int m, int y)
{
	setDate(d, m, y);
}

int Date::getDay()const {
	return this->day;
}
int Date::getMonth()const {
	return this->month;
}
int Date::getYear() const {
	return this->year;
}

Date::~Date()
{
	cout << "Decrustor worked!" << endl;
}
Date::Date(const Date& oth)
{
	this->day = oth.day;
	this->month = oth.month;
	this->year = oth.year;
	cout << "Date copied to target" << endl;
}

void Date::setDay(int d)
{
	this->day = d >= 1 && d <= monthDays[this->month - 1] ? d : 1;
}

void Date::setMonth(int m)
{
	this->month = m >= 1 && m <= 12 ? m :  1;
}

void Date::setYear(int y)
{
	this->year = y >= 1900 ? y : 1900;
}

void Date::setDate(int d, int m, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::increaseDay()
{
	if (this->day < monthDays[this->month - 1]) { ++this->day; }
	else {  
		this->day = 1;
		if (this->month < 12)
			++this->month;
		else
		{
			this->month = 1;
			++this->year;
		}

	}



}

long Date::compareDate(const Date& oth)
{
	size_t firstDay;
	size_t secondDay;
	firstDay = this->year * 365 + this->year * 30 + this->day;
	secondDay = oth.year * 365 + oth.year * 30 + oth.day;

	return firstDay - secondDay;
}


#endif