#include"studentClass.h"

int main()
{
	Student student1("Berkay", "Uzun", "191305008");
	student1.displayInformation();
	student1.setStudentID("13174");
	student1.displayInformation();
	Student st3(student1);
	cout << student1.getStudentID() << endl;


	
}

