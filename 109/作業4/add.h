#ifndef ADD_H
#define ADD_H

#include "bigint_end.h"
#include "constructor.h"
#include "tool.h"
#include <iostream>
#include <string>
using namespace std;
int max(int a, int b)
{
    return a >= b ? a : b;
}
void bigint::add(int value)
{
    bigint t(value);
    add(t);
}
void bigint::add(string s)
{
    bigint t(s);
    add(t);
}
void bigint::add(bigint &x)
{
    reverse();
    x.reverse();
    digits = max(digits, x.digits);
    for (int i = 0; i < digits; i++)
    {
        //cout << array_pointer[i] << " = " << array_pointer[i] << " * " << sign << " + " << x.array_pointer[i] << " * " << x.sign << " -> ";
        array_pointer[i] = array_pointer[i] * sign + x.array_pointer[i] * x.sign;
        //cout << array_pointer[i] << "\n";
    }
    carry();
    x.reverse();
}
#endif
