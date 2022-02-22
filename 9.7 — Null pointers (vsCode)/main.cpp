#include <iostream>

void someFunction(double* x)
{

}

int main()
{
    /*
    In the previous lesson (9.6 -- Introduction to pointers), we covered the basics of pointers, which are objects that hold 
    the address of another object. This address can be dereferenced using the dereference operator (*) to get the value at that 
    address:
    */
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x

    int* ptr_x{ &x }; // ptr holds the address of x
    // use dereference operator to print the value at the address that ptr is holding (which is x's address)
    std::cout << *ptr_x << '\n';

    /*
    The above example prints:

    55

    In the prior lesson, we also noted that pointers do not need to point to anything. In this lesson, we’ll explore such 
    pointers (and the various implications of pointing to nothing) further.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Null pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Besides a memory address, there is one additional value that a pointer can hold: a null value. 
    A null value (often shortened to null) is a special value that means something has no value. When a pointer is holding a 
    null value, it means the pointer is not pointing at anything. Such a pointer is called a null pointer.

    The easiest way to create a null pointer is to use value initialization:
    */
    
    int* ptr{}; // ptr is now a null pointer, and is not holding an address

    /*
    Best practice

    Value initialize your pointers (to be null pointers) if you are not initializing them with the address of a valid object.

    Because we can use assignment to change what a pointer is pointing at, a pointer that is initially set to null can later 
    be changed to point at a valid object:
    */

    double* e_ptr{};// ptr is a null pointer, and is not holding an address
    
    double d{ 3.3 };
    e_ptr = &d;// ptr now pointing at object d (no longer a null pointer)

    std::cout << *e_ptr << '\n';// print value of d through dereferenced ptr


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The nullptr keyword" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Much like the keywords true and false represent Boolean literal values, the nullptr keyword represents a null pointer 
    literal. We can use nullptr to explicitly initialize or assign a pointer a null value.
    */

    double* db{ nullptr };// can use nullptr to initialize a pointer to be a null pointer

    double someValue{ 34.6 };
    double* ptr_someValue{ &someValue }; // ptr is a valid pointer

    ptr_someValue = nullptr;// Can assign nullptr to make the pointer a null pointer

    someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter

    /*
    In the above example, we use assignment to set the value of ptr2 to nullptr, making ptr2 a null pointer.

    Best practice

    Use nullptr when you need a null pointer literal for initialization, assignment, or passing a null pointer to a function.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Dereferencing a null pointer results in undefined behavior" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Much like dereferencing a dangling (or wild) pointer leads to undefined behavior, dereferencing a null pointer also leads 
    to undefined behavior. In most cases, it will crash your application.

    The following program illustrates this, and will probably crash or terminate your application abnormally when you run it 
    (go ahead, try it, you won’t harm your machine):
    */
    int* empty_ptr{ nullptr };

    // ERROR occurring
    // std::cout << *empty_ptr << '\n';

    /*
    Conceptually, this makes sense. Dereferencing a pointer means “go to the address the pointer is pointing at and access the 
    value there”. A null pointer doesn’t have an address. So when you try to access the value at that address, what should it do?

    Accidentally dereferencing null and dangling pointers is one of the most common mistakes C++ programmers make, and is 
    probably the most common reason that C++ programs crash in practice.

    Warning

    Whenever you are using pointers, you’ll need to be extra careful that your code isn’t dereferencing null or dangling 
    pointers, as this will cause undefined behavior (probably an application crash).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Checking for null pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Much like we can use a conditional to test Boolean values for true or false, we can use a conditional to test whether a 
    pointer has value nullptr or not:
    */

    int xOne{ 5 };
    int* ptr_xOne{ &xOne };

    // pointers convert to Boolean false if they are null, and Boolean true if they are non-null
    if(ptr_xOne == nullptr)// explicit test for equivalence
        std::cout << "ptr_xOne is null\n";
    else
        std::cout << "ptr_xOne is non-null\n";

    int* nullPtr{};
    // explicit test for equivalence
    std::cout << "nullPtr is: " << (nullPtr == nullptr ? "null\n" : "non-null\n");

    /*
    The above program prints:

    ptr is non-null
    nullPtr is null

    In lesson 4.9 -- Boolean values, we noted that integral values will implicitly convert into Boolean values: an integral 
    value of 0 converts to Boolean value false, and any other integral value converts to Boolean value true.

    Similarly, pointers will also implicitly convert to Boolean values: a null pointer converts to Boolean value false, and a 
    non-null pointer converts to Boolean value true. This allows us to skip explicitly testing for nullptr and just use the 
    implicit conversion to Boolean to test whether a pointer is a null pointer. The following program is equivalent to the 
    prior one:
    */
    int xTwo{ 5 };
    int* ptr_xTwo{ &xTwo };

    // pointers convert to Boolean false if they are null, and Boolean true if they are non-null
    if(ptr_xTwo)// implicit conversion to Boolean
        std::cout << "yuup ptr_xTwo is non-null.\n";
    else
        std::cout << "nope ! ptr_xTwo is null.\n";

    int* ptr_x1{};
    std::cout << (ptr_x1 ? "non-null\n" : "null\n");// implicit conversion to Boolean

    /*
    Warning

    Conditionals can only be used to differentiate null pointers from non-null pointers. There is no convenient way to 
    determine whether a non-null pointer is pointing to a valid object or dangling (pointing to an invalid object).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Use nullptr to avoid dangling pointers" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Above, we mentioned that dereferencing a pointer that is either null or dangling will result in undefined behavior. 
    Therefore, we need to ensure our code does not do either of these things.

    We can easily avoid dereferencing a null pointer by using a conditional to ensure a pointer is non-null before trying to 
    dereference it:
    */
    // Assume ptr is some pointer that may or may not be a null pointer
    if(ptr_xTwo)// if ptr is not a null pointer 
        std::cout << *ptr_xTwo << '\n';// okay to dereference
    else
    // do something else that doesn't involve dereferencing ptr (print an error message, do nothing at all, etc...)
        std::cout << "Dereferencing nullptrs ERROR !\n";

    /*
    But what about dangling pointers? Because there is no way to detect whether a pointer is dangling, we need to avoid having 
    any dangling pointers in our program in the first place. We do that by ensuring that any pointer that is not pointing at a 
    valid object is set to nullptr.

    That way, before dereferencing a pointer, we only need to test whether it is null -- if it is non-null, we assume the pointer 
    is not dangling.

    Best practice:

    A pointer should either hold the address of a valid object, or be set to nullptr. That way we only need to test pointers for 
    null, and can assume any non-null pointer is valid.

    Unfortunately, avoiding dangling pointers isn’t always easy: when an object is destroyed, any pointers to that object will be 
    left dangling. Such pointers are not nulled automatically! It is the programmer’s responsibility to ensure that all pointers 
    to an object that has just been destroyed are properly set to nullptr.

    Warning:

    When an object is destroyed, any pointers to the destroyed object will be left dangling (they will not be automatically set 
    to nullptr). It is your responsibility to detect these cases and ensure those pointers are subsequently set to nullptr.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Legacy null pointer literals: 0 and NULL" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In older code, you may see two other literal values used instead of nullptr.

    The first is the literal 0. In the context of a pointer, the literal 0 is specially defined to mean a null value, and is 
    the only time you can assign an integral literal to a pointer.
    */

    double* someDoublePTR{ 0 };// someDoublePTR is now a null pointer (for example only, don't do this)

    double someEmptyPTR;  // someEmptyPTR is uninitialized

    someEmptyPTR = 0; // someEmptyPTR is now a null pointer (for example only, don't do this)
    
    /*
    As an aside…

    On modern architectures, the address 0 is typically used to represent a null pointer. However, this value is not 
    guaranteed by the C++ standard, and some architectures use other values. The literal 0, when used in the context of a 
    null pointer, will be translated into whatever address the architecture uses to represent a null pointer.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Favor references over pointers whenever possible" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Pointers and references both give us the ability to access some other object indirectly.

    Pointers have the additional abilities of being able to change what they are pointing at, and to be pointed at null. 
    However, these pointer abilities are also inherently dangerous: A null pointer runs the risk of being dereferenced, and 
    the ability to change what a pointer is pointing at can make creating dangling pointers easier:
    */

    int* ptr_xTree{};

        {
            int xTree{ 5 };
            ptr_xTree = &xTree; // set the pointer to an object that will be destroyed (not possible with a reference)
        }// ptr is now dangling

    /*
    Since references can’t be pointed at null, we don’t have to worry about null dereferences. And because references must 
    be bound to a valid object upon creation and then can not be reseated, dangling references are harder to create.

    Because they are safer, references should be favored over pointers, unless the additional capabilities provided by pointers 
    are required.

    Best practice

    Favor references over pointers unless the additional capabilities provided by pointers are needed.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Question #1

    1a) Can we determine whether a pointer is a null pointer or not? If so, how?

    Show Solution

    1b) Can we determine whether a non-null pointer is valid or dangling? If so, how?

    Show Solution
    */

    /*
    Question #2

    For each subitem, answer “yes”, “no”, or “possibly” to whether the action described will result in undefined behavior 
    (immediately). If the answer is “possibly”, clarify when.

    2a) Assigning a new address to a pointer

    Show Solution

    2b) Assigning nullptr to a pointer

    Show Solution

    2c) Dereferencing a pointer to a valid object

    Show Solution

    2d) Dereferencing a dangling pointer

    Show Solution

    2e) Dereferencing a null pointer

    Show Solution

    2f) Dereferencing a non-null pointer

    Show Solution
    */

    /*
    Question #3

    Why should we set pointers that aren’t pointing to a valid object to ‘nullptr’?

    Show Solution:

    We can not determine whether a non-null pointer is valid or dangling, and accessing a dangling pointer will result in 
    undefined behavior. Therefore, we need to ensure that we do not have any dangling pointers in our program.

    If we ensure all pointers are either pointing to valid objects or set to nullptr, then we can use a conditional to test 
    for null to ensure we don’t dereference a null pointer, and assume all non-null pointers are pointing to valid objects.

    */

    return 0;
}