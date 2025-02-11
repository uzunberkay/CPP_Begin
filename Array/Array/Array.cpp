#include"Array.h"

int main()
{
    Array arr;
    Array arr2(arr);

	for (size_t i = 0; i < 25; i++)
	{
		arr.AddItem(i);

	}
	for (size_t i = 0; i < 25; i++)
	{
		arr.AddItem(i);

	}

	arr.printItems();
	cout << "--------------------------------------" << endl;
	arr.removeIndexItem(3);
	arr.printItems();
	cout << "--------------------------------------" << endl;
	arr.removeIndexItem(0);
	arr.printItems();
	cout << "--------------------------------------" << endl;
	arr.removeIndexItem(22);
	arr.printItems();
	cout << "--------------------------------------" << endl;
	arr.removeItem(2);

	for (size_t i = 0; i < 20; i++)
	{
		arr.removeIndexItem(i);
	}
	for (size_t i = 0; i < 5; i++)
	{
		arr.removeIndexItem(i);
	}
	arr.printItems();
}
