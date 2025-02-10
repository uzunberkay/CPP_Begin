#include"complexNumber.h"
int main()
{
    complexNumber c(4, 5);
    c.displayComplex();
    complexNumber c1(4, -3);
    c1.displayComplex();
    c1.setValue(-3, 33);
    c1.displayComplex();

    complexNumber c2 = c1.addComplex(c);

    c2.displayComplex();

    cout << "--------------------------" << endl;

    complexNumber resultMain;
    resultMain = c1.subtractComplex(c);
    resultMain.displayComplex();

    cout << "--------------------------" << endl;
    complexNumber resultMain2;
    resultMain2 = resultMain.multiplyConstant(5);
    resultMain2.displayComplex();

    cout << "-------------------------" << endl;

    complexNumber resultMain3;
    resultMain3 = resultMain2.multiplyComplex(c);
    resultMain3.displayComplex();
    
}


