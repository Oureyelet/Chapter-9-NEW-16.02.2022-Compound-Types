#include <iostream>
#include <string>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

void printEmployee(const Employee& e)
{
    // Use member selection opeartor (.) to select member from reference to struct
    std::cout << "Id: " << e.id << '\n';
    std::cout << "Age: " << e.age << '\n';
    std::cout << "Wage: " << e.wage << '\n';
}

struct Paw
{
    int claws{};
};

struct Animal
{
    std::string name{};
    Paw paw{};
};




int main()
{
    //Member selection for structs and references to structs:
    Employee joe { 1, 34, 65000.0 };

    // Use member selection operator (.) to select a member from struct object
    ++joe.age;// Joe had a birthday
    joe.wage = 68000.0;// Joe got a promotion

    printEmployee(joe);

    
    //Member selection for pointers to structs;
    Employee* ptr{ &joe };
    std:;cout << (*ptr).age << '\n';// Not great but works: First dereference ptr, then use member selection
    std::cout << ptr->age << '\n';// Better: use -> to select member from pointer to object

    //Mixing pointers and non-pointers to members:
    Animal puma{ "Puma", { 5 } };

    Animal* ptr_puma{ &puma };

    // ptr is a pointer, use ->
    // paw is not a pointer, use .
    std::cout << ptr_puma->paw.claws << '\n';
    



    return 0;
}