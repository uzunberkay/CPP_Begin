#include"Matris.h"

int main()
{
	Matrix m(5, 5);
	Matrix m2(5, 5);
	
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			m.setValue(i,j, i * j);
		}

	}
	m.display();
	m.randomSet();
	m.display();
	m2.randomSet();
	//m.identityMatrixSet();
	m.display();

	m.addMatrix(m2);
}


