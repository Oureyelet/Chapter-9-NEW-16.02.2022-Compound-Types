#include <iostream>
#include <string>

const std::string& getProgramName() // returns a const reference
{
    static const std::string s_programName { "Calculator" };// has static duration, destroyed at end of program

    return s_programName;
}

const int& getNextId()
{
    static int s_x{ 0 };// note: variable is non-const
    ++s_x; // generate the next id

    return s_x; // and return a reference to it
}
 
int main()
{
    /*
    In previous lessons, we discussed that when passing an argument by value, a copy of the argument is made into the function 
    parameter. For fundamental types (which are cheap to copy), this is fine. But copying is typically expensive for class types 
    (such as std::string). We can avoid making an expensive copy by utilizing passing by (const) reference (or pass by address) 
    instead.

    We encounter a similar situation when returning by value: a copy of the return value is passed back to the caller. If the 
    return type of the function is a class type, this can be expensive.
    
    std::string returnByValue(); // returns a copy of a std::string (expensive)
    
    In cases where we’re passing a class type back to the caller, we may (or may not) want to return by reference instead. 
    Return by reference returns a reference that is bound to the object being returned, which avoids making a copy of the 
    return value. To return by reference, we simply define the return value of the function to be a reference type:

    std::string&       returnByReference(); // returns a reference to an existing std::string (cheap)
    const std::string& returnByReferenceToConst(); // returns a const reference to an existing std::string (cheap)

    Here is an academic program to demonstrate the mechanics of return by reference:
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Return by reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In cases where we’re passing a class type back to the caller, we may (or may not) want to return by reference instead. 
    Return by reference returns a reference that is bound to the object being returned, which avoids making a copy of the 
    return value. To return by reference, we simply define the return value of the function to be a reference type:

    std::string&       returnByReference(); // returns a reference to an existing std::string (cheap)
    const std::string& returnByReferenceToConst(); // returns a const reference to an existing std::string (cheap)

    Here is an academic program to demonstrate the mechanics of return by reference:
    */

    std::cout << "This program is named " << getProgramName() << '\n';

    /*
    This program prints:

    This program is named Calculator

    Because getProgramName() returns a const reference, when the line return s_programName is executed, getProgramName() will 
    return a const reference to s_programName (thus avoiding making a copy). That const reference can then be used by the 
    caller to access the value of s_programName, which is printed.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The object being returned by reference must exist after the function returns" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Using return by reference has one major caveat: the programmer must be sure that the object being referenced outlives the 
    function returning the reference. Otherwise, the reference being returned will be left dangling (referencing an object that 
    has been destroyed), and use of that reference will result in undefined behavior.

    In the program above, because s_programName has static duration, s_programName will exist until the end of the program. 
    When main() accesses the returned reference, it is actually accessing s_programName, which is fine, because s_programName 
    won’t be destroyed until later.

    Now let’s modify the above program to show what happens in the case where our function returns a dangling reference:
    
    const std::string& getProgramName()
    {
        const std::string programName { "Calculator" }; // now a local variable, destroyed when function ends

        return programName;
    }

    The result of this program is undefined. When getProgramName() returns, a reference bound to local variable programName is 
    returned. Then, because programName is a local variable with automatic duration, programName is destroyed at the end of the 
    function. That means the returned reference is now dangling, and use of programName in the main() function results in 
    undefined behavior.

    Modern compilers will produce a warning or error if you try to return a local variable by reference (so the above program 
    may not even compile), but compilers sometimes have trouble detecting more complicated cases.

    Warning

    Objects returned by reference must live beyond the scope of the function returning the reference, or a dangling reference 
    will result. Never return a local variable by reference.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Don’t return non-const local static variables by reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the original example above, we returned a local static variable by reference to illustrate the mechanics of return by 
    reference in a simple way. However, returning non-const static variables by reference is fairly non-idiomatic, and should 
    generally be avoided. Here’s a simplified example that illustrates one such problem that can occur:
    */

    const int& id1{ getNextId() };// id1 is a reference
    const int& id2{ getNextId() };// id2 is a reference


    std::cout << id1 << id2 << '\n';
    
    /*
    This program prints:

    22

    This happens because id1 and id2 are referencing the same object (the static variable s_x), so when anything 
    (e.g. getNextId()) modifies that value, all references are now accessing the modified value. Another issue that commonly 
    occurs with programs that return a static local by const reference is that there is no standardized way to reset s_x back 
    to the default state. Such programs must either use a non-idiomatic solution (e.g. a reset parameter), or can only be reset 
    by quitting and restarting the program.

    While the above example is a bit silly, there are permutations of the above that programmers sometimes try for optimization 
    purposes, and then their programs don’t work as expected.

    Best practice

    Avoid returning references to non-const local static variables.

    Returning a const reference to a const local variable is sometimes done if the local variable being returned by reference is 
    expensive to create (so we don’t have to recreate the variable every function call). This is okay.

    Returning a const reference to a const global variable is also sometimes done as a way to encapsulate access to a global 
    variable. We discuss this in lesson 6.8 -- Why (non-const) global variables are evil. When used intentionally and carefully, 
    this is also okay.
    */


    return 0;
}