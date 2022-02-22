#include <iostream>

int main()
{
    /*
    Consider the following code snippet:
    */
    int x{ 5 };
    int* ptr{ &x }; // ptr is a normal (non-const) pointer

    int y{ 6 };
    ptr = &y; // we can point at another value

    *ptr = 7; // we can change the value at the address being held

    /*
    With normal (non-const) pointers, we can change both what the pointer is pointing at (by assigning the pointer a new 
    address to hold) or change the value at the address being held (by assigning a new value to the dereferenced pointer).

    However, what happens if the value we want to point at is const?
    */
    const int xTwo{ 8 };  // x is now const
    // int* ptr_xTwo{ &xTwo }; // compile error: cannot convert from const int* to int*

    /*
    The above snippet won’t compile -- we can’t set a normal pointer to point at a const variable. This makes sense: a const 
    variable is one whose value cannot be changed. Allowing the programmer to set a non-const pointer to a const value would 
    allow the programmer to dereference the pointer and change the value. That would violate the const-ness of the variable.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointer to const value" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    A pointer to a const value (sometimes called a pointer to const for short) is a (non-const) pointer that points to a 
    constant value.

    To declare a pointer to a const value, use the const keyword before the pointer’s data type:
    */
    const int y2{ 7 };
    const int* ptr_y2{ &y2 }; // okay: ptr is pointing to a "const int"

    // *ptr_y2 = 23; // not allowed: we can't change a const value

    /*
    In the above example, ptr points to a const int. Because the data type being pointed to is const, the value being pointed 
    to can’t be changed.

    However, because a pointer to const is not const itself (it just points to a const value), we can change what the pointer is 
    pointing at by assigning the pointer a new address:
    */
    const double z{ 34.2 };
    const double* next_ptr{ &z }; // ptr points to const int x

    const double tB{ 45.5 };
    next_ptr = &tB; // okay: ptr now points at const int y

    std::cout << *next_ptr << '\n';

    /*
    Just like a reference to const, a pointer to const can point to non-const variables too. 
    A pointer to const treats the value being pointed to as constant, regardless of whether the object at that address was 
    initially defined as const or not:
    */
    int xTree{ 7 };// non-const
    const int* ptr_Tree{ &xTree };// ptr points to a "const int"   

    //ERROR: *ptr_Tree = 8; // not allowed: ptr points to a "const int" so we can't change the value through ptr

    xTree = 122;// allowed: the value is still non-const when accessed through non-const identifier xTree


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    We can also make a pointer itself constant. A const pointer is a pointer whose address can not be changed 
    after initialization.

    To declare a const pointer, use the const keyword after the asterisk in the pointer declaration:
    */
    float fVar{ 12.2 };
    float* const ptr_fVar{ &fVar };// const after the asterisk means this is a const pointer

    /*
    In the above case, ptr is a const pointer to a (non-const) int value.

    Just like a normal const variable, a const pointer must be initialized upon definition, and this value can’t be 
    changed via assignment:
    */
    int x4{ 4 };
    int y8{ 8 };

    int* const ptr_x4{ &x4 };// okay: the const pointer is initialized to the address of

    //ERROR ptr_x4 = &y8;// error: once initialized, a const pointer can not be changed.

    /*
    However, because the value being pointed to is non-const, it is possible to change the value being pointed to via 
    dereferencing the const pointer:
    */
    double dB{ 67.7 };
    double* const ptr_dB{ &dB }; // ptr will always point to dB

    *ptr_dB = 23.3; // okay: the value being pointed to is non-const


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const pointer to a const value" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Finally, it is possible to declare a const pointer to a const value by using the const keyword both before the type and 
    after the asterisk:
    */
    float f1{ 33.2 };
    const float* const ptr_f1{ &f1 };// a const pointer to a const value

    /*
    A const pointer to a const value can not have its address changed, nor can the value it is pointing to be changed through 
    the pointer. It can only be dereferenced to get the value it is pointing at.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointer and const recap" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    To summarize, you only need to remember 4 rules, and they are pretty logical:

    A non-const pointer can be assigned another address to change what it is pointing at
    A const pointer always points to the same address, and this address can not be changed.

    A pointer to a non-const value can change the value it is pointing to. These can not point to a const value.
    A pointer to a const value treats the value as const when accessed through the pointer, and thus can not change the value 
    it is pointing to. These can be pointed to const or non-const l-values (but not r-values, which don’t have an address)

    Keeping the declaration syntax straight can be a bit challenging:

    The pointer’s type defines the type of the object being pointed at. So a const in the type means the pointer is pointing at a 
    const value.
    A const after the asterisk means the pointer itself is const and it can not be assigned a new address.
    */
    int value{ 55 };

    int* ptr0{ &value };// ptr0 points to an "int" and is not const itself, so this is a normal pointer.
    const int* ptr1{ &value };// ptr1 points to a "const int", but is not const itself, so this is a pointer to a const value.
    int* const ptr2{ &value };// ptr2 points to an "int", but is const itself, so this is a const pointer (to a non-const value).
    const int* const ptr3{ &value };// ptr3 points to an "const int", and it is const itself, so this is a const pointer to a const value.



    return 0;
}