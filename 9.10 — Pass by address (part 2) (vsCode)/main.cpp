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

void nulllift_reference(int*& ptr_ref)// refptr is now a reference to a pointer
{
    ptr_ref = nullptr;// Make the function parameter a null pointer
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
    Yup, it’s a thing. Just like we can pass a normal variable by reference, we can also pass pointers by reference. 
    Here’s the same program as above with ptr2 changed to be a reference to an address:
    */

    int y{ 2 };
    int* ptr_y{ &y };// ptr points to y

    std::cout << "ptr_y is:" << ( ptr_y ? "non-null\n" : "null\n" );

    nulllift_reference( ptr_y );


    std::cout << "ptr_y is:" << ( ptr_y ? "non-null\n" : "null\n" );

    /*
    This program prints:

    ptr is non-null
    ptr is null

    Because refptr is now a reference to a pointer, when ptr is passed as an argument, refptr is bound to ptr. 
    This means any changes to refptr are made to ptr.

    As an aside…

    Because references to pointers are fairly uncommon, it can be easy to mix up the syntax for a pointer to reference 
    (is it int*& or int&*?). The good news is that if you do it backwards, the compiler will error because you can’t have a 
    pointer to a reference (because pointers must hold the address of an object, and references aren’t objects). Then you can 
    switch it around.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "There is only pass by value" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Now that you understand the basic differences between passing by reference, address, and value, let’s get reductionist for a 
    moment. :)

    If they can’t be optimized away entirely, references are normally implemented by the compiler using pointers. This means that 
    behind the scenes, pass by reference is essentially just a pass by address (with access to the reference doing an implicit 
    dereference).

    And in the previous lesson, we mentioned that pass by address just copies an address from the caller to the 
    called function -- which is just passing an address by value.

    Therefore, we can conclude that C++ really passes everything by value! The properties of pass by address (and reference) 
    come solely from the fact that we can dereference the passed address to change the argument, which we can not do with a 
    normal value parameter!
    */



    return 0;
}