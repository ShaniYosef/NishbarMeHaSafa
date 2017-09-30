//
// Created by user-pc on 18/09/2017.
//

#ifndef UNTITLED2_FRACTION_H
#define UNTITLED2_FRACTION_H


class Fraction{

public:

    Fraction(int nominator,int denominator); //c'tor get 2 integers and create fraction
    Fraction(int number); //c'tor get 1 integers and create fraction
    Fraction(double); //c'tor get 1 double and create fraction
    Fraction(const Fraction &f); //copy c'tor get fraction and same create fraction
    Fraction(); // empty fraction

    Fraction operator*(const Fraction &other) const;
    Fraction operator/(const Fraction &other) const;
    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator-() const;

    Fraction& operator*=(const Fraction &other);
    Fraction& operator/=(const Fraction &other);
    Fraction& operator-=(const Fraction &other);
    Fraction& operator+=(const Fraction &other);


    void operator--();
    void operator++();

    float cvt2Float () const;
    void print()const ;



private:
    int  m_numerator;
    int m_denominator;
    Fraction& simplify(); // simplify the fraction
};


#endif //UNTITLED2_FRACTION_H
