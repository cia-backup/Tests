#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
    string sentence;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    cout << endl << sentence << endl << "The length of the sentence is (including spaces): " << sentence.length() << endl;
    system("PAUSE");
    return 0;
}
