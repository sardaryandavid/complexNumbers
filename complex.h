#pragma once 

#include <iostream>
#include <cmath>

struct Complex
{
    const double EPS = 10e-6;

    enum {NO = 0, YES};

    double r;
    double im;

    Complex ();
    Complex (const Complex& );
    Complex (double, double );
    ~Complex ();

    Complex operator+ (const Complex& ) const;
    Complex operator- (const Complex& ) const;

    Complex operator+ (const double ) const;
    Complex operator- (const double ) const;

    void operator+ () const;
    Complex operator- () const;

    Complex operator* (const Complex& ) const;
    Complex operator/ (const Complex& ) const;
    Complex& operator= (const Complex& );
    Complex& operator+= (const Complex& );
    Complex& operator-= (const Complex& );

    int operator>  (const Complex& ) const;
    int operator>= (const Complex& ) const;
    int operator<  (const Complex& ) const;
    int operator<= (const Complex& ) const;
    int operator== (const Complex& ) const;
    int operator!= (const Complex& ) const;
    
    double cmplxAbs () const;
};

Complex operator+ (double val, Complex& cmplx);
Complex operator- (double val, Complex& cmplx);
