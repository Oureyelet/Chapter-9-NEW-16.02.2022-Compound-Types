#include <iostream>

struct Something
{
    int x;      // no initialization value (bad)
    int y{};    // value-initialized by default
    int z{ 2 }; // explicit default value
    int q;
};

struct Fraction
{
    int numerator{};// we should use { 0 } here, but for the sake of example we'll use value initialization instead
    int denominator{ 1 };// explicit default value of 1
};



int main()
{
    Something s1; // s1.x is uninitialized, s1.y is 0, and s1.z is 2

    //Explicit initialization values take precedence over default values:
    Something s2{ 5, 6, 7 }; // use explicit initializer for s2.x, s2.y, s2.z, (no default values are used)


    //Missing initializers in an initializer list when default values exist:
    Something s3{}; // value initialize s3.x, use default values for s3.y and s3.z

    std::cout << "s3.x is: " << s3.x << '\n'; // print x = 0
    std::cout << "s3.y is: " << s3.y << '\n'; // print y = 0
    std::cout << "s3.z is: " << s3.z << '\n'; // print z = 2
    std::cout << "s3.q is: " << s3.q << '\n'; // print q = 0


    //Recapping the initialization possibilities:
    Something a1;// No initializer list: s1.x is uninitialized, s1.y and s1.z use defaults

    Something a1{ 5, 6, 7 };// Explicit initializers: s2.x, s2.y, and s2.z use explicit values (no default values are used)

    Something a1;{};// Missing initializers: s3.x is value initialized, s3.y and s3.z use defaults

    
    //Always provide default values for your members:
    Fraction f1;// f1.numerator value initialized to 0, f1.denominator defaulted to 1

    Fraction f2{};// f2.numerator value initialized to 0, f2.denominator defaulted to 1

    Fraction f3{ 6 };// f3.numerator initialized to 6, f3.denominator defaulted to 1

    Fraction f4{ 5, 8 };// f4.numerator initialized to 5, f4.denominator initialized to 8


    //Default initialization vs value initialization for aggregates:
    



    return 0;
}