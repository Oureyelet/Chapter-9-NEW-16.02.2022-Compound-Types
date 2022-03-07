#include <iostream>
#include <initializer_list>
#include <string>

int getVal() // some function that returns an int by value
{
    return 5;
}

const double foo()
{
    return 7.7;
}

std::string& getRef()
{
    static std::string o{ "ooo" };

    return o;
}

int main()
{
    /*
    In lesson 8.7 -- Type deduction for objects using the auto keyword, we discussed how the auto keyword can be used to 
    have the compiler deduce the type of a variable from the initializer:
    */

    auto val{ getVal() };// val deduced as type int

    //We also noted that by default, type deduction will drop const qualifiers:
    const double cd{ 7.8 };

    auto x{ cd };   // double (const dropped)
    auto y{ foo() };// double (const dropped)

    //Const can be reapplied by adding the const qualifier in the definition:

    const auto z{ foo() };// const double (const reapplied)
    const auto g{ cd };// const double (const reapplied)


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Type deduction drops references" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In addition to dropping const qualifiers, type deduction will also drop references:
    */
    
    auto ref{ getRef() };

    /*
    In the above example, variable ref is using type deduction. Although function getRef() returns a std::string&, 
    the reference qualifier is dropped, so the type of ref is deduced as std::string.

    Just like with the dropped const qualifier, if you want the deduced type to be a reference, you can reapply the reference 
    at the point of definition:
    */
    auto ref1{ getRef() }; // std::string (reference dropped)
    auto& ref2{ getRef() };// std::string& (reference reapplied)


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Top-level const and low-level const" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    A top-level const is a const qualifier that applies to an object itself. For example:
    */
    int gh{ 5 };
    const int x_x{ 44 }; // this const applies to x, so it is top-level
    int* const ptr{ &gh };// this const applies to ptr, so it is top-level

    //In contrast, a low-level const is a const qualifier that applies to the object being referenced or pointed to:
    const int y_y{ 44 };    // this const applies to the object being referenced, so it is low-level
    const int* ptr_y{ &x_x };// this const applies to the object being pointed to, so it is low-level

    //A reference to a const value is always a low-level const. A pointer can have a top-level, low-level, or both kinds of const:
    const int* const ptr_x{ &x_x };// the left const is low-level, the right const is top-level

    /*
    When we say that type deduction drops const qualifiers, it only drops top-level consts. 
    Low-level consts are not dropped. We’ll see examples of this in just a moment.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Type deduction and const references" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*

    */

    return 0;
}