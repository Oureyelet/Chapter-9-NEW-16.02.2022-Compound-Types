#include <iostream>

/*
Define a program-defined type named Fraction so the compiler understands what a Fraction is
(we'll explain what a struct is and how to use them later in this chapter)
This only defines what a Fraction type looks like, it doesn't create one
*/
struct Fraction
{
    int numerator{};
    int denominator{};
};

// Now we can make use of our Fraction type
int main()
{
    /*
    Because fundamental types are defined as part of the core C++ language, they are available for immediate use. 
    For example, if we want to define a variable with a type of int or double, we can just do so:
    */

    int x; // define variable of fundamental type 'int'
    double y; // define variable of fundamental type 'double'

    /*
    This is also true for the compound types that are simple extensions of fundamental types (including functions, 
    pointers, references, and arrays):
    */
    void fcn(int x);// define a function of type void()(int)
    int* ptr;// define variable of compound type 'pointer to int'
    int& ref{ x };// define variable of compound type 'reference to int'
    int arr[5];// define an array of 5 integers of type int[5] (we'll cover this in a future chapter)

    /*
    This works because the C++ language already knows what the type names (and symbols) for these types mean -- we do not 
    need to provide or import any definitions.
    */

    /*
    However, consider the case of a type alias (introduced in lesson 8.6 -- Typedefs and type aliases), which allows us to 
    define a new name for an existing type. Because a type alias introduces a new identifier into the program, a type alias 
    must be defined before it can be used:
    */
    using lenght = int; // define a type alias with identifier 'length'

    lenght op{ 5 }; // we can use 'length' here since we defined it above
    std::cout << op << '\n';

    /*
    If we were to omit the definition of length, the compiler wouldn’t know what a length is, and would complain when we try 
    to define a variable using that type. The definition for length doesn’t create an object -- it just tells the compiler 
    what a length is so it can be used later.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "What are user-defined / program-defined types?" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Back in the introduction to this chapter (9.1 -- Introduction to compound data types), we introduced the challenge of wanting 
    to store a fraction, which has a numerator and denominator that are conceptually linked together. In that lesson, we discussed 
    some of the challenges with using two separate integers to store a fraction’s numerator and denominator independently.

    If C++ had a built-in fraction type, that would have been perfect -- but it doesn’t. And there are hundreds of other 
    potentially useful types that C++ doesn’t include because it’s just not possible to anticipate everything that someone might 
    need (let alone implement and test those things).

    Instead, C++ solves for such problems in a different way: by allowing us to create entirely new, custom types for use in our 
    programs! Such types are often called user-defined types (though we think the term program-defined types is better -- we’ll 
    discuss the difference later in this lesson). C++ has two categories of compound types that allow for this: the enumerated 
    types (including unscoped and scoped enumerations), and the class types (including structs, classes, and unions).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Defining program-defined types" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Just like type aliases, program-defined types must also be defined before they can be used. The definition for a 
    program-defined type is called a type definition.

    Although we haven’t covered what a struct is yet, here’s an example showing the definition of custom Fraction type and an 
    instantiation of an object using that type:
    */
    Fraction f{ 3, 4 };// this actually instantiates a Fraction object named f

    /*
    In this example, we’re using the struct keyword to define a new program-defined type named Fraction (in the global scope, 
    so it can be used anywhere in the rest of the file). This doesn’t allocate any memory -- it just tells the compiler what a 
    Fraction looks like, so we can allocate objects of a Fraction type later. Then, inside main(), we instantiate (and initialize) 
    a variable of type Fraction named f.

    Program-defined type definitions always end in a semicolon. Failure to include the semicolon at the end of a type definition 
    is a common programmer error, and one that can be hard to debug because the compiler will usually error on the line after the 
    type definition. For example, if you remove the semicolon from the end of the Fraction definition (line 8) of the example 
    above, the compiler will probably complain about the definition of main() (line 11).

    Warning

    Don’t forget to end your type definitions with a semicolon, otherwise the compiler will typically error on the next line of 
    code.

    We’ll show more examples of defining and using program-defined types in the next lesson (9.14 -- Unscoped enumerations), 
    and we cover structs starting in lesson 9.17 -- Introduction to structs, members, and member selection.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Naming program-defined types" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    By convention, program-defined types are named starting with a capital letter and don’t use a “_t” suffix (e.g. Fraction, 
    not fraction or fraction_t). This nomenclature helps differentiate program-defined type names from type aliases (which often 
    use a “_t” or “_type” suffix) and variable names (which start with a lower case letter).

    Best practice

    Whenever you create a new program-defined type, name it starting with a capital letter.

    New programmers sometimes find variable definitions such as the following confusing because of the similarity between the 
    type name and variable name:
    */

    Fraction fraction{}; // Instantiates a variable named fraction of type Fraction

    /*
    But this is no different than any other variable definition: the type (Fraction) comes first 
    (and because Fraction is capitalized, we know it’s a program-defined type), then the variable name (fraction), 
    and then an optional initializer. Because C++ is case-sensitive, there is no naming conflict here!
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using program-defined types throughout a multi-file program" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */



    return 0;
}