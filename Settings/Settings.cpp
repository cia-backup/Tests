#include <iostream>
#include <fstream>

using namespace std;

void Pause()
{
    cout << "Press any key to exit...";
    cin.ignore();
    cin.get();
}

int main()
{
    fstream file;
    int x;
    int def;
    double maxIterations = 20;
    double significantFigures = 6;
    double rootFindingMethod = 0;
    double trace = 0;
    
    //for debugging
    cout << "Default <1 yes, 0 no>: ";
    cin >> def;
    
    file.open("settings.ini");
    file << def;
    file << def;
    
    file.close();
    
    file.open("settings.ini");
    file >> x;
    if(x == 0)
    {
        file >> x;
        maxIterations = x;
        
        file >> x;
        significantFigures = x;
        
        file >> x;
        rootFindingMethod = x;
        
        file >> x;
        trace = x;
    }
    else
    {
    }
    
    file.close();
    
    cout << maxIterations << endl;
    cout << significantFigures << endl;
    cout << rootFindingMethod << endl;
    cout << trace << endl;
    
    
    Pause();
    return 0;
}
