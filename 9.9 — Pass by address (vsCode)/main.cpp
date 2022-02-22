#include <iostream>
#include <string>

void printByValue(std::string val)// The function parameter is a copy of str
{
    std::cout << val << '\n';// print the value via the copy
}

void printByReference(const std::string& val)// The function parameter is a reference that binds to str
{
    std::cout << val << '\n';// print the value via the reference
}

void printByNon_const_reference(std::string& val)// The function parameter is a reference that binds to str
{
    val = "Yo yo yo!";
    std::cout << val << '\n';// print the value via the reference
}

int main()
{
    /*
    In prior lessons, we’ve covered two different ways to pass an argument to a function: pass by value (2.3 -- Introduction to 
    function parameters and arguments) and pass by reference (9.5 -- Pass by lvalue reference).

    Here’s a sample program that shows a std::string object being passed by value and by reference:
    */
    std::string str{ "Hello, world!" };

    printByValue(str);// pass str by value, makes a copy of str
    printByReference(str);// pass str by reference, does not make a copy of str
    printByNon_const_reference(str);

    std::cout << str << '\n';

    /*
    When we pass argument str by value, the function parameter val receives a copy of the argument. Because the parameter is a 
    copy of the argument, any changes to the val are made to the copy, not the original argument.

    When we pass argument str by reference, the reference parameter ref is bound to the actual argument. This avoids making a 
    copy of the argument. Because our reference parameter is const, we are not allowed to change ref. But if ref were non-const, 
    any changes we made to ref would change str.

    In both cases, the caller is providing the actual object (str) to be passed as an argument to the function call.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pass by address" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */

    return 0;
}