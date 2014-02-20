// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <functional>

class Foo {
public:
    Foo() : num_ ( 0){}
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout <<"Add number: "<< num_+i << '\n'; }
    void addPrint(int i ) { std::cout << "Print "<< num_ +i << std::endl;}
    int num_;
};


void print_number(int i)
{
    std::cout <<"Print_number: "<< i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

Foo a(666);
int main()
{
    Foo b;
    void (Foo::*mem_foo_ptr)(int) const;
    mem_foo_ptr = &Foo::print_add; 
    typedef void (Foo::*typ_ptr)(int) const; 
   // f_ptr pf1=X::f; blad kompilacji 
    typ_ptr pf1 = &Foo::print_add; // function is const so there should be const modifier

    ((a).*(mem_foo_ptr))(1.0); 
    #define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember)) 
    CALL_MEMBER_FN(a, mem_foo_ptr)(111); 
    CALL_MEMBER_FN(b, pf1)(9876);

    void (*ptr_print_num)(int) = print_number; 
    // or &print_num ptr_print_num(1234); 
    (*ptr_print_num)(123123); 

    std::function<void(int)> call_function = &print_number;
    std::cout <<"std::function<> test"<<std::endl;
    call_function(1);
   
    std::cout << "---Funktor do metody klasy Foo C++11"<<std::endl;
    std::function<void (Foo, int)> call_foo_print = &Foo::addPrint; // z nieznanego powodu Foo w szablnie z & i * nie bangla ...

    // Wywolanie funkcji na obiekcie c
    Foo c(1000);
    call_foo_print(c,1000);

    std::cout << "---Funktor z automatyczna dedukcja typow"<<std::endl; 
    auto auto_call_print = &print_number; // czlonek musi byc z & zebyu byl adres funkcji w normalnej funkcji bez roznicy bo nazwa adresem
    decltype(&print_number) drugie_auto_call = print_number;
    std::function<decltype(print_number)> trzecie_call = &print_number; // tutaj bez amerasaunda
    auto_call_print(27);
    drugie_auto_call(26);
    drugie_auto_call(25);

    std::cout << "---Automatyczn dedukcja dla czlonkow"<<std::endl;
    Foo d(2);
    auto auto_czlonek = std::mem_fn(&Foo::addPrint);
    auto_czlonek(d, 3); // d moze tez byc wskaznikiem Foo*
    _getch();
}