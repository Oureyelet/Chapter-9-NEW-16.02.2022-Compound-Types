#include <iostream>
#include <string>
#include <string_view>

enum Color
{
    color_black, // assigned 0
    color_red, // assigned 1
    color_blue, // assigned 2
    color_green, // assigned 3
    color_white, // assigned 4
    color_cyan, // assigned 5
    color_yellow, // assigned 6 
    color_magenta, // assigned 7
};

enum Animal
{
    animal_cat = -3,
    animal_dog,         // assigned -2
    animal_pig,         // assigned -1
    animal_horse = 5,
    animal_giraffe = 5, // shares same value as horse
    animal_chicken,     // assigned 6
};

void printColor(Color color)
{
    if(color == color_black) std::cout << "black";
    else if(color == color_red) std::cout << "red";
    else if(color == color_blue) std::cout << "blue";
    else if(color == color_yellow) std::cout << "yellow";
    else std::cout << "???";
}

std::string getColor(Color color)
{
    switch (color)
    {
    case color_black: return "black";
    case color_red: return "red";
    case color_blue: return "blue";
    default: return "???";
    }
}

constexpr std::string_view getColor_view(Color color)
{
    switch (color)
    {
    case color_black: return "black";
    case color_red: return "red";
    case color_blue: return "blue";
    default: return "???";
    }
}

std::ostream& operator<<(std::ostream& out, Color color)
{
    switch (color)
    {
    case color_black: out << "black"; break;
    case color_red:   out << "red"; break;
    case color_blue:  out << "blue"; break;
    case color_white: out << "white"; break;
    default:          out << "???"; break;
    }

    return out;
}

namespace enumeration_size_and_base
{
    // Use an 8-bit unsigned integer as the enum base
    enum Color : std::uint8_t
    {
        color_black, 
        color_red, 
        color_blue,
        color_green,
        color_white,
        color_cyan, 
        color_yellow, 
        color_magenta,
    };
}

enum Pet
{
    pet_cat,// assigned 0
    pet_dog,// assigned 1
    pet_pig,// assigned 2
    pet_whale,// assigned 3
};

std::ostream& operator<<(std::ostream& out, Pet pet)
{
    switch (pet)
    {
    case pet_cat: return out << "cat"; break;
    case pet_dog: return out << "dog"; break;
    case pet_pig: return out << "pig"; break;
    case pet_whale: return out << "whale"; break;
    default: return out << "something went wrong"; break;
    }
}

namespace specified_a_base
{
    enum Pet: int
    {
        pet_cat,// assigned 0
        pet_dog,// assigned 1
        pet_pig,// assigned 2
        pet_whale,// assigned 3
    };
}

int main()
{
    /*
    In the prior lesson (9.14 -- Unscoped enumerations), we mentioned that enumerators are symbolic constants. 
    What we didn’t tell you then is that enumerators are integral symbolic constants. As a result, enumerated types 
    actually hold an integral value.

    This is similar to the case with chars (4.11 -- Chars). Consider:
    */
    
    char ch{ 'A' };
    char ch_int{ 65 };

    std::cout << ch << ' ' << ch_int << '\n';

    /*
    A char is really just a 1-byte integral value, and the character 'A' gets converted to an integral value (in this case, 65) 
    and stored.

    When we define an enumerator, each enumerator is automatically assigned an integer value based on its position in the 
    enumerator list. By default, the first enumerator is assigned the integral value 0, and each subsequent enumerator has a 
    value one greater than the previous enumerator:
    */

    //go see our enum Color above main()

    Color shirt{ color_blue }; // This actually stores the integral value 2

    std::cout << shirt << '\n';

    /*
    It is possible to explicitly define the value of enumerators. These integral values can be positive or negative, and can 
    share the same value as other enumerators. Any non-defined enumerators are given a value one greater than the previous 
    enumerator.
    */

    //go see our enum Animal above main()

    /*
    Note in this case, horse and giraffe have been given the same value. When this happens, the enumerators become 
    non-distinct -- essentially, horse and giraffe are interchangeable. Although C++ allows it, assigning the same value to 
    two enumerators in the same enumeration should generally be avoided.

    Best practice

    Avoid assigning explicit values to your enumerators unless you have a compelling reason to do so.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz timeUnscoped enumerations will implicitly convert to integral values" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Consider the following program:
    */

    // go see our enum Color above main)()

    Color pants{ color_blue };

    std::cout << "Your pants are: " << pants << '\n'; // what does this do?

    /*
    Since enumerated types hold integral values, as you might expect, this prints:

    Your shirt is 2

    When an enumerated type is used in a function call or with an operator, the compiler will first try to find a function or 
    operator that matches the enumerated type. For example, when the compiler tries to compile std::cout << shirt, the compiler 
    will first look to see if std::cout knows how to print an object of type Color (because shirt is of type Color). It doesn’t.

    If the compiler can’t find a match, the compiler will then implicitly convert an unscoped enumeration or enumerator to its 
    corresponding integer value. Because std::cout does know how to print an integral value, the value in shirt gets converted 
    to an integer and printed as integer value 2.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Printing enumerator names" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Most of the time, printing an enumeration as an integral value (such as 2) isn’t what we want. Instead, we typically will 
    want to print the name of whatever the enumerator represents (blue). But to do that, we need some way to convert the integral 
    value of the enumeration (2) into a string matching the enumerator name ("blue").

    As of C++20, C++ doesn’t come with any easy way to do this, so we’ll have to find a solution ourselves. Fortunately, that’s 
    not very difficult. The typical way to do this is to write a function that takes an enumerated type as a parameter and then 
    outputs the corresponding string (or returns the string to the caller).

    The typical way to do this is to test our enumeration against every possible enumerator:
    */

    //see our void printColor function above main()

    printColor(color_yellow);
    std::cout << std::endl;

    /*
    However, using a series of if-else statements for this is inefficient, as it requires multiple comparisons before a 
    match is found. A more efficient way to do the same thing is to use a switch statement. In the following example, we 
    will also return our Color as a std::string, to give the caller more flexibility to do whatever they want with the name 
    (including print it):
    */

    //see our void getColor function above main()

    std::cout << getColor(color_blue) << std::endl;

    Color shirt2{ color_red };

    std::cout << "Your shirt is: " << getColor(shirt2) << '\n';

    /*
    This prints:

    Your shirt is blue

    This likely performs better than the if-else chain (switch statements tend to be more efficient than if-else chains), 
    and it’s easier to read too. However, this version is still inefficient, because we need to create and return a std::string 
    (which is expensive) every time the function is called.

    In C++17, a more efficient option is to replace std::string with std::string_view. std::string_view allows us to return 
    string literals in a way that is much less expensive to copy.
    */

    // go see our new getColor_view funstion above main()

    Color hat{ color_blue };

    std::cout << "Our hat is: " << getColor_view(hat) << '\n';


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Teaching std::cout how to print an enumerator" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Although the above example functions well, we still have to remember the name of the function we created to get the 
    enumerator name. While this usually isn’t too burdensome, it can become more problematic if you have lots of enumerations. 
    Using operator overloading (a capability similar to function overloading), we can actually teach std::cout how to print the 
    value of a program-defined enumeration! We haven’t explained how this works yet, so consider it a bit of magic for now:
    */

    //see our overload operator<< function above main() 

    Color boots{ color_white };

    std::cout << boots << '\n'; // it works!

    /*
    This prints:

    Your shirt is blue

    For advanced readers

    For the curious, here’s what the above code is actually doing. When we try to print shirt using std::cout and operator<<, 
    the compiler will see that we’ve overloaded operator<< to work with objects of type Color. This overloaded operator<< 
    function is then called with std::cout as the out parameter, and our shirt as parameter color. Since out is a reference to 
    std::cout, a statement such as out << "blue" is really just printing "blue" to std::cout.

    We cover overloading the I/O operators in lesson 13.4 -- Overloading the I/O operators. For now, you can copy this code and 
    replace Color with your own enumerated type.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Enumeration size and base" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Enumerated types are considered part of the integer family of types, and it’s up to the compiler to determine how much 
    memory to allocate for an enum variable. The C++ standard says the enum size needs to be large enough to represent all of 
    the enumerator values. Most often, it will make enum variables the same size as a standard int.

    However, it is possible to specify a different underlying type. For example, if you are working in some bandwidth-sensitive 
    context (e.g. sending data over a network) you may want to specify a smaller type:
    */

    //see our enumeration_size_and_base namespace with new enum Color: std::uint8_t

    std::cout << enumeration_size_and_base::color_blue << '\n';

    /*
    Since enumerators aren’t usually used for arithmetic or comparisons with integers, it’s generally safe to use an unsigned 
    integer if desired.

    Best practice

    Specify the base type of an enumeration only when necessary.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Integer to unscoped enumerator conversion" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    While the compiler will implicitly convert unscoped enumerators to an integer, it will not implicitly convert an integer 
    to an unscoped enumerator. The following will produce a compiler error:

    #include <iostream>

    enum Pet
    {
        cat, // assigned 0
        dog, // assigned 1
        pig, // assigned 2
        whale, // assigned 3
    };

    int main()
    {
        Pet pet { 2 }; // compile error: integer value 2 won't implicitly convert to a Pet
        pet = 3;       // compile error: integer value 1 won't implicitly convert to a Pet

        return 0;
    }

    There are two ways to work around this.

    First, you can force the compiler to convert an integer to an unscoped enumerator using static_cast:
    */

    Pet pet{ static_cast<Pet>(2) };// convert integer 2 to a Pet

    pet = static_cast<Pet>(3);// our pig evolved into a whale!

    /*
    We’ll see an example in a moment where this can be useful.

    Second, in C++17, if an unscoped enumeration has a specified base, then the compiler will allow you to initialize 
    (but not assign) an unscoped enumeration using an integral value:
    */

    specified_a_base::Pet pet2{ 2 }; // ok: can initialize with integer

    // pet2 = 1; // compile error: can not assign with integer


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Unscoped enumerator input" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): ";

    int input{};
    std::cin >> input; // input an integer

    Pet homePet{ static_cast<Pet>(input) }; // static_cast our integer to a pet

    std::cout << homePet << '\n'; // i added overloading function for print string: cat, dog, pig or whale :)

    
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz Time" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Question #1

    True or false. Enumerators can be:

        Given an integer value

    Show Solution

        Not assigned a value

    Show Solution

        Given a floating point value

    Show Solution

        Given a negative value

    Show Solution

        Given a non-unique value

    Show Solution

        Initialized with the value of prior enumerators (e.g. magenta = red)

    Show Solution
    */

    

    return 0;
}