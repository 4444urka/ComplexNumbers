#include <iostream>
#include "ComplexNumber/ComplexNumber.h"
#include "RationalNumber/RationalNumber.h"

using namespace std;

int main()
{
    ComplexNumber a({1, 1}, {-1, 1});
    ComplexNumber b({1, 1}, {1, 1});
    RationalNumber c(1, 2);

    cout << c;
}