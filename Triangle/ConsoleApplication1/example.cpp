#include"Triangle.h"

int main()
{
    float a, b, c;
    cout << "Please enter the sides (a-b-c):" << endl;
    cin >> a >> b >> c;
    Triangle triangle1(a, b, c);
    Triangle triangle2(triangle1);
}

