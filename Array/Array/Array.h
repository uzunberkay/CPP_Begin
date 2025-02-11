#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
using namespace std;

class Array {
	int* data, size, capacity;
	int findIndex(int number, int b = 0);
public:
	Array(int user_capacity = 5);
	~Array();
	Array(const Array& oth);
	int getSize()const;
	int getCapacity()const;
	void AddItem(int number);
	void printItems();
	void removeIndexItem(int index);
	void removeItem(int number);
	void findElement(int number, int b = 0);
	void shrinkCapacity();
};

Array::Array(int user_capacity)
{
	this->capacity = user_capacity;
	this->size = 0;
	this->data = new int[this->capacity];
	cout << "Array is created with capacity: " << capacity << endl;
	
}

Array::~Array()
{
	delete[] this->data;
	cout << "Array destroyed " << endl;
}

Array::Array(const Array& oth)
{
	this->capacity = oth.capacity;
	this->size = oth.size;
	this->data = new int[this->capacity];
	for (size_t i = 0; i < oth.size; i++)
	{
		this->data[i] = oth.data[i];

	}
	cout << "Array copied to target" << endl;

}

int Array::getSize()const {
	return this->size;
}
int Array::getCapacity()const
{
	return this->capacity;
}

void Array::AddItem(int number)
{
	if (this->size == this->capacity)
	{
		int* temp = new int[this->capacity * 2];
		for (size_t i = 0; i < this->capacity; i++)
		{
			temp[i] = this->data[i];

		}
		delete[] this->data;
		this->data = temp;
		this->capacity *= 2;

	}
	this->data[this->size++] = number;
}
void Array::printItems() {
	if (!this->size) {
		cout << "Ar" << endl;
	}
	cout << "Array : ";
	for (size_t i = 0; i < this->size; ++i)
	{
		cout << this->data[i] << "  ";

	}

	cout << "\n" << "capacity : " << this->capacity << " size : " << this->size << endl;
}
void Array::removeIndexItem(int index)
{
	if (index < 0 || index >= this->size)
	{
		cout << "ERROR! No item at the index : "<<index << endl;
		return;
	}
	int removeItem = this->data[index];
	for (size_t i = index; i <this->size; i++)
	{
		this->data[i] = this->data[i + 1];

	}
	--this->size;
	cout << "Item: " << removeItem << " is deleted." << endl;
	if (this->size % 5 == 0) shrinkCapacity();

}
void Array::removeItem(int number)
{
	int counter = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		if (data[i] == number) {
			for (size_t j = i; j < this->size; j++)
			{
				data[j] = data[j + 1];

			}
			++counter;
			--i;
		}
	}
	cout << counter << " items (" << number << ")" << "are deleted from the array" << endl;
	this->size -= counter;
	if (this->size % 5 == 0) shrinkCapacity();

}

void Array::shrinkCapacity()
{
	if (this->capacity / 4  >= this->size)
	{
		int* arr = new int[this->capacity / 2]; 
		for (size_t i = 0; i < this->size; ++i)
		{
			arr[i] = this->data[i];
		}

		delete[] this->data;
		this->capacity /= 2;

		this->data = arr;		
	}
}
int Array::findIndex(int number, int index)
{
	
	for (size_t i = index; i < this->size; i++)
	{
		if (this->data[i] == number) { return i; }
	}


	return -1;
}

void Array::findElement(int number, int index)
{
	int result = findIndex(number, index);
	if (result != -1)
	{
		cout << number << "found at index" << endl;
	}
}

#endif