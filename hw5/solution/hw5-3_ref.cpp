#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <assert.h>
#define __EPS 0.01
#define __F_ANS_EQ(L, R) (fabs(L - R) < __EPS)

using namespace std;

class LookupTable
{
public:
    // constructor, start: start position; end: end position; increment: the increment "dx"
    // You should calculate the value in range [start, end], with increment "increment"
    LookupTable(double start, double end, double increment) {};
    // virtual destructor
    virtual ~LookupTable() = 0;
    // get the value f(x) of the given x
    virtual double getValue(double x) = 0;
};
LookupTable::~LookupTable(){};



class SquareLookupTable : public LookupTable
{
public:
    SquareLookupTable(double start, double end, double increment) : LookupTable(start, end, increment)
    {
        for (double i = start; i < end; i += increment)
        {
            m_x.push_back(i);
            m_data.push_back(sqrt(i));
        }

    }
    ~SquareLookupTable() {};
    double getValue(double x)
    {
        for (int i = 0; i < m_data.size() - 1; i++)
        {
            if (__F_ANS_EQ(m_x[i], x))
                return m_data[i];
            else if (x > m_x[i] && x < m_x[i+1])
                return ((x - m_x[i])*m_data[i+1] + (m_x[i+1] - x)*m_data[i]) / (m_x[i+1] - m_x[i]);
        }
        return 0;
    }
private:
    vector<double> m_data;
    vector<double> m_x;
    // Your code here.
};

class SinLookupTable : public LookupTable
{
public:
    SinLookupTable(double start, double end, double increment) : LookupTable(start, end, increment)
    {
        for (double i = start; i < end; i += increment)
        {
            m_x.push_back(i);
            m_data.push_back(sin(i));
        }

    }
    ~SinLookupTable() {};
    double getValue(double x)
    {
        for (int i = 0; i < m_data.size() - 1; i++)
        {
            if (__F_ANS_EQ(m_x[i], x))
                return m_data[i];
            else if (x > m_x[i] && x < m_x[i+1])
                return ((x - m_x[i])*m_data[i+1] + (m_x[i+1] - x)*m_data[i]) / (m_x[i+1] - m_x[i]);
        }
        return 0;
    }
private:
    vector<double> m_data;
    vector<double> m_x;
    // Your code here.
};

class LogLookupTable : public LookupTable
{
    public:
    LogLookupTable(double start, double end, double increment) : LookupTable(start, end, increment)
    {
        for (double i = start; i < end; i += increment)
        {
            m_x.push_back(i);
            m_data.push_back(log(i));
        }

    }
    ~LogLookupTable() {};
    double getValue(double x)
    {
        for (int i = 0; i < m_data.size() - 1; i++)
        {
            if (__F_ANS_EQ(m_x[i], x))
                return m_data[i];
            else if (x > m_x[i] && x < m_x[i+1])
                return ((x - m_x[i])*m_data[i+1] + (m_x[i+1] - x)*m_data[i]) / (m_x[i+1] - m_x[i]);
        }
        return 0;
    }
private:
    vector<double> m_data;
    vector<double> m_x;
    // Your code here.
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    int tcase;
    std::cin >> tcase;
    switch (tcase)
    {
        case 1:
        case 2:
        {
            LookupTable* l = new SquareLookupTable(1, 9, 0.5);
            assert(__F_ANS_EQ(l->getValue(3), 1.732));
            delete l;
            break;
        }
        case 3:
        {
            LookupTable* l = new SquareLookupTable(0, 8, 2);
            assert(__F_ANS_EQ(l->getValue(3), 1.707));
            delete l;
            break;
        }
        case 4:
        {
            LookupTable* l = new SquareLookupTable(0, 8, 2);
            assert(__F_ANS_EQ(l->getValue(2.5), 1.561));
            delete l;
            break;
        }
        case 5:
        {            
            LookupTable* l = new SinLookupTable(1, 10, 1);
            assert(__F_ANS_EQ(l->getValue(2), 0.909));
            delete l;
            break;            
        }
        case 6:
        {
            LookupTable* l = new SinLookupTable(1, 10, 0.01);
            assert(__F_ANS_EQ(l->getValue(2.2), 0.808));
            delete l;
            break;
        }
        case 7:
        {
            LookupTable* l = new SinLookupTable(1, 10, 1);
            assert(__F_ANS_EQ(l->getValue(2.2), 0.755));
            delete l;
            break;
        }
        case 8:
        {
            LookupTable* l = new LogLookupTable(1, 10, 1);
            assert(__F_ANS_EQ(l->getValue(2), 0.693));
            delete l;
            break;
        }
        case 9:
        {
            LookupTable* l = new LogLookupTable(1, 10, 1);
            assert(__F_ANS_EQ(l->getValue(2.5), 0.896));
            delete l;
            break;
        }
        case 10:
        {
            LookupTable* l = new LogLookupTable(1, 10, 1);
            assert(__F_ANS_EQ(l->getValue(2.2), 0.774));
            delete l;
            break;
        }
        default:
            break;
    }
    std::cout << tcase << std::endl;
    return 0;
}

