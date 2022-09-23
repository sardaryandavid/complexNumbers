#include <iostream>
#include <stdio.h>
#include <cmath>

#include "complex.h"

int main()
{
    Complex compl1 {1.0, 2.0};
    Complex compl2 {2, 1};
    Complex compl3 {100, 100};
    printf ("%d\n", compl3 > compl1);

    compl3.print();

    return 0;
}