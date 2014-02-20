// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <cstdarg>
using namespace std;

void typy(const char typ[] ...);

int main() {
    typy("NxN", "Jan", 0, "Maria");
    typy("innD", 17, "Jan", "Maria", 1.);
    typy("iDdniI", 17, 19.5, 1.5, "OK", -1, 8);
}

void typy(const char typ[] ...) {
    int     i = 0, integ;
    char    c, *strin;
    double  doubl;

    va_list ap;

    va_start(ap,typ);

    while ( (c = typ[i++]) != '\0') {
        switch (c) {
            case 'i':
            case 'I':
                integ = va_arg(ap,int);
                cout << "Liczba int   : " << integ << endl;
                break;
            case 'd':
            case 'D':
                doubl = va_arg(ap,double);
                cout << "Liczba double: " << doubl << endl;
                break;
            case 'n':
            case 'N':
                strin = va_arg(ap,char*);
                cout << "Napis        : " << strin << endl;
                break;
            default:
                cout << "Nielegalny kod typu!!!!!" << endl;
                goto KONIEC;
        }
    }
    KONIEC:
    cout << endl;

    va_end(ap);
    _getch();
}