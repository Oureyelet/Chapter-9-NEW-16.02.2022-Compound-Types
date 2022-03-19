#include <iostream>
#include <string>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

struct Company
{
    std::string name{};
    Employee CEO{}; // Employee is a struct within the Company struct
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

Point3d getOnePoint()
{
    return Point3d{ 1.0, 1.0, 1.0 }; //returning a temporary (unnamed) object Point3d
}

Point3d getTwoPoint()
{
    // We already specified the type at the function declaration
    // so we don't need to do so here again
    return { 2.0, 2.0, 2.0 };// return an unnamed Point3d
}

Point3d getDefaultZeroPoint()
{
    return {}; // We can use empty curly braces to value-initialize all members
}

struct Christian
{
    struct Catholic// accessed via Christian::Cathlic
    {
        std::string name{};
        int age{};
        std::string gender{};
    };

    int numberOfChristians{};
    Catholic member{}; // Catholic is a struct within the Christian struct
    
};

struct Foo
{
    int a{};
    int b{};
    int c{};
};

struct Advertisement
{
    double howManyADS{};
    double percentage{};
    double earned{};
};

Advertisement readUserInfo()
{
    Advertisement today;

    std::cout << "How mnay ads was showed: ";
    std::cin >> today.howManyADS;

    std::cout << "How mnay percentage were clicked on by users: ";
    std::cin >> today.percentage;

    std::cout << "How much you earned on average from each ad that was clicked: ";
    std::cin >> today.earned;

    return today;
}

void printAdsInfo(const Advertisement& ads)
{
    std::cout << "You showed " << ads.howManyADS << " ads." << '\n';
    std::cout << "Percentage of ads were clicked on by users " << ads.percentage << "%." << '\n';
    std::cout << "You earned from each ad: " << ads.earned << "$." << '\n';

    std::cout << "Today you earned: " << ads.earned * ads.howManyADS * ads.percentage << "$\n";
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
        std::cout << "The point is more then zero\n";
    

    //Returning unnamed structs:
    Point3d one{ getOnePoint() };

    if(one.x == 0.0 && one.y == 0.0 && one.z == 0.0)
        std::cout << "The point is zero\n";
    else 
        std::cout << "The point is more then zero\n";


    Point3d two{ getTwoPoint() };

    Point3d default_point_zero{ getDefaultZeroPoint() };

    std::cout << '\n';

    //Structs with program-defined members:
    Company myCompany{ "Cod Mood", { 1, 29, 20.00 } };// Nested initialization list to initialize Employee  
    std::cout << "CEO wage is: " << myCompany.CEO.wage << '\n'; // print the CEO's wage

    Christian anna{ 1, { "Anna", 32, "female" } }; // Nested initialization list to initialize Catholic
    std::cout << "gender of our first member is :" << anna.member.gender << '\n'; // print gender of anna


    //Struct size and data structure alignment:
    std::cout << "The size off Foo struct is: " << sizeof(Foo) << '\n';


    //Quiz time:

    /*
    Question #1

    You are running a website, and you are trying to keep track of how much money you make per day from advertising. 
    Declare an advertising struct that keeps track of how many ads you’ve shown to readers, what percentage of ads were 
    clicked on by users, and how much you earned on average from each ad that was clicked. Read in values for each of these 
    fields from the user. Pass the advertising struct to a function that prints each of the values, and then calculates how much 
    you made for that day (multiply all 3 fields together).
    */
    printAdsInfo( readUserInfo() );


    return 0;
}