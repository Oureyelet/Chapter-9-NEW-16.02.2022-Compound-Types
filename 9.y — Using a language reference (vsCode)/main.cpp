#include <iostream>
#include <string>
#include <limits> // for std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

int getUserInput()
{
    int i{};
    std::cin >> i;
    return i;
}

int main()
{
    //cppreferences.com example:
    std::string txt{ "Hello World!" };
    std::cout << txt.length() << '\n'; // print 12

    std::string name{};
    std::cout << "What's your name? " << '\n';
    std::cout << ':';
    std::cin >> name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Remove the extraneous newline character


    //A language grammar example:
    std::cout << "How many bananas did you eat today? \n";

    if (int iBananasEaten{ getUserInput() }; iBananasEaten <= 2)
    {
        std::cout << "Yummy\n";
    }
    else
    {
        std::cout << iBananasEaten << " is a lot!\n";
    }


    //Quiz time:
    /*
    Question #1

    What does the following program print? Don’t run it, use a reference to figure out what erase does.

    #include <iostream>
    #include <string>

    int main()
    {
    std::string str{ "The rice is cooking" };

    str.erase(4, 11);

    std::cout << str << '\n';

    return 0;
    }

    Tip

    When you find erase on cppreference, you can ignore the function signatures (2) and (3).

    Tip

    Indexes in C++ start at 0. The character at index 0 in the string “House” is ‘H’, at 1 it’s ‘o’, and so on.
    */
    std::string str{ "The rice is cooking" };

    str.erase(4, 11);

    std::cout << str << '\n'; // print The King

    /*
    Question #2

    In the following code, modify str so that its value is “I saw a blue car yesterday” without repeating the string. 
    For example, don’t do this:

    str = "I saw a blue car yesterday.";

    You only need to call one function to replace “red” with “blue”.

    #include <iostream>
    #include <string>

    int main()
    {
    std::string str{ "I saw a red car yesterday." };

    // ...

    std::cout << str << '\n'; // I saw a blue car yesterday.

    return 0;
    }
    */
    std::string str2{ "I saw a red car yesterday." };

    //str.replace(8,6,"a shorty",7);
    str2.replace(8,3, "blue");

    std::cout << str2 << '\n'; // print // I saw a blue car yesterday.  

    return 0;
}