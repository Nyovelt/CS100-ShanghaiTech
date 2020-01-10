#include <iostream>
#include <string>
#include <vector>

class LookupTable
{
public:
    // constructor, start: start position; end: end position; increment: the increment "dx"
    // You should calculate the value in range [start, end], with increment "increment"
    LookupTable(double start, double end, double increment);
    // virtual destructor
    virtual ~LookupTable() = 0;
    // get the value f(x) of the given x
    virtual double getValue(double x) = 0;
};

class SquareLookupTable : public LookupTable
{
    // Your code here.
};

class SinLookupTable : public LookupTable
{
    // Your code here.
};

class LogLookupTable : public LookupTable
{
    // Your code here.
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    // Your code here.
    return 0;
}

