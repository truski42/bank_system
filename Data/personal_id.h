#ifndef PERSONAL_ID_H
#define PERSONAL_ID_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
short PESEL[11];
int valid = 0;

using std::cout;
using std::cin;
using std::endl;

int getBirthYear()
{
    int year;
    int month;
    cout << "\n\tEnter your birth year: ";
    cin >> year;
    cout << "\n\tEnter your birth month";
    cin >> month;
    year = 10 * PESEL[0];
    year += PESEL[1];
    month = 10 * PESEL[2];
    month += PESEL[3];
    if (month > 80 && month < 93)
    {
        year += 1800;
    }
    else if (month > 0 && month < 13)
    {
        year += 1900;
    }
    else if (month > 20 && month < 33)
    {
        year += 2000;
    }
    else if (month > 40 && month < 53)
    {
        year += 2100;
    }
    else if (month > 60 && month < 73)
    {
        year += 2200;
    }
    return year;
}
#endif // PERSONAL_ID_H