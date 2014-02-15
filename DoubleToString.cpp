#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string DoubleToString(double number)
{
    string str;
    fstream file;
    
    ofstream createFile("rootFinding.txt");
    createFile.close();
    
    file.open("rootFinding.txt");
    file.precision(49);
    file << number;
    file.close();
    
    file. open("rootFinding.txt");
    file >> str;
    file.close();
    
    remove("rootFinding.txt");
    
    return str;
}

int SignificantFigures(string str1, string str2)
{
    int significantFigures = 0;
    for(int x = 0; x <= str1.length() - 1; x++)
    {
        if(str1[x] == str2[x])
        {
            if((x == 0) && (str1[x] == '0'))
            {
                //do not add significantFigures
            }
            else if((x == 0) && (str1[x] == '-'))
            {
                //do not add significantFigures
                if(str1[x + 1] == '0')
                {
                    x++;
                }
            }
            else if(str1[x] == '.')
            {
                //do not add significantFigures
            }
            else
            {
                significantFigures++;
            }
        }
        else if(str1[x] != str2[x])
        {
            return significantFigures;
        }
        else
        {
        }
    }
    
    return significantFigures;
}

int main()
{
    double number1;
    double number2;
    string str1, str2;
    
    cin >> number1;
    cin >> number2;
    
    str1 = DoubleToString(number1);
    str2 = DoubleToString(number2);
    
    cout << str1 << endl;
    cout << str2 << endl;
    
    cout << SignificantFigures(str1, str2) << endl;
    
    system("PAUSE");
    return 0;
}
