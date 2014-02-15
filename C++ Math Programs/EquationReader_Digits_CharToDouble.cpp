#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
    char character[100];
    double digit[100];
    
    cin >> character[0];
    
    digit[0] = static_cast<int>(character);
    
    cout << digit[0] << endl;
    
    system("PAUSE");
    return 0;
}
