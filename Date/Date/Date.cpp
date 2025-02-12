#include"Date.h"
int main()
{
    Date d(15, 06, 1999);
	Date d2(15, 06, 1999);

    d.displayDate();
	cout << d2.compareDate(d) << endl;
	for (size_t i = 0; i < 1000; i++)
	{
		d.increaseDay();
		d.displayDate();
	}
	cout << d2.compareDate(d) << endl;
}

