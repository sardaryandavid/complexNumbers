#include "complex.h"

Complex::Complex ()
{
    r = 0;
    im = 0;
}

Complex::Complex (double realPart, double imPart) 
{
    r = realPart;
    im = imPart;
}

Complex::Complex (const Complex& complexNum)
{
    r = complexNum.r;
    im = complexNum.im;
}

Complex::~Complex ()
{
    //empty body
}

Complex& Complex::operator= (const Complex& ComplexNum)
{
    this->r  = ComplexNum.r;
    this->im = ComplexNum.im;

    return *this;
}

Complex& Complex::operator+= (const Complex& ComplexNum)
{
    this->r  += ComplexNum.r;
    this->im += ComplexNum.im;

    return *this;
}

Complex& Complex::operator-= (const Complex& ComplexNum)
{
    this->r  -= ComplexNum.r;
    this->im -= ComplexNum.im;

    return *this;
}

double Complex::cmplxAbs () const
{
    return std::sqrt(this->r * this->r + this->im * this->im);
}

/*************************************************************/

void Complex::operator+() const
{
    return ;
}

Complex Complex::operator-() const
{
    return Complex (-this->r, -this->im);
}

Complex Complex::operator+(const double num)
{ 
    return Complex (this->r + num, this->im); 
}

Complex Complex::operator-(const double num)
{
    return Complex (this->r - num, this->im);
}

Complex Complex::operator*(const Complex& cmplxNum) const
{
    return Complex (this->r * cmplxNum.r - this->im * cmplxNum.im, 
                    this->r * cmplxNum.im + this->im * cmplxNum.r);
}

Complex Complex::operator/(const Complex& cmplxNum) const
{
    int val = cmplxNum.im * cmplxNum.im + cmplxNum.r * cmplxNum.r;

    return Complex ((this->r * cmplxNum.r + this->im * cmplxNum.im) / val,
                    (this->im * cmplxNum.r - this->r * cmplxNum.im) / val);
}

Complex Complex::operator+ (const Complex& cmplx)
{
    return Complex (this->r + cmplx.r, this->im + cmplx.im);
}

Complex Complex::operator- (const Complex& cmplx)
{
    return Complex (this->r - cmplx.r, this->im - cmplx.im);
}

/*************************************************************/

int Complex::operator> (const Complex& cmplxNum) const 
{
    return (this->cmplxAbs () - cmplxNum.cmplxAbs () > EPS) ? YES : NO;
}

int Complex::operator>= (const Complex& cmplxNum) const 
{
    int diff = this->cmplxAbs() - cmplxNum.cmplxAbs();
    return (diff > 0 || std::fabs(diff) < EPS) ? YES : NO;
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
    return (std::fabs(this->r - cmplxNum.r  ) < EPS && 
            std::fabs(this->im - cmplxNum.im) < EPS); 
}

int Complex::operator!= (const Complex& cmplxNum) const 
{
    return !(*this == cmplxNum); 
}

Complex operator+ (double val, Complex& cmplx) 
{
    return Complex (val + cmplx.r, cmplx.im);
}

Complex operator- (double val, Complex& cmplx) 
{
    return Complex (val - cmplx.r, -cmplx.im);
}