#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream createFile("example.txt");
    createFile.close();
    
    string str = "10.0+5.5";
    double number1, number2;
    
    fstream file;
    file.open("example.txt");
    file << str;
    file.close();
    
    file.open("example.txt");
    file >> number1;
    file >> number2;
    file.close();
    
    cout << number1 << endl;
    cout << number2 << endl;
    
    //remove("example.txt");
    system("PAUSE");
    return 0;
}
