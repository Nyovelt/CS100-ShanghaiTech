#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

vector<string> split(const string& str, const string& delim) 
{   
 	vector<string> res;  
	if("" == str) return res;  
	char * strs = new char[str.length() + 1] ; 
	strcpy(strs, str.c_str());   
 
	char * d = new char[delim.length() + 1];  
	strcpy(d, delim.c_str());  
 
	char *p = strtok(strs, d);  
	while(p) 
    {  
		string s = p;  
		res.push_back(s);
		p = strtok(NULL, d);  
	}  
	return res; 
}

void putchars(char c, int cnt)
{
    while (cnt--)
        putchar(c);
}

bool infoless (const vector<string> & lhs, const vector<string> & rhs, int i)
{
    return lhs[i] < rhs[i];
}

class ReportParser
{
public:
    ReportParser(int numStudents, int numProblems);
    ~ReportParser();
    void readReport();
    void writeStructuredReport(int sortOption);
private:
    vector<string>*  m_data;
    vector<int>*     maxlength;
    size_t m_numStudents, m_numProblems;
};

ReportParser::ReportParser(int numStudents, int numProblems) 
{
    m_data =  new vector<string>(numStudents);
    maxlength = new vector<int>(numProblems);
    m_numProblems = numProblems;
    m_numStudents = numStudents;
};

ReportParser::~ReportParser() 
{
    delete m_data;
    delete maxlength;
};


void ReportParser::readReport()
{
    int cnt = 0;
    string str;
    while (cnt < m_numStudents)
    {
        getline(cin, str);
        m_data->at(cnt) = str;
        cnt++;
    }
}

void ReportParser::writeStructuredReport(int sortOption)
{
    vector< vector<string> > res;
    int total = 0;
    for (auto str : (*m_data))
    {
        vector<string> tmp = split(str, " ");
        assert(tmp.size() == m_numProblems);
        for (int i = 0; i < tmp.size(); i++)
        {  
            string substr = tmp[i];
            if (substr.size() > (*maxlength)[i])
                (*maxlength)[i] = substr.size();
        }
        res.push_back(tmp);
    }
    sort(res.begin(), res.end(), bind(infoless, placeholders::_1, placeholders::_2, sortOption));

    for (auto maxi : *maxlength)
        total += (maxi + 3);
    total--;

    putchar('/');
    putchars('-', total);
    cout << "\\\n";

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << "| " << res[i][j];
            putchars(' ', maxlength->at(j) - res[i][j].size() + 1);
        }   
        cout << "|\n";
        if (i != res.size() - 1)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                putchar('|');
                putchars('-', maxlength->at(j)+ 2);

            }
            putchar('|');
            putchar('\n');
        };
    }
    putchar('\\');
    putchars('-', total);
    cout << "/\n";
}


int main()
{
    int m, n, sortOption;
    cin >> m >> n >> sortOption;
    getchar();
    ReportParser a(n, m);
    a.readReport();
    a.writeStructuredReport(sortOption);
    return 0;
}

