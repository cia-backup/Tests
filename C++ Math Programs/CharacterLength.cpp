#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
    char A[1000];
    int length = 0;
    
    cin >> A;
    
    cout << strlen(A) << " characters" << endl;    
    
    for(int x = 0; x <= strlen(A) - 1; x++)
    {
        if(A[x] >= 48 && A[x] <= 57)
        {
            cout << A[x] << " is a number.\n";
        }
        else if((A[x] >= 65 && A[x] <= 90) || (A[x] >= 97 && A[x] <= 122))
        {
            cout << A[x] << " is a letter.\n";
        }
        else
        {
            cout << A[x] << " is a symbol.\n";
        }
    }
    
    system("PAUSE");
    return 0;
}
