#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>

using namespace std;

string Derivative(string term, string derivative)
{
    int withX = 0;
    
    for(int x = 0; x <= term.length() - 1; x++)
    {
        if(term[x] == 'x')
        {
            withX = 1;
        }
        else if((withX == 0) && (x == term.length() - 1))
        {
            return "0";
        }
        else
        {
        }
    }
    
    return derivative;
}

int main()
{
    string term, derivative;
    
    getline(cin, term);
    
    derivative = Derivative(term, derivative);
    
    cout << derivative << endl;
    
    system("PAUSE");
    return 0;
}
