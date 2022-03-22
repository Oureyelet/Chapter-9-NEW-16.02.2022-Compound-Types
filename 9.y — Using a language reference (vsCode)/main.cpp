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


    return 0;
}