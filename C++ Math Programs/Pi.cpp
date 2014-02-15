#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
    double pi = 0;
    double x = 0;
    double term[100000];
    
    for(int y = 0; y <= 99999; y++)
    {
        term[y] = (4/(2*(x + 1) - 1))*pow(-1, x + 2);
        x++;
    }
    
    for(int x = 0; x <= 99999; x++)
    {
        pi = pi + term[x];
    }
    
    cout.precision(21);
    cout << fixed << pi << endl;
    
    system("PAUSE");
    return 0;
}
