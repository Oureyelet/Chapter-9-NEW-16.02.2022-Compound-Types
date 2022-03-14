#include <iostream>
#include <string_view>

enum class Color// "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
{
    red_color,// red is considered part of Color's scope region
    blue_color,
};

enum class Fruit
{
    banana_fruit,// banana is considered part of Fruit's scope region
    apple_fruit,
};

std::ostream& operator<<(std::ostream& out, Fruit ft)
{
    switch (ft)
    {
    case Fruit::apple_fruit: return out << "apple"; break;
    case Fruit::banana_fruit: return out << "banana"; break;    
    default: return out << "somenthing went wrong"; break;
    }
}

enum class Animals
{
    chicken, // 0
    dog, // 1
    cat, // 2
    elephant, // 3
    duck, // 4 
    snake, // 5

    maxAnimals, // 6
};

constexpr auto operator+(Animals a) noexcept
{
    return static_cast<std::underlying_type_t<Animals>>(a);
}

enum class Animal
{
    pig,
    chicken, 
    goat, 
    cat, 
    dog, 
    duck,
};

constexpr std::string_view getAnimalName(Animal ani)
{
    switch (ani)
    {
        case Animal::cat: return "cat"; break;
        case Animal::chicken: return "chicken"; break;
        case Animal::dog: return "dog"; break;
        case Animal::duck: return "duck"; break;
        case Animal::goat: return "goat"; break;
        case Animal::pig: return "pig"; break;
        default: return "???"; break;
    }
}

void printNumberOfLegs(Animal ani)
{
    std::cout << "A " << getAnimalName(ani) << " has ";

    switch (ani)
    {
        case Animal::cat: std::cout << 4; break;
        case Animal::chicken: std::cout << 2; break;
        case Animal::dog: std::cout << 4; break;
        case Animal::duck: std::cout << 2; break;
        case Animal::goat: std::cout << 2; break;
        case Animal::pig: std::cout << 4; break;
        default: std::cout << "something went wrong"; break;
    }

    std::cout << " legs.\n";
}

int main()
{
    Color color{ Color::red_color };// note: red is not directly accessible, we have to use Color::red 
    Fruit fruit{ Fruit::banana_fruit };// note: banana is not directly accessible, we have to use Fruit::banana

    //Scoped enumerations define their own scope regions:

    Color shirt{ Color::blue_color };

    //Scoped enumerations don’t implicitly convert to integers:

    if(shirt == Color::red_color)// this Color to Color comparison is okay
        std::cout << "Your shirt is red color" << '\n';
    else if(shirt == Color::blue_color )
        std::cout << "Your shirt is blue color" << '\n';

    std::cout << static_cast<int>(shirt) << '\n'; //explicitly convert a scoped enumeration to an integer

    std::cout << "Enter a pet (0=banana, 1=apple, 2=s/w, 3=s/w): ";
    int input{};
    std::cin >> input;

    Fruit banana{ static_cast<Fruit>(input) }; // static_cast our integer to a Fruit
    std::cout << banana << '\n';

    //Easing the conversion of scoped enumerators to integers (advanced):

    std::cout << +Animals::maxAnimals << '\n';// convert Animals::elephant to an integer using unary operator+

    //Quiz Time !

    /*
    Question #1

    Define an enum class named Animal that contains the following animals: pig, chicken, goat, cat, dog, duck. 
    Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement to return the name for 
    that animal as a std::string_view (or std::string if you’re using C++14). Write another function named printNumberOfLegs() 
    that uses a switch statement to print the number of legs each animal walks on. Make sure both functions have a default case 
    that prints an error message. Call printNumberOfLegs() from main() with a cat and a chicken. Your output should 
    look like this:

    A cat has 4 legs.
    A chicken has 2 legs.
    */

    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}