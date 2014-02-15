#include <iostream>
#include <cstdlib>

using namespace std;

int Factorial(int num)
{
    for(int x = num - 1; x >= 1; x--)
    {
        num = num*x;
    }
    
    return num;
}

int main()
{
    int variable;
    
    cin >> variable;
    
    variable = Factorial(variable);
    
    cout << variable << endl;
    
    system("PAUSE");
    return 0;
}
