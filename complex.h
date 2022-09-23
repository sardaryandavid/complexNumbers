#pragma once 

#include <iostream>
#include <stdio.h>
#include <cmath>

enum {NO = 0, YES};

#define EPS 10e-6
struct Complex
{
    double r;
    double im;

    Complex ();
    Complex (const Complex& );
    Complex (double, double);
    ~Complex ();

    friend Complex operator+ (const Complex&, const Complex& );
    friend Complex operator- (const Complex&, const Complex& );

    friend Complex operator+ (const Complex&, const double );
    friend Complex operator- (const Complex&, const double );
    Complex operator+ (const Complex& ) const;
    Complex operator- (const Complex& ) const;
    Complex operator* (const Complex& ) const;
    Complex operator/ (const Complex& ) const;
    Complex operator= (const Complex& );

    int operator>  (const Complex& ) const;
    int operator>= (const Complex& ) const;
    int operator<  (const Complex& ) const;
    int operator<= (const Complex& ) const;
    int operator== (const Complex& ) const;
    int operator!= (const Complex& ) const;
    
    void print () const;
    double cmplxAbs () const;
};