#include <iostream>

using namespace std;


class Student {
private:
	string studentName, studentSurname, stundentID;  // üye deðiþkenleri (member variables)
public:
	void displayInformation();	// Üye fonksiyonu (member function)
	Student(const string name, const string surname, const string ID);
	~Student();
	string getStudentName(void);
	string getStudentSurname(void);
	string getStudentID(void);
	void   setStudentName(const string name);
	void   setStudentSurname(const string surname);
	void   setStudentID(const string id);
};

void Student::displayInformation()
{
	cout << "Name: " << getStudentName() << " Surname : " << getStudentSurname() << " ID: " << getStudentID() << endl;
}

Student::Student(const string name, const string surname, const string ID)
{
	
	studentName = name;
	studentSurname = surname;
	stundentID = ID;
}
string Student::getStudentName(void)
{
	return this->studentName;
}
string Student::getStudentSurname(void)
{
	return this->studentSurname;
}
string Student::getStudentID(void)
{
	return this->stundentID;
}

void Student::setStudentName(const string name)
{
	this->studentName = name;
}
void Student::setStudentSurname(const string surname)
{
	this->studentSurname = surname;
}
void Student::setStudentID(const string id)
{
	this->stundentID = id;
}

Student::~Student()
{
	cout << "Nesne yok edildi ! " << endl;
}