#include <iostream>
#include <string>
#include <string_view>

enum class Monster_type
{
    ogre,
    dragon,
    orc,
    spider,
    slime,

    max_monster,
};

struct Monster
{
    std::string name{};
    int hp{};
};

void printMonster(Monster_type type, Monster creatura)
{
    std::cout << "This ";

    switch (type)
    {
    case Monster_type::ogre: std::cout << "Ogre"; break;
    case Monster_type::dragon: std::cout <<  "Dragon"; break;
    case Monster_type::orc: std::cout <<  "Orc"; break;
    case Monster_type::spider: std::cout <<  "Spider"; break;
    case Monster_type::slime: std::cout <<  "Slime"; break;

    default: std::cout <<  "???"; break;
    }

    std::cout << " is named " << creatura.name << " and has " << creatura.hp << " health.\n";
}


int main()
{
    //Quiz time:

    /*
    In designing a game, we decide we want to have monsters, because everyone likes fighting monsters. Declare a struct that 
    represents your monster. The monster should have a type that can be one of the following: an ogre, a dragon, an orc, 
    a giant spider, or a slime. Use an enum class for this.

    Each individual monster should also have a name (use a std::string or std::string_view), as well as an amount of health that 
    represents how much damage they can take before they die. Write a function named printMonster() that prints out all of the 
    struct’s members. Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().

    Your program should produce the following output:

    This Ogre is named Torg and has 145 health.
    This Slime is named Blurp and has 23 health.
    */
    Monster ogre{ "Torg", 145 };
    printMonster(Monster_type::ogre, ogre);

    Monster slime{ "Blurp", 23 };
    printMonster(Monster_type::slime, slime);


    /*
    Question #2

    Specify whether objects of each of the given types should be passed by value, const address, or const reference. 
    You can assume the function that takes these types as parameters doesn’t modify them.

    a) char

    Show Solution

    b) std::string

    Show Solution

    c) unsigned long

    Show Solution

    d) bool

    Show Solution

    e) An enumerated type

    Show Solution

    f)

    struct Position
    {
    double x{};
    double y{};
    double z{};
    };

    Show Solution

    g)

    struct Player
    {
    int health{};
    // The Player struct is still under development.  More members will be added.
    };

    Show Solution

    h) an object whose address is held in an int*

    Show Solution
    */

    return 0;
}