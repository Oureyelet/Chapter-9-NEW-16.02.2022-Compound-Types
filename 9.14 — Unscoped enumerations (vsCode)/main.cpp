#include <iostream>

// Define a new unscoped enumeration named Color
enum Color
{
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    yellow,
    pink,
    black,// trailing comma optional but recommended
};// the enum definition must end with a semicolon


int main()
{
    /*
    C++ contains many useful fundamental and compound data types (which we introduced in lessons 4.1 -- Introduction to 
    fundamental data types and 4.11 -- Chars). But these types aren’t always sufficient for the kinds of things we want to do.

    For example, let’s say you’re writing a program that needs to keep track of whether an apple is red, yellow, or green, or 
    what color a shirt is (from a preset list of colors). If only fundamental types were available, how might you do this?

    You might store the color as an integer value, using some kind of implicit mapping (0 = red , 1 = green, 2 = blue):
    */

    int appleColor{ 0 }; // my apple is red
    int shirtColor{ 1 }; // my shirt is green

    /*
    But this isn’t at all intuitive, and we’ve already discussed why magic numbers are bad (4.15 -- Symbolic constants: const 
    and constexpr variables). We can get rid of the magic numbers by using symbolic constants:
    */

    constexpr int red{ 0 };
    constexpr int green{ 1 };
    constexpr int blue{ 2 };

    int colorApple{ red };
    int colorShirt{ green };

    /*
    While this is a bit better for reading, the programmer is still left to deduce that appleColor and shirtColor 
    (which are of type int) are meant to hold one of the values defined in the set of color symbolic constants (which are likely 
    defined elsewhere, probably in a separate file).

    We can make this program a little more clear by using a type alias:
    */

    using color_t = int; // define a type alias named color_t

    // The following color values should be used for a color_t
    constexpr color_t red2{ 0 };
    constexpr color_t green2{ 1 };
    constexpr color_t blue2{ 2 };

    color_t colorApple2{ red2 };
    color_t colorShirt2{ green2 };

    /*
    We’re getting closer. Someone reading this code still has to understand that these color symbolic constants are meant to be 
    used with variables of type color_t, but at least the type has a unique name now so someone searching for color_t would be 
    able to find the set of associated symbolic constants.

    However, because color_t is just an alias for an int, we still have the problem that nothing enforces proper usage of these 
    color symbolic constants. We can still do something like this:
    */

    color_t eyeColor{ 8 };// syntactically valid, semantically meaningless

    /*
    Also, if we debug any of these variables in our debugger, we’ll only see the integer value of the color (e.g. 0), not the 
    symbolic meaning (red), which can make it harder to tell if our program is correct.

    Fortunately, we can do even better.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Enumerations" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    An enumeration (also called an enumerated type or an enum) is a compound data type where every possible value is defined as a 
    symbolic constant (called an enumerator).

    Because enumerations are program-defined types 9.13 -- Introduction to program-defined (user-defined) types, each enumeration 
    needs to be defined before we can use it to create objects using that enumerated type.

    C++ supports two kinds of enumerations: unscoped enumerations (which we’ll cover now) and scoped enumerations (which we’ll 
    cover later in this chapter).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Unscoped enumerations" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Unscoped enumerations are defined via the enum keyword.

    Enumerated types are best taught by example, so let’s define an unscoped enumeration that can hold some color values. 
    We’ll explain how it all works below.
    */

    // Define a few variables of enumerated type Color
    Color apple{ yellow };  // my apple is red
    Color shirt{ pink };// my shirt is green
    Color cup{ black };   // my cup is blue

    /*
    Color socks { white }; // error: white is not an enumerator of Color
    Color hat { 2 };       // error: 2 is not an enumerator of Color
    */

    /*
    We start our example by using the enum keyword to tell the compiler that we are defining an unscoped enumeration, 
    which we’ve named Color.

    Inside a pair of curly braces, we define the enumerators for the Color type: red, green, and blue. These enumerators 
    specify the set of possible values that objects of type Color will be able to hold. Each enumerator must be separated by a 
    comma (not a semicolon) -- a trailing comma after the last enumerator is optional but recommended for consistency.

    The type definition for Color ends with a semicolon. We’ve now fully defined what enumerated type Color is!

    Inside main(), we instantiate three variables of type Color: apple is initialized with the color red, shirt is initialized 
    with the color green, and cup is initialized with the color blue. Memory is allocated for each of these objects. Note that 
    the initializer for an enumerated type must be one of the defined enumerators for that type. The variables socks and hat 
    cause compile errors because the initializers white and 2 are not enumerators of Color.

    A reminder

    To quickly recap on nomenclature:

        An enumeration or enumerated type is the program-defined type itself (e.g. Color)
        An enumerator is a symbolic constant that is a possible value for a given enumeration (e.g. red)
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Naming enumerations and enumerators" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    By convention, the names of enumerated types start with a capital letter (as do all program-defined types).

    Warning

    Enumerations don’t have to be named, but unnamed enumerations should be avoided in modern C++.

    Enumerators must be given names. Unfortunately, there is no common naming convention for enumerator names. Common choices 
    include starting with lower case (e.g. red), starting with caps (Red), all caps (RED), all caps with a prefix (COLOR_RED), 
    or prefixed with a “k” and intercapped (kColorRed).

    Modern C++ guidelines typically recommend avoiding the all caps naming conventions, as all caps is typically used for 
    preprocessor macros and may conflict. We recommend also avoiding the conventions starting with a capital letter, as names 
    beginning with a capital letter are typically reserved for program-defined types.

    Best practice

    Name your enumerated types starting with a capital letter. Name your enumerators starting with a lower case letter.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Enumerated types are distinct types" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Each enumerated type you create is considered to be a distinct type, meaning the compiler can distinguish it from other 
    types (unlike typedefs or type aliases, which are considered non-distinct from the types they are aliasing).

    Because enumerated types are distinct, enumerators defined as part of one enumerated type can’t be used with objects of 
    another enumerated type:
    
    enum Pet
    {
        cat,
        dog,
        pig,
        whale,
    };

    enum Color
    {
        black,
        red,
        blue,
    };

    int main()
    {
        Pet myPet { black }; // compile error: black is not an enumerator of Pet
        Color shirt { pig }; // compile error: pig is not an enumerator of Color

        return 0;
    }

    You probably didn’t want a pig shirt anyway.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Putting enumerations to use" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */

    return 0;
}