#include <iostream>

void someFunction(double* x)
{

}

int main()
{
    /*
    In the previous lesson (9.6 -- Introduction to pointers), we covered the basics of pointers, which are objects that hold 
    the address of another object. This address can be dereferenced using the dereference operator (*) to get the value at that 
    address:
    */
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x

    int* ptr_x{ &x }; // ptr holds the address of x
    // use dereference operator to print the value at the address that ptr is holding (which is x's address)
    std::cout << *ptr_x << '\n';

    /*
    The above example prints:

    55

    In the prior lesson, we also noted that pointers do not need to point to anything. In this lesson, we’ll explore such 
    pointers (and the various implications of pointing to nothing) further.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Null pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Besides a memory address, there is one additional value that a pointer can hold: a null value. 
    A null value (often shortened to null) is a special value that means something has no value. When a pointer is holding a 
    null value, it means the pointer is not pointing at anything. Such a pointer is called a null pointer.

    The easiest way to create a null pointer is to use value initialization:
    */
    
    int* ptr{}; // ptr is now a null pointer, and is not holding an address

    /*
    Best practice

    Value initialize your pointers (to be null pointers) if you are not initializing them with the address of a valid object.

    Because we can use assignment to change what a pointer is pointing at, a pointer that is initially set to null can later 
    be changed to point at a valid object:
    */

    double* e_ptr{};// ptr is a null pointer, and is not holding an address
    
    double d{ 3.3 };
    e_ptr = &d;// ptr now pointing at object d (no longer a null pointer)

    std::cout << *e_ptr << '\n';// print value of d through dereferenced ptr


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The nullptr keyword" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Much like the keywords true and false represent Boolean literal values, the nullptr keyword represents a null pointer 
    literal. We can use nullptr to explicitly initialize or assign a pointer a null value.
    */

    double* db{ nullptr };// can use nullptr to initialize a pointer to be a null pointer

    double someValue{ 34.6 };
    double* ptr_someValue{ &someValue }; // ptr is a valid pointer

    ptr_someValue = nullptr;// Can assign nullptr to make the pointer a null pointer

    someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter

    /*
    In the above example, we use assignment to set the value of ptr2 to nullptr, making ptr2 a null pointer.

    Best practice

    Use nullptr when you need a null pointer literal for initialization, assignment, or passing a null pointer to a function.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Dereferencing a null pointer results in undefined behavior" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Much like dereferencing a dangling (or wild) pointer leads to undefined behavior, dereferencing a null pointer also leads 
    to undefined behavior. In most cases, it will crash your application.

    The following program illustrates this, and will probably crash or terminate your application abnormally when you run it 
    (go ahead, try it, you won’t harm your machine):
    */
    int* empty_ptr{ nullptr };

    // ERROR occurring
    // std::cout << *empty_ptr << '\n';

    /*
    Conceptually, this makes sense. Dereferencing a pointer means “go to the address the pointer is pointing at and access the 
    value there”. A null pointer doesn’t have an address. So when you try to access the value at that address, what should it do?

    Accidentally dereferencing null and dangling pointers is one of the most common mistakes C++ programmers make, and is 
    probably the most common reason that C++ programs crash in practice.

    Warning

    Whenever you are using pointers, you’ll need to be extra careful that your code isn’t dereferencing null or dangling 
    pointers, as this will cause undefined behavior (probably an application crash).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Checking for null pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Much like we can use a conditional to test Boolean values for true or false, we can use a conditional to test whether a 
    pointer has value nullptr or not:
    */

    int xOne{ 5 };
    int* ptr_xOne{ &xOne };

    // pointers convert to Boolean false if they are null, and Boolean true if they are non-null
    if(ptr_xOne == nullptr)// explicit test for equivalence
        std::cout << "ptr_xOne is null\n";
    else
        std::cout << "ptr_xOne is non-null\n";

    int* nullPtr{};
    // explicit test for equivalence
    std::cout << "nullPtr is: " << (nullPtr == nullptr ? "null\n" : "non-null\n");

    return 0;
}