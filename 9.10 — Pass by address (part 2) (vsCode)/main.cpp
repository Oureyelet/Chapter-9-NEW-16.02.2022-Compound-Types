#include <iostream>
#include <string>

void greed(std::string* name = nullptr)
{
    std::cout << "Hello ";
    std::cout << (name ? *name : "guest\n") << '\n';    
}

void greed2()
{
    std::cout << "Hello guest" << '\n';
}

void greed2(const std::string& name)// name now passed by const reference
{
    std::cout << "Hello " << name << '\n';
}

void nullify(int* ptr)
{
    ptr = nullptr;
}

int main()
{
    /*
    This lesson is a continuation of 9.9 -- Pass by address.
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pass by address for “optional” arguments" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    One of the more common uses for pass by address is to allow a function to accept an “optional” argument. 
    This is easier to illustrate by example than to describe:
    */

    greed(); // we don't know who the user is yet

    std::string ptr_name{ "Dre" };
    greed( &ptr_name );// we know the user is joe

    /*
    This example prints:

    Hello guest
    Hello Joe

    In this program, the greet() function has one parameter that is passed by address and defaulted to nullptr. Inside main(), 
    we call this function twice. The first call, we don’t know who the user is, so we call greet() without an argument. 
    The name parameter defaults to nullptr, and the greet function substitutes in the name “guest”. For the second call, we now 
    have a valid user, so we call greet(&joe). The name parameter receives the address of joe, and can use it to print the name 
    “Joe”.

    However, in many cases, function overloading is a better alternative to achieve the same result:
    */
    greed2();

    std::string name{ "Adam" };

    greed2(name);

    /*
    This has a number of advantages: we no longer have to worry about null dereferences, and we could pass in a string 
    literal if we wanted.
    */

    
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Changing what a pointer parameter points at" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    When we pass an address to a function, that address is copied from the argument into the pointer parameter (which is 
    fine, because copying an address is fast). Now consider the following program:
    */

    int x{ 5 };
    int* ptr_x{ &x };

    std::cout << "ptr is " << ( ptr_x ? "non-null\n" : "null\n" );

    nullify(ptr_x);

    std::cout << "ptr is " << ( ptr_x ? "non-null\n" : "null\n" );

    /*
    As you can see, changing the address held by the pointer parameter had no impact on the address held by the argument 
    (ptr still points at x). When function nullify() is called, ptr2 receives a copy of the address passed in (in this case, 
    the address held by ptr, which is the address of x). When the function changes what ptr2 points at, this only affects the 
    copy held by ptr, not the original argument.

    So what if we want to allow a function to change what a pointer argument points to?
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pass by address… by reference?" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*

    */


    return 0;
}