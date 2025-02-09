#include"studentClass.h"

int main()
{
	Student student1("Berkay", "Uzun", "191305008");
	student1.displayInformation();
	student1.setStudentID("13174");
	student1.displayInformation();
	int x; 
	cout << student1.getStudentID() << endl;


	
}

