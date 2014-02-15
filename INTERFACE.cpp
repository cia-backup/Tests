#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void Pause()
{
    cout << "Press enter to exit...";
    cin.ignore();
}

void InputEquation()
{
    cout << "This is case 1" << endl;
}

void PredefinedFunctions()
{
    cout << "This is case 2" << endl;
}

void Settings()
{
    cout << "This is case 3" << endl;
}

void Instructions()
{
    cout << "This is case 4" << endl;
}

char Introduction()
{
    string input;
    bool valid = false;
    cout << "[write intro here]" << endl << endl;
    
    cout << "\t1. Input Equation" << endl;
    cout << "\t2. Predefined Functions" << endl;
    cout << "\t3. Settings" << endl;
    cout << "\t4. Help" << endl;
    cout << "\t5. Exit" << endl;
    
    
    do
    {
        getline(cin, input);
        
        if( (input.length() == 1) && (input[0] >= 49) && (input[0] <= 53) )
        {
            valid = true;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }   
    }while(!valid);
    
    return input[0];
}

int main()
{
    char input;
    do
    {
        input = Introduction();
        switch(input)
        {
            case '1':
                InputEquation();
                break;
            case '2':
                PredefinedFunctions();
                break;
            case '3':
                Settings();
                break;
            case '4':
                Instructions();
            case '5':
                break;
        }
    }while(input != '5');
    
    Pause();
    return 0;
}
