#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
    string sentence;
    
    getline(cin, sentence);
    
    cout << endl << sentence << endl << sentence.length() << endl;
    
    for(int x = 0; x <= sentence.length() - 1; x++)
    {
        if(sentence[x] == ' ')
        {
            for(int y = x + 1; y <= sentence.length() - 1; y++)
            {
                if(sentence[y] == ' ')
                {
                    //skip or do nothing when next character is a space, then go to next character
                }
                else
                {
                    sentence[x] = sentence[y];
                    sentence[y] = ' ';         //interchange the space and the character that's not a space
                    cout << sentence << endl;
                    break;
                }
            }
        }
        else
        {
        }
    }
    
    cout << endl << sentence << endl << sentence.length() << endl;
    
    system("PAUSE");
    return 0;
}
