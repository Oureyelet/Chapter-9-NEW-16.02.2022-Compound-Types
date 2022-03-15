#include <iostream>

struct Employee
{
    int id;
    int age;
    double wage;
};


int main()
{
    //Defining structs: struct Employee

    

    //Defining struct objects:

    Employee joe; // Employee is the type, joe is the variable name
    Employee frank; // create an Employee struct for Frank

    //Accessing members:

    joe.age = 32; // use member selection operator (.) to select the age member of variable joe

    std::cout << joe.age << '\n'; // print joe's age

    Employee ania;
    ania.id = 1;
    ania.age = 32;
    ania.wage = 3.200;

    Employee sophie;
    sophie.id = 2;
    sophie.age = 1;
    sophie.wage = 10.500;

    int totalAge{ ania.age + sophie.age };

    if(ania.wage > sophie.wage)
        std::cout << "Ania makes more then Sophie" << '\n';
    else if(ania.wage < sophie.wage)
        std::cout << "Sophie makes more then Ania" << '\n';
    else
        std::cout << "Ania and Sophie makes the same amount" << '\n';

    //Ania got a promotion
    ania.wage += 500.0;

    //Today is Sophie's birthday
    ++sophie.age;// use pre-increment to increment Joe's age by 1

    std::cout << "Now Sophie is " << sophie.age << " years old :)" << '\n';

    

    return 0;
}