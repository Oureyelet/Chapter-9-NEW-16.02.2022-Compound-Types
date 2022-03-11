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

enum DaysOfWeek
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
};

enum CardinalDirections
{
    north,
    east,
    south,
    west,
};

enum CardSuits
{
    clubs,
    diamonds,
    hearts,
    spades,
};

int readFileContents(int (*openFile)(), int (*readFile)(), int (*parseFile)()) 
{
    if(!openFile())
        return -1;
    if(!readFile())
        return -2;
    if(!parseFile())
        return -3;

    return 0; //success
}

enum FileReadResult
{
    readResultSuccess,
    readResultErrorFileOpen,
    readResultErrorFileRead,
    readResultErrorFileParse,
};

FileReadResult readFileContents(int openFile, int readFile, int parseFile)
{
    if(!openFile)
        return readResultErrorFileOpen;
    if(!readFile)
        return readResultErrorFileRead;
    if(!parseFile)
        return readResultErrorFileParse;
    
    return readResultSuccess; //success   
}

enum ItemType
{
    sword,
    torch,
    potion,
};

enum SortOrder
{
    alphabetical,
    alphabeticalReverse,
    numerical,
};

void sortData(SortOrder order)
{
    if( order == numerical )
    {
        // sort data in forwards alphabetical order
    }
    else if( order == alphabeticalReverse )
    {
        // sort data in backwards alphabetical order
    }
    else if( order == alphabetical )
    {
        // sort data numerically
    }
}

enum Color3
{
    color3_yellow,
    color3_red,
    color3_blue,
};

enum Feeling
{
    feeling_happy,
    feeling_tired,
    feeling_blue,// no longer has a naming collision with color_blue
};

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
    Because enumerators are descriptive, they are useful for enhancing code documentation and readability. 
    Enumerated types are best used when you have a smallish set of related constants, and objects only need to hold one of 
    those values at a time.

    Commonly defined enumerations include days of the week, the cardinal directions, and the suits in a deck of cards:
    
    Go see our new enums above main():

    DaysOfWeek
    CardinalDirections
    CardSuits

    Sometimes functions will return a status code to the caller to indicate whether the function executed successfully or 
    encountered an error. Traditionally, small negative numbers were used to represent different possible error codes. 
    For example:
    
    Go see our 'readFileContents' function above main()

    However, using magic numbers like this isn’t very descriptive. A better method would be to use an enumerated type:

    See our enum 'FileReadResult' and 'readFileContents' function above main()

    Then the caller can test the function’s return value against the appropriate enumerator, which is easier to 
    understand than testing the return result for a specific integer value.
    */

    /*
    if(readFileContents() == readResultSuccess)
    {
        // do something
    }
    else
    {
        // print error message
    }
    */

    /*
    Enumerated types can also be put to good use in games, to identify different types of items, or monsters, or terrain types. 
    Basically, anything that is a small set of related objects.

    For example:
    */

    ItemType holding{ torch };

    /*
    Enumerated types can also make for useful function parameters when the user needs to make a choice between two or 
    more options:
    */

    //see our enum SortOrder

    // see our function sortData

    /*
    Many languages use enumerations to define Booleans -- after all, a Boolean is essentially just an enumeration with 2 
    enumerators: false and true! However, in C++, true and false are defined as keywords instead of enumerators.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The scope of unscoped enumerations" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Unscoped enumerations are named such because they put their enumerator names into the same scope as the enumeration 
    definition itself (as opposed to creating a new scope region like a namespace does).

    For example, given this program:
    */

    // see our enum Color (blue is put into the global namespace)

    Color banana{ yellow };// my banana is yellow

    /*
    The Color enumeration is defined in the global scope. Therefore, all the enumeration names (red, green, and blue) 
    also go into the global scope. This pollutes the global scope and significantly raises the chance of naming collisions.

    One consequence of this is that an enumerator name can’t be used in multiple enumerations within the same scope:
    
    enum Color
    {
        red,
        green,
        blue, // blue is put into the global namespace
    };

    enum Feeling
    {
        happy,
        tired,
        blue, // error: naming collision with the above blue
    };

    int main()
    {
        Color apple { red }; // my apple is red
        Feeling me { happy }; // I'm happy right now (even though my program doesn't compile)

        return 0;
    }
    */

    /*
    In the above example, both unscoped enumerations (Color and Feeling) put enumerators with the same name blue into the global 
    scope. This leads to a naming collision and subsequent compile error.

    Unscoped enumerations also provide a named scope region for their enumerators (much like a namespace acts as a named scope 
    region for the names declared within). This means we can access the enumerators of an unscoped enumeration as follows:
    */

    Color waterMelon{ yellow };// okay, accessing enumerator from global namespace
    Color cucumber{ Color::yellow };// also okay, accessing enumerator from scope of Color
    Color son{ yellow }; // ang again okay !

    /*
    Most often, unscoped enumerators are accessed without using the scope resolution operator.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Avoiding enumerator naming collisions" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    There are quite a few common ways to prevent unscoped enumerator naming collisions. One option is to prefix each 
    enumerator with the name of the enumeration itself:
    */

    //see our enum Color3 and Feeling please

    Color3 paint{ color3_blue };
    Feeling me{ feeling_blue };

    /*
    This still pollutes the namespace but reduces the chance for naming collisions by making the names longer and more unique.

    A better option is to put the enumerated type inside something that provides a separate scope region, such as a namespace:
    */


    return 0;
}