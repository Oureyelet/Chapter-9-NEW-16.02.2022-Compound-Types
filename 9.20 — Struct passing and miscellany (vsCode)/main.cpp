#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

void printEmployee(int id, int age, double wage)
{
    std::cout << "ID: " << id << '\n';
    std::cout << "Age: " << age << '\n';
    std::cout << "Wage: " << wage << '\n';
}

void printEmployee_by_const_reference(Employee& employee)// note pass by reference here
{
    std::cout << "ID: " << employee.id << '\n';
    std::cout << "Age: " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

struct Point3d
{
    double x{ 0.0 };
    double y{ 0.0 };
    double z{ 0.0 };
};

Point3d getZeroPoint()
{
    Point3d temp{ 0.0, 0.0, 0.0 };// We can create a variable and return the variable (we'll improve this below)
    return temp;
}



int main()
{
    int id{ 1 };
    int age{ 24 };
    double wage{ 52400.0 };

    printEmployee(id, age, wage);

    std::cout << '\n';

    //Passing structs (by reference):
    Employee joe{ 14, 32, 24.15 };
    Employee frank{ 15, 28, 18.27 };

    printEmployee_by_const_reference(joe);// Print Joe's information

    std::cout << '\n';

    printEmployee_by_const_reference(frank);// Print Frank's information


    //Returning structs:
    Point3d zero{ getZeroPoint() };

    if(zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else 
        std::cout << "The point is not zero\n";
    

    //Returning unnamed structs:
    



    return 0;
}