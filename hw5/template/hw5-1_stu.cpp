#include <iostream>
#include <vector>

const int ERRORCODE = -1;

class DataAnalyser
{
public:
    DataAnalyser() {};
    virtual ~DataAnalyser() {};
    /** 
     * virtual function "calculate"
     * @param data: the data array need to be calculated
     * @param size: the length of the data
     * @return: the calculated result
     */
    virtual float calculate(float* data, size_t size)
    {
        std::cout << "ERROR: Try to access virtual function which is in base class" << std::endl;
        return ERRORCODE;
    };
};


// MaximumAnalyser
class MaximumAnalyser : public DataAnalyser
{
    // Your code here.
};

// MinimumAnalyser
class MinimumAnalyser : public DataAnalyser
{
    // Your code here.
};

// AverageAnalyser
class AverageAnalyser : public DataAnalyser
{
    // Your code here.
};

// MedianAnalyser
class MedianAnalyser : public DataAnalyser
{
    // Your code here.
};

// StdDevAnalyser
class StdDevAnalyser : public DataAnalyser
{
    // Your code here
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    /* Your can write your own main for testing */
    return 0;
}