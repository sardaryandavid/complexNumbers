#include "tests.h"

void test_func()
{
    test_sum_cmplx ();
    test_sub_cmplx ();
    test_div ();
    test_mul ();

    test_sum_double ();
    test_sub_double ();

    test_sum_double_cmplx ();
    test_sub_double_cmplx ();

    test_abs ();
}

void test_sum_cmplx ()
{
    Complex cmplx1 (4, 5);
    Complex cmplx2 (3, 2);
    Complex cmplx3 (7, 7);
   
    assert (cmplx3 == cmplx1 + cmplx2);
}

void test_sub_cmplx ()
{
    Complex cmplx1 (4, 5);
    Complex cmplx2 (3, 2);
    Complex cmplx3 (1, 3);
   
    assert (cmplx3 == cmplx1 - cmplx2);
}

void test_div ()
{
    Complex cmplx1 (8, 10);
    Complex cmplx2 (2, 4);
    Complex cmplx3 (2.8, -0.6);

    assert (cmplx3 == cmplx1 / cmplx2);
}

void test_mul ()
{
    Complex cmplx1 (8, 10);
    Complex cmplx2 (2, 4);
    Complex cmplx3 (-24, 52);

    assert (cmplx3 == cmplx1 * cmplx2);
}

void test_sum_double ()
{
    double a = 5.5;
    Complex cmplx1 (4, 10);
    Complex cmplx2 (9.5, 10);

    assert (cmplx2 == cmplx1 + a);
}

void test_sub_double ()
{
    double a = 5.5;
    Complex cmplx1 (4, 10);
    Complex cmplx2 (-1.5, 10);

    assert (cmplx2 == cmplx1 - a);
}

void test_sum_double_cmplx ()
{
    double a = 5.5;
    Complex cmplx1 (4, 10);
    Complex cmplx2 (9.5, 10);

    assert (cmplx2 == a + cmplx1);    
}

void test_sub_double_cmplx ()
{
    double a = 5.5;
    Complex cmplx1 (4, 10);
    Complex cmplx2 (1.5, -10);

    assert (cmplx2 == a - cmplx1);    
}

void test_abs ()
{
    Complex cmplx (3, 4);
    double val = 5;

    assert ((val - cmplx.cmplxAbs()) < EPS);
}
