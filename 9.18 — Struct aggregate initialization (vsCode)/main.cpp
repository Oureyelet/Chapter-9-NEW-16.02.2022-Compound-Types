#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

struct Rectangle
{
    double lenght {};
    double wight {};
};

struct Foo
{
    int a{};
    int b{}; // just added
    int c{};
};


int main()
{
    // Data members are not initialized by default:

    //What is an aggregate?

    //Aggregate initialization of a struct:

    Employee joe; // how do we initialize joe.id, joe.age, and joe.wage?

    Employee ania = { 1, 32, 1.500 }; // copy-list initialization using braced list
    Employee mateusz ( 2, 30, 2.250 ); // direct initialization using parenthesized list (C++20)
    Employee sophie { 3, 1, 10 }; // list initialization using braced list (preferred)

    //Missing initializers in an initializer list:
    
    Employee ktos{ 4, 122 }; // ktos.wage will be value-initialized to 0.0

    Employee tobias{};// value-initialize all members

    //Const structs;
        
    const Rectangle unit { 1.0, 1.0 };
    const Rectangle zero {}; // value-initialize all members

    //Designated initializers:

    Foo f{ 1, 3 }; // f.a = 1, f.c = 3
    Foo d{ 1, 3 }; // d.a = 1, d.b = 3, d.c = 0
    Foo s{ .a{ 1 }, .c{ 3 } };

    if (__cplusplus > 201703L) std::cout << "C++20\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";




    return 0;
}