#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
    string sentence;
    
    getline(cin, sentence);
    
    for(int x = 0; x <= sentence.length() - 1; x++)
    {
        if(sentence[x] >= 48 && sentence[x] <= 57)
        {
            cout << sentence[x] << " is a number.\n";
        }
        else if((sentence[x] >= 65 && sentence[x] <= 90) || (sentence[x] >= 97 && sentence[x] <= 122))
        {
            cout << sentence[x] << " is a letter.\n";
        }
        else if(sentence[x] == ' ')
        {
            cout << sentence[x] << " is a space.\n";
        }
        else
        {
            cout << sentence[x] << " is a symbol.\n";
        }
    }
    
    system("PAUSE");
    return 0;
}
