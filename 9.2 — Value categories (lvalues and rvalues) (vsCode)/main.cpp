#include <iostream>

//function prototypes:
void print(int);

int main()
{
    /*
    Before we talk about our first compound type (lvalue references), we’re going to take a little detour and talk about what 
    an lvalue is.

    In lesson 1.10 -- Introduction to expressions, we defined an expression as, “a combination of literals, variables, operators, 
    and function calls that can be executed to produce a singular value”.
    For example:
    */
    std::cout << 2 + 3 << '\n'; // The expression 2 + 3 produces the value 5

    /*
    In the above program, the expression 2 + 3 is evaluated to produce the value 5, which is then printed to the console.

    In lesson 5.4 -- Increment/decrement operators, and side effects, we also noted that expressions can produce side effects 
    that outlive the expression:
    */
    int x{ 5 };
    ++x;// This expression statement has the side-effect of incrementing x
    std::cout << x << '\n'; // prints 6 

    /*
    In the above program, the expression ++x increments the value of x, and that value remains changed even after the expression 
    has finished evaluating.

    Besides producing values and side effects, expressions can do one more thing: they can evaluate to objects or functions. 
    We’ll explore this point further in just a moment.
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The properties of an expression" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    To help determine how expressions should evaluate and where they can be used, all expressions in C++ have two properties: 
    a type and a value category.
    */
    

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The type of an expression" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    The type of an expression is equivalent to the type of the value, object, or function that results from the evaluated 
    expression. For example:
    */
    auto v1 { 12 / 4 }; // int / int => int
    auto v2 { 12.0 / 4 };// double / int => double

    /*
    For v1, the compiler will determine (at compile time) that a division with two int operands will produce an int result, so 
    int is the type of this expression. Via type inference, int will then be used as the type of v1.

    For v2, the compiler will determine (at compile time) that a division with a double operand and an int operand will produce 
    a double result. Remember that arithmetic operators must have operands of matching types, so in this case, the int operand gets promoted to a double, and a floating point division is performed. So double is the type of this expression.

    The compiler can use the type of an expression to determine whether an expression is valid in a given context. 
    For example:
    */
    // print("foo");// error: print() was expecting an int argument, we tried to pass in a string literal

    /*
    In the above program, the print(int) function is expecting an int parameter. However, the type of the expression we’re 
    passing in (the string literal "foo") does not match, and no conversion can be found. So a compile error results.

    Note that the type of an expression must be determinable at compile time (otherwise type checking and type deduction wouldn’t
     work) -- however, the value of an expression may be determined at either compile time (if the expression is constexpr) 
     or runtime (if the expression is not constexpr).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The value category of an expression" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */


    return 0;
}


void print(int x)
{
    std::cout << x << '\n';
}