#include "complex.h"

Complex::Complex ()
{
    r = 0;
    im = 0;
};

/*************************************************************/

Complex::Complex (double realPart, double imPart) 
{
    r = realPart;
    im = imPart;
}

/*************************************************************/

Complex::Complex (const Complex& complexNum)
{
    r = complexNum.r;
    im = complexNum.im;
}

/*************************************************************/

Complex Complex::operator= (const Complex& ComplexNum)
{
    return Complex (ComplexNum.r, ComplexNum.im);
}

/*************************************************************/

double Complex:: cmplxAbs () const
{
    return this->r * this->r + this->im * this->im;
}

/*************************************************************/

Complex Complex::operator+(const Complex& cmplxNum) const
{
    return Complex (this->r + cmplxNum.r, this->im + cmplxNum.im);
}

/*************************************************************/

Complex operator+(const Complex& cmplxNum, const double num)
{ 
    return Complex (cmplxNum.r + num, cmplxNum.im); 
}

/*************************************************************/

Complex operator-(const Complex& cmplxNum, const double num)
{
    return Complex (cmplxNum.r - num, cmplxNum.im);
}

/*************************************************************/

Complex Complex::operator-(const Complex& cmplxNum) const
{
    return Complex (this->r - cmplxNum.r, this->im - cmplxNum.im);
}

/*************************************************************/

Complex Complex::operator*(const Complex& cmplxNum) const
{
    return Complex (this->r * this->im - cmplxNum.r * cmplxNum.im, 
                    this->r * cmplxNum.im - this->im * cmplxNum.r);
}

/*************************************************************/

Complex Complex::operator/(const Complex& cmplxNum) const
{
    int val = cmplxNum.im * cmplxNum.im + cmplxNum.r * cmplxNum.r;

    return Complex ((this->r * cmplxNum.r + this->im * cmplxNum.im) / val,
                    (this->im * cmplxNum.r - this->r * cmplxNum.im) / val);
}
/*************************************************************/

Complex::~Complex ()
{
    printf ("I was in destructor\n");
}

/*************************************************************/

void Complex::print () const
{
    printf ("%.02f + (%.02f)i\n", this->r, this->im);
}

/*************************************************************/

int Complex::operator> (const Complex& cmplxNum) const 
{
    return (this->cmplxAbs () - cmplxNum.cmplxAbs () > EPS) ? YES : NO;
}

int Complex::operator>= (const Complex& cmplxNum) const 
{
    int diff = this->cmplxAbs() - cmplxNum.cmplxAbs();
    return (diff > 0 || fabs(diff) < EPS) ? YES : NO;
}

int Complex::operator< (const Complex& cmplxNum) const 
{
    return !(*this >= cmplxNum);
}

int Complex::operator<= (const Complex& cmplxNum) const 
{
    return !(*this > cmplxNum);
}

int Complex::operator== (const Complex& cmplxNum) const 
{
    return (fabs(this->r - cmplxNum.r) < EPS && fabs(this->im - cmplxNum.im) < EPS); 
}

int Complex::operator!= (const Complex& cmplxNum) const 
{
    return !(*this == cmplxNum); 
}

/*************************************************************/

Complex operator+ (const Complex& cmplx1, const Complex& cmplx2)
{
    return Complex (cmplx1.r + cmplx2.r, cmplx1.im + cmplx2.im);
}

/*************************************************************/

Complex operator- (const Complex& cmplx1, const Complex& cmplx2)
{
    return Complex (cmplx1.r - cmplx2.r, cmplx1.im - cmplx2.im);
}