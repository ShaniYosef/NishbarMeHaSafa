//
// Created by user-pc on 18/09/2017.
//
#include <iostream>
#include <math.h>
using namespace std;
#include "Fraction.h"


Fraction::Fraction(int numerator ,int denominator): m_numerator(numerator),m_denominator(denominator) {}

Fraction::Fraction(int number): m_numerator(number),m_denominator(1) {}

Fraction::Fraction() : m_numerator(0), m_denominator(0){}

Fraction::Fraction(double number)
{
    int power = pow(10,6);
    float fracPart, intPart;
    fracPart = modff(number,&intPart);
    m_numerator = intPart*power+int(fracPart*power);
    m_denominator = power;

    this->simplify();
}

Fraction::Fraction(const Fraction &other)
{
    m_denominator = other.m_denominator;
    m_numerator = other.m_numerator;
}


Fraction Fraction::operator*(const Fraction &other) const
{
    return(Fraction(m_numerator*other.m_numerator,m_denominator*other.m_denominator).simplify());
}

Fraction Fraction::operator/(const Fraction &other) const
{
    return(Fraction(m_numerator*other.m_denominator,m_denominator*other.m_numerator).simplify());
}

Fraction Fraction::operator+(const Fraction &other) const
{
    return(Fraction((m_numerator*other.m_denominator)+(m_denominator*other.m_numerator),m_denominator*other.m_denominator).simplify());
}

Fraction Fraction::operator-(const Fraction &other) const
{
    return(Fraction((m_numerator*other.m_denominator)-(m_denominator*other.m_numerator),m_denominator*other.m_denominator).simplify());
}

Fraction Fraction::operator-() const
{
    return (Fraction(this->operator*(-1)));
}

Fraction& Fraction::operator*=(const Fraction &other)
{
    m_numerator *= other.m_numerator;
    m_denominator *= other.m_denominator;
    return  this->simplify();
}


Fraction& Fraction::operator/=(const Fraction &other)
{
    m_numerator *= other.m_denominator;
    m_denominator *= other.m_numerator;
    return  this->simplify();
}

Fraction& Fraction::operator-=(const Fraction &other)
{
    m_numerator = m_numerator*other.m_denominator - other.m_numerator*m_denominator;
    m_denominator *= other.m_denominator;
    return  this->simplify();
}

Fraction& Fraction::operator+=(const Fraction &other)
{
    m_numerator = m_numerator*other.m_denominator + other.m_numerator*m_denominator;
    m_denominator *= other.m_denominator;
    return  this->simplify();
}

void Fraction::operator--()
{
    (*this)-=1;
    simplify();
}

void Fraction::operator++()
{
    (*this)+=1;
    simplify();
}

float Fraction::cvt2Float () const
{
    return (float(m_numerator)/float(m_denominator));
}

void Fraction::print()const
{
    cout<<m_numerator<<'/'<<m_denominator << endl;
}


Fraction& Fraction::simplify()
{
    int gcd = __gcd(m_numerator,m_denominator);

    m_numerator /= gcd;
    m_denominator /= gcd;

    return *this;
}
