#include <iostream>

void printValue(int y)
{
    std::cout << y << '\n';
}// y is destroyed here

void printString(std::string y)
{
    std::cout << y << '\n';
}// y is destroyed here

int main()
{   
    /*
    In the previous lessons, we introduced lvalue references (9.3 -- Lvalue references) and lvalue references to const 
    (9.4 -- Lvalue references to const). In isolation, these may not have seemed very useful -- why create an alias to a 
    variable when you can just use the variable itself?

    In this lesson, we’ll finally provide some insight into what makes references useful. And then starting later in this 
    chapter, you’ll see references used regularly.

    First, some context. Back in lesson 2.3 -- Introduction to function parameters and arguments we discussed pass by value, 
    where an argument passed to a function is copied into the function’s parameter:
    */
    int x{ 2 };

    printValue( x ); // x is passed by value (copied) into parameter y (inexpensive)

    /*
    In the above program, when printValue(x) is called, the value of x (2) is copied into parameter y. Then, at the end of the 
    function, object y is destroyed.

    This means that when we called the function, we made a copy of our argument’s value, only to use it briefly and then destroy 
    it! Fortunately, because fundamental types are cheap to copy, this isn’t a problem.
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Some objects are expensive to copy" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Most of the types provided by the standard library (such as std::string) are class types. Class types are usually expensive 
    to copy. Whenever possible, we want to avoid making unnecessary copies of objects that are expensive to copy, especially 
    when we will destroy those copies almost immediately.

    Consider the following program illustrating this point:
    */
    std::string y{ "Hello, world!" };// x is a std::string

    printString(y);// x is passed by value (copied) into parameter y (expensive)

    /*
    This prints

    Hello, world!

    While this program behaves like we expect, it’s also inefficient. Identically to the prior example, when printValue() is 
    called, argument x is copied into printValue() parameter y. However, in this example, the argument is a std::string 
    instead of an int, and std::string is a class type that is expensive to copy. And this expensive copy is made every 
    time printValue() is called!

    We can do better.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pass by reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */

    return 0;
}