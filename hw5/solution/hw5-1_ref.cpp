#include <iostream>
#include <algorithm>
#include <math.h>

#define __EPS 0.01
#define __F_ANS_EQ(L, R) fabs((L)-(R)) <= __EPS

using namespace std;

#define ERRORCODE -1
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
        std::cout << "ERROR: try to access virtual function in base class" << std::endl;
        return ERRORCODE;
    };
};

class MaximumAnalyser : public DataAnalyser
{
public:
    MaximumAnalyser()  {};
    ~MaximumAnalyser() {};
    float calculate(float* data, size_t size)
    {
        float maxval = std::numeric_limits<float>::min();
        for (size_t i = 0; i < size; ++i)
        {
            if (data[i] > maxval)
                maxval = data[i];
        }
        return maxval;
    }
};

class MinimumAnalyser : public DataAnalyser
{
public:
    MinimumAnalyser()  {};
    ~MinimumAnalyser() {};
    float calculate(float* data, size_t size)
    {
        float minval = std::numeric_limits<float>::max();
        for (size_t i = 0; i < size; ++i)
        {
            if (data[i] < minval)
                minval = data[i];
        }
        return minval;
    }
};

// AverageAnalyser
class AverageAnalyser : public DataAnalyser
{
public:
    AverageAnalyser() {};
    ~AverageAnalyser() {};
    float calculate(float* data, size_t size)
    {
        float sum = 0;
        for (size_t i = 0; i < size; ++i)
            sum += data[i];
        return sum / (float)size;
    }
};

class MedianAnalyser : public DataAnalyser
{
public:
    MedianAnalyser() {};
    ~MedianAnalyser() {};
    float calculate(float* data, size_t size)
    {
        std::sort(&data[0], &data[size]);
        if (size % 2 == 0)
            return (data[size/2] + data[size/2 - 1]) / 2.0f;
        else
            return data[size/2];
    }
};

class StdDevAnalyser : public DataAnalyser
{
public:
    StdDevAnalyser() {};
    ~StdDevAnalyser() {};
    float calculate(float* data, size_t size)
    {
        float sum = 0, avg;
        for (size_t i = 0; i < size; ++i)
            sum += data[i];
        avg = sum / (float)size;
        float s = 0;
        for (size_t i = 0; i < size; ++i)
            s += pow(data[i] - avg, 2);
        s = s / (float)size;
        return sqrt(s);
    }
};



int main()
{
    int tcase;
    std::cin >> tcase;
    switch (tcase)
    {
        case 1:
        {
            float arr[] = {0.3,-100,1,2,5,6,9,12,2};
            DataAnalyser* ma = new MinimumAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 9), -100.0f));  
            delete ma;
            break;
        }
        case 2:
        {
            float arr[] = {0.3,9,1,2,5,6,9,12,-2};
            DataAnalyser* ma = new MinimumAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 5), 0.3f));  
            delete ma;
            break;
        }
        case 3:
        {
            float arr[] = {0.3,-100,1,2,5,6,9,12,2};
            DataAnalyser* ma = new MaximumAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 9), 12.0f));  
            delete ma;
            break;
        }
        case 4:
        {
            float arr[] = {0.3,9,1,2,5,6,9,12,-2};
            DataAnalyser* ma = new MaximumAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 3), 9.0f));  
            delete ma;
            break;
        }
        case 5:
        {
            float arr[] = {1,5,4,3,2};
            DataAnalyser* ma = new MedianAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 5), 3.0f));  
            delete ma;
            break;
        }
        case 6:
        {
            float arr[] = {1,2,3,4};
            DataAnalyser* ma = new MedianAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 4), 2.5f));  
            delete ma;
            break;
        }
        case 7:
        {
            float arr[] = {1,3,6,7,8};
            DataAnalyser* ma = new AverageAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 5), 5.0f));  
            delete ma;
            break;
        }
        case 8:
        {
            float arr[] = {1,3,6,7,8};
            DataAnalyser* ma = new AverageAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 2), 2.0f));  
            delete ma;
            break;
        }
        case 9:
        {
            float arr[] = {1,3,6,7,8};
            DataAnalyser* ma = new StdDevAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 5), 2.607f));  
            delete ma;
            break;
        }
        case 10:
        {
            float arr[] = {5,5,5,5,5};
            DataAnalyser* ma = new StdDevAnalyser();  
            assert(__F_ANS_EQ(ma->calculate(arr, 5), 0.0f));  
            delete ma;
            break;
        }
    }
    std::cout << tcase << std::endl;
    return 0;
}