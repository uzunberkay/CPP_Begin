#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


#include<iostream>
using namespace std;


class bankAccount {
	float accountBalance;
	string personName, personSurname, personPhone;
public:
	bankAccount(string name, string surname, float balance = 0, string phone_number = "");
	bankAccount(const bankAccount& oth);
	~bankAccount();
	bool controlNameSurname(string nameOrSurname);
	bool controlPhoneNumber(string phoneNumber);
	void displayProfile();
	void credit(float); // para yatýrma
	void withdraw(float);
	void sendMoney(bankAccount& oth, float amount);
	void setPersonName(string name);
	void setPersonSurName(string surname);
	void setPersonBalance(float balance = 0);
	void setPersonPhone(string phone);
	float getPersonBalance()const;
	string getPersonName()const;
	string getPersonSurName()const;
	string getPersonPhone()const;
};

bankAccount::bankAccount(string name, string surname, float balance, string phone_number)
{
	setPersonName(name);
	setPersonSurName(surname);
	setPersonBalance(balance);
	setPersonPhone(phone_number);

}
bankAccount::bankAccount(const bankAccount& oth)
{
	this->personName = oth.personName;
	this->personSurname = oth.personSurname;
	this->personPhone = oth.personPhone;
	this->accountBalance = oth.accountBalance;
}
bankAccount::~bankAccount()
{
	cout << "Destructor worked ! " << endl;
}
void bankAccount::credit(float money)
{
	this->accountBalance += money;
}
void bankAccount::displayProfile()
{
	cout << "Name : " << this->personName << " Surname : " << this->personSurname << " Phone : " << this->personPhone << " Balance : " << this->accountBalance << endl;
}

void bankAccount::setPersonName(string name)
{
	while (!controlNameSurname(name))
	{
		cout << "Lutfen isim giriniz : ";
		cin >> name;
	}
	this->personName = name;

}

void bankAccount::setPersonSurName(string surname)
{
	while (!controlNameSurname(surname))
	{
		cout << "Lutfen gecerli bir soy isim giriniz : ";
		cin >> surname;
	}
	this->personSurname = surname;
}
void bankAccount::setPersonBalance(float balance)
{

	if (balance < 0.0)
	{
		balance = 0.0;
	}
	this->accountBalance = balance;
}
void bankAccount::setPersonPhone(string phoneNumber)
{
	if (!controlPhoneNumber(phoneNumber))
	{
		phoneNumber = "";
	}
	this->personPhone = phoneNumber;
}


void bankAccount::sendMoney(bankAccount& oth, float amount)
{
	if (this->accountBalance < amount)
	{
		cout << "Bakiyen yetersiz !" << endl;
		return;
	}
	oth.accountBalance += amount;
	this->accountBalance -= amount;
}

bool bankAccount::controlNameSurname(string nameorSurname)
{
	for (size_t i = 0; i < nameorSurname.length(); ++i)
	{
		if (!((nameorSurname[i] >= 'a' && nameorSurname[i] <= 'z') || (nameorSurname[i] >= 'A' && nameorSurname[i] <= 'Z')))
		{
			return false;
		}
	}

	return true;
}


bool bankAccount::controlPhoneNumber(string phoneNumber)
{
	if (phoneNumber.size() != 11) { return false; }
	for (size_t i = 0; i < phoneNumber.length(); ++i)
	{
		if (!(phoneNumber[i] >= '0' && phoneNumber[i] <= '9'))
		{
			return false;
		}
	}

	return true;
}

string bankAccount::getPersonName()const { return this->personName;}
string bankAccount::getPersonSurName()const { return this->personSurname; }
string bankAccount::getPersonPhone()const { return this->personPhone; }
float bankAccount::getPersonBalance()const { return this->accountBalance; }

#endif