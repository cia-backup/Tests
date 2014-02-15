#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int asciiDec;
    string asciiChar;
    
    cin >> asciiChar;
    
    asciiDec = asciiChar[0];
    /*
    numbers 65 - 90   characters A-Z
    numbers 97 - 122  characters a-z
    numbers 48 - 57   characters 0-9
    42 = *
    43 = +
    45 = -
    46 = .
    47 = /
    */

    cout << asciiDec << endl;
    
    system("PAUSE");
    return 0;
}
