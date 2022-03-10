#ifndef FRACTION2_H
#define FRACTION2_H


// Define a new type named Fraction
// This only defines what a Fraction looks like, it doesn't create one
// Note that this is a full definition, not a forward declaration
struct Fraction2
{
    int numerator{};
    int denominator{};

    Fraction2(int x, int y)
        : numerator{ x }, denominator{ y }
    {
    }
};


#endif // end FRACTION2_H