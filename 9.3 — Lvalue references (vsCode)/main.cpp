#include <iostream>

int main()
{
    /*
    In C++, a reference is an alias for an existing object. Once a reference has been defined, any operation on the reference 
    is applied to the object being referenced.

    Key insight

    A reference is essentially identical to the object being referenced.

    This means we can use a reference to read or modify the object being referenced. Although references might seem silly, 
    useless, or redundant at first, references are used everywhere in C++ (we’ll see examples of this in a few lessons).

    You can also create references to functions, though this is done less often.

    Modern C++ contains two types of references: lvalue references, and rvalue references. In this chapter, we’ll discuss 
    lvalue references.

    Related content

    Because we’ll be talking about lvalues and rvalues in this lesson, please review 9.2 -- Value categories (lvalues and 
    rvalues) if you need a refresher on these terms before proceeding.

    Rvalue references are covered in the chapter on move semantics (chapter M).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Lvalue reference types" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    An lvalue reference (commonly just called a reference since prior to C++11 there was only one type of reference) acts as an 
    alias for an existing lvalue (such as a variable).

    To declare an lvalue reference type, we use an ampersand (&) in the type declaration:
    */
    int c{}; // a normal int type
    int& c2{ c }; // an lvalue reference to an int object

    double h1{}; // a normal double type
    double& c3{ h1 }; // an lvalue reference to a double object

    
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Lvalue reference variables" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    One of the things we can do with an lvalue reference type is create an lvalue reference variable. An lvalue reference 
    variable is a variable that acts as a reference to an lvalue (usually another variable).

    To create an lvalue reference variable, we simply define a variable with an lvalue reference type:
    */
    int ss{ 7 }; // ss is a normal integer variable
    int& ref{ ss }; // ref is an lvalue reference variable that can now be used as an alias for variable ss

    std::cout << ss << '\n'; // print the value of ss (7)
    std::cout << ref << '\n'; // print the value of ss via ref (7)
    
    /*
    In the above example, the type int& defines ref as an lvalue reference to an int, which we then initialize with lvalue 
    expression x. Thereafter, ref and x can be used synonymously. This program thus prints:

    5
    5

    From the compiler’s perspective, it doesn’t matter whether the ampersand is “attached” to the type name (int& ref) or the 
    variable’s name (int &ref), and which you choose is a matter of style. Modern C++ programmers tend to prefer attaching the 
    ampersand to the type, as it makes clearer that the reference is part of the type information, not the identifier.

    Best practice

    When defining a reference, place the ampersand next to the type (not the reference variable’s name).

    For advanced readers

    For those of you already familiar with pointers, the ampersand in this context does not mean “address of”, it means “lvalue 
    reference to”.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Modifying values through an lvalue reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the above example, we showed that we can use a reference to read the value of the object being referenced. 
    We can also use a reference to modify the value of the object being referenced:
    */
    int erPOL{ 12 }; // normal integer variable
    int& ref_erPOL{ erPOL }; // ref_erPol is now an alias for variable erPol

    std::cout << erPOL << ref_erPOL << '\n'; // print 1212

    erPOL = 14; // erPol now has value 14

    std::cout << erPOL << ref_erPOL << '\n'; // print 1414

    ref_erPOL = 16; // the object being referenced (erPol) now has value 16

    std::cout << erPOL << ref_erPOL << '\n'; // print 1616

    //In the above example, ref is an alias for x, so we are able to change the value of x through either x or ref.


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Initialization of lvalue references" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Much like constants, all references must be initialized.
    */
    // int& uhh{}; // error: references must be initialized

    double opo{ 23.3 };
    double& ref_opo{ opo }; // okay: reference to double is bound to double variable

    /*
    When a reference is initialized with an object (or function), we say it is bound to that object (or function). 
    The process by which such a reference is bound is called reference binding. The object (or function) being referenced 
    is sometimes called the referent.

    Lvalue references must be bound to a modifiable lvalue.
    */
    int li_x{ 5 };
    int& ref_li_x{ li_x };
    
    const int gg{ 5 };
    // int& invalidRef{ gg }; // invalid: can't bind to a non-modifiable lvalue
    // int& invalidRef2{ 0 }; // invalid: can't bind to an r-value

    /*
    Lvalue references can’t be bound to non-modifiable lvalues or rvalues (otherwise you’d be able to change those values 
    through the reference, which would be a violation of their const-ness). For this reason, lvalue references are occasionally 
    called lvalue references to non-const (sometimes shortened to non-const reference).

    In most cases, the type of the reference must match the type of the referent (there are some exceptions to this rule that 
    we’ll discuss when we get into inheritance):
    */
    int s1{ 56 };
    int& ref_s1{ s1 }; // okay: reference to int is bound to int variable

    double r1{ 6.0 };
    // int& invalidRef_1{ r1 }; // invalid; reference to int cannot bind to double variable
    // double& invalidRef_2{ s1 }; // invalid: reference to double cannot bind to int variable

    //Lvalue references to void are disallowed (what would be the point?).


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "References can’t be reseated (changed to refer to another object)" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Once initialized, a reference in C++ cannot be reseated, meaning it cannot be changed to reference another object.

    New C++ programmers often try to reseat a reference by using assignment to provide the reference with another variable to 
    reference. This will compile and run -- but not function as expected. Consider the following program:
    */
    int house{ 5 };
    int shed{ 6 };

    int& ref_house{ house }; // ref_house is now an alias for house

    // assigns 6 (the value of 'shed') to 'house' (the object being referenced by 'ref_house')
    // The above line does NOT change 'ref_house' into a reference to variable 'shed'!
    ref_house = shed;

    std::cout << house << '\n'; // user is expecting this to print 5

    /*
    Perhaps surprisingly, this prints:

    6

    When a reference is evaluated in an expression, it resolves to the object it’s referencing. So ref = y doesn’t change ref 
    to now reference y. Rather, because ref is an alias for x, the expression evaluates as if it was written x = y -- and 
    since y evaluates to value 6, x is assigned the value 6.
    */
    

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Lvalue reference scope and duration" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Reference variables follow the same scoping and duration rules that normal variables do:
    */
    int i_One{ 2 }; // normal integer
    int& ref_i_One{ i_One }; // reference to variable value


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "References and referents have independent lifetimes" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    With one exception (that we’ll cover next lesson), the lifetime of a reference and the lifetime of its referent are 
    independent. In other words, both of the following are true:

    A reference can be destroyed before the object it is referencing.
    The object being referenced can be destroyed before the reference.

    When a reference is destroyed before the referent, the referent is not impacted. The following program demonstrates this:
    */
    int newVariable{ 5 };

    {
        int& ref_newVariable{ newVariable }; // ref is a reference to newVariable
        std::cout << ref_newVariable << '\n'; // prints value of ref (5)
    } // ref is destroyed here -- newVariable is unaware of this

    std::cout << newVariable << '\n'; // prints value of newVariable (5)

    // When ref dies, variable x carries on as normal, blissfully unaware that a reference to it has been destroyed.


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Dangling references" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    When an object being referenced is destroyed before a reference to it, the reference is left referencing an object that no 
    longer exists. Such a reference is called a dangling reference. Accessing a dangling reference leads to undefined behavior.

    Dangling references are fairly easy to avoid, but we’ll show a case where this can happen in practice in lesson 9.5 -- Pass 
    by lvalue reference.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "References aren’t objects" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Perhaps surprisingly, references are not objects in C++. A reference is not required to exist or occupy storage. If 
    possible, the compiler will optimize references away by replacing all occurrences of a reference with the referent. 
    However, this isn’t always possible, and in such cases, references may require storage.

    This also means that the term “reference variable” is a bit of a misnomer, as variables are objects with a name, and 
    references aren’t objects.

    Because references aren’t objects, they can’t be used anywhere an object is required (e.g. you can’t have a reference to a 
    reference, since an lvalue reference must reference an identifiable object). In cases where you need a reference that is an 
    object or a reference that can be reseated, std::reference_wrapper (which we cover in lesson 16.3 -- Aggregation) provides a 
    solution.

    As an aside…

    Consider the following variables:
    */

    int var{};
    int& ref_var{ var }; // an lvalue reference bound to var
    int& ref_ref_var{ ref_var }; // an lvalue reference bound to var
    
    /*
    Because ref2 (a reference) is initialized with ref1 (a reference), you might be tempted to conclude that ref2 is a 
    reference to a reference. It is not. Because ref1 is a reference to var, when used in an expression (such as an initializer), 
    ref1 evaluates to var. So ref2 is just a normal lvalue reference (as indicated by its type int&), bound to var.

    A reference to a reference (to an int) would have syntax int&& -- but since C++ doesn’t support references to references, 
    this syntax was repurposed in C++11 to indicate an rvalue reference (which we cover in lesson M.2 -- R-value references).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz Time" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Question #1

    Determine what values the following program prints by yourself (do not compile the program).

    #include <iostream>

    int main()
    {
        int x{ 1 };
        int& ref{ x };

        std::cout << x << ref; // print 11

        int y{ 2 };
        ref = y;
        y = 3;

        std::cout << x << ref; // print 33

        x = 4;

        std::cout << x << ref; // print 44

        return 0;
    }
    */

    int x_Quiz{ 1 };
    int& ref_Quiz{ x_Quiz };

    std::cout << x_Quiz << ref_Quiz; // print 11

    int y_Quiz{ 2 };
    ref_Quiz = y_Quiz;
    y_Quiz = 3;

    std::cout << x_Quiz << ref_Quiz; // print 33

    x_Quiz = 4;

    std::cout << x_Quiz << ref_Quiz; // print 44

    /*
    112244

    Because ref is bound to x, x and ref are synonymous, so they will always print the same value. The line ref = y assigns 
    the value of y (2) to ref -- it does not change ref to reference y. The subsequent line y = 3 only changes y.
    */
    
    
    
    
    
    return 0;
}// i_One and ref_i_One die here
// newVariable destroyed here