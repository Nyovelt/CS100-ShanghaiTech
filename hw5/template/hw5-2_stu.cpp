#include <iostream>
#include <string>
#include <vector>


class ReportParser
{
public:
    ReportParser(int numStudents, int numInfos);
    ~ReportParser();
    void readReport();
    void writeStructuredReport(int sortOption);
    // Add your own functions and variables here
private:
    // Add your own functions and variables here
};

ReportParser::ReportParser(int numStudents, int numInfos) 
{
    // Your code here
} 

ReportParser::~ReportParser() 
{
    // Your code here
}


void ReportParser::readReport()
{
    // Your code here
}

void ReportParser::writeStructuredReport(int sortOption)
{
    // Your code here
}

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    int m, n, sortOption;
    std::cin >> m >> n >> sortOption;
    getchar();
    ReportParser p(m, n);
    p.readReport();
    p.writeStructuredReport(sortOption);
    return 0;
}

