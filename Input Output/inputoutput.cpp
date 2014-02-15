#include <iostream>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <fstream>

using namespace std;

int main()
{
    char e;
    fstream file;
    
    //create file
    ofstream createFile("example.ini");
    createFile.close();
    
    //write file
    file.open("example.ini");
    file << "1";
    file.close();
    
    //read file
    file.open("example.ini");
    file >> e;
    
    file.close();

    cout << e << endl;

    cout << "Press any key to exit...";
    getch();
    return 0;
}
