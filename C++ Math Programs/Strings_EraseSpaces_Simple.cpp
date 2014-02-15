#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

string eraseSpaces(string example)
{
    for(int x = 0; x <= example.length() - 1; x++)
    {
        if(example[x] == ' ')
        {
            example.erase(x, 1);
            x = x - 1;
        }
        else
        {
            //do nothing
        }
    }
    return example;
}

int main()
{
    string sentence;;
    
    getline(cin, sentence);
    
    cout << endl << sentence << endl << sentence.length() << endl;

    sentence = eraseSpaces(sentence);
    
    cout << endl << sentence << endl << sentence.length() << endl;
    
    cout << endl;
    
    system("PAUSE");
    return 0;
}
