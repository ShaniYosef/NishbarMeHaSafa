#include <iostream>
#include "Fraction.h"
using namespace std;


Fraction operator*(double first, Fraction& second)
{
    return (Fraction(first)*=second);
}

Fraction operator+(double first, Fraction& second)
{
    return (Fraction(first)+=second);
}

Fraction operator-(double first, Fraction& second)
{
    return (Fraction(first)-=second);
}

Fraction operator/(double first, Fraction& second)
{
    return (Fraction(first)/=second);
}

int main() {

    return 0;
}