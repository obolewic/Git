// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <functional>


int main()
{
    std::cout << "---Lambdy"<<std::endl;
    auto func_labmda = [] () { std::cout << "Hello, I'm Lambda"<<std::endl; };
    func_labmda(); // now call the function

    double dabel = 3.14;
    /*std::function<double(double)> zamiast auto*/
    auto func_labmda2 = [&dabel](double arg) {dabel = 2.68;  std::cout << "Hello, I'm Lambda. dabel = "<<dabel <<std::endl; return dabel - arg;};
    std::cout << "Wynik Lambdy to "<<func_labmda2(55.5)<<" A dabel poza ot to "<<dabel<<std::endl;
    std::cout << "Wynik Lambdy to 2 "<<func_labmda2(4)<<std::endl;


    int sum = 0;
    auto running_sum = [&sum](double x) {sum += x;};
    running_sum(1);
    running_sum(2);
    running_sum(3);
    std::cout << "SUM "<<sum<<std::endl;


    _getch();
}