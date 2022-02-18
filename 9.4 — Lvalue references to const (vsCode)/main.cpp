#include <iostream>

int main()
{
    /*
    In the previous lesson (9.3 -- Lvalue references), we discussed how an lvalue reference can only bind to a modifiable 
    lvalue. This means the following is illegal:
    */
    const int x{ 2 }; // x is a non-modifiable (const) lvalue
    // int& ref_x{ x }; // error: ref can not bind to non-modifiable lvalue

    /*
    This is disallowed because it would allow us to modify a const variable (x) through the non-const reference (ref).

    But what if we want to have a const variable we want to create a reference to? A normal lvalue reference 
    (to a non-const value) won’t do.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Lvalue reference to const" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    By using the const keyword when declaring an lvalue reference, we tell an lvalue reference to treat the object it is 
    referencing as const. Such a reference is called an lvalue reference to a const value (sometimes called a reference to 
    const or a const reference).

    Lvalue references to const can bind to non-modifiable lvalues:
    */
    const double y{ 12.2 };// y is a non-modifiable lvalue
    const double& ref_y{ y };// okay: ref is a an lvalue reference to a const value

    /*
    Because lvalue references to const treat the object they are referencing as const, they can be used to access but not 
    modify the value being referenced:
    */

    std::cout << ref_y << '\n'; // okay: we can access the const object

    // ref_y = 7; // error: we can not modify a const object

    
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing an lvalue reference to const with a modifiable lvalue" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Lvalue references to const can also bind to modifiable lvalues. In such a case, the object being referenced is treated as 
    const when accessed through the reference (even though the underlying object is non-const):
    */
    int z{ 7 };// x is a modifiable lvalue
    const int& ref_z{ z };// okay: we can bind a const reference to a modifiable lvalue

    std::cout << ref_z << '\n';// okay: we can access the object through our const reference    
    // ref_z = 8;// error: we can not modify an object through a const reference

    z = 3;// okay: x is a modifiable lvalue, we can still modify it through the original identifier

    /*
    In the above program, we bind const reference ref to modifiable lvalue x. We can then use ref to access x, but because ref 
    is const, we can not modify the value of x through ref. However, we still can modify the value of x directly 
    (using the identifier x).

    Best practice

    Favor lvalue references to const over lvalue references to non-const unless you need to modify the object being referenced.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing an lvalue reference to const with an rvalue" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Perhaps surprisingly, lvalues references to const can also bind to rvalues:
    */
    const double& clean_ref{ 8 };// okay: 5 is an rvalue

    std::cout << clean_ref << '\n';//print 8

    /*
    When this happens, a temporary object is created and initialized with the rvalue, and the reference to const is bound to 
    that temporary object.

    A temporary object (also sometimes called an anonymous object) is an object that is created for temporary use (and then 
    destroyed) within a single expression. Temporary objects have no scope at all (this makes sense, since scope is a property 
    of an identifier, and temporary objects have no identifier). This means a temporary object can only be used directly at 
    the point where it is created, since there is no way to refer to it beyond that point.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const references bound to temporary objects extend the lifetime of the temporary object" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Temporary objects are normally destroyed at the end of the expression in which they are created.

    However, consider what would happen in the above example if the temporary object created to hold rvalue 5 was destroyed at 
    the end of the expression that initializes ref. Reference ref would be left dangling (referencing an object that had been 
    destroyed), and we’d get undefined behavior when we tried to access ref.

    To avoid dangling references in such cases, C++ has a special rule: When a const lvalue reference is bound to a temporary 
    object, the lifetime of the temporary object is extended to match the lifetime of the reference.
    */
    const int& var{ 22 };// The temporary object holding value 22 has its lifetime extended to match 'var'

    std::cout << var << '\n';// Therefore, we can safely use it here


    /*
    In the above example, when ref is initialized with rvalue 5, a temporary object is created and ref is bound to that temporary object. The lifetime of the temporary object matches the lifetime of ref. Thus, we can safely print the value of ref in the next statement. Then both ref and the temporary object go out of scope and are destroyed at the end of the block.

    Key insight

    Lvalue references can only bind to modifiable lvalues.

    Lvalue references to const can bind to modifiable lvalues, non-modifiable lvalues, and rvalues. This makes them a much more 
    flexible type of reference.

    So why does C++ allow a const reference to bind to an rvalue anyway? We’ll answer that question in the next lesson!
    */
 


    return 0;
}// Both 'var' and the temporary object die here