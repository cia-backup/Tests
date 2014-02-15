#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
    string number;
    double termInEquation[100]; //0 for first term, 1 for 2nd, etc.
    double decimal; //only a placeholder
    double divider; //values of 10, 100, 1000, 10 000, etc. depending on place of decimal.
    int checkIfDecimal = 0;
    int position = 0; //including decimal point (for positioning)
    
    getline(cin, number); //input one number
    
    double term[number.length()]; // holder to get integers and decimal AND limits the array to its maximum value
    
    for(int x = 0; x <= number.length() - 1; x++)
    {
        for(int y = 48; y <= 57; y++)
        {
            if(number[x] == y)
            {
                term[x] = y - 48;
                number[x] = ' ';
                position++;
            }
            else
            {
            }
        }
        
        if((number[x + 1] >= 48) && (number[x + 1] <= 57)) // for integers with more than one digit
        {
            for(int y = 48; y <= 57; y++)
            {
                if(number[x + 1] == y)
                {
                    term[x + 1] = 10*term[x] + (y - 48);
                    number[x + 1] = ' ';
                    term[x] = 0;
                    position++;
                }
                else
                {
                }
            }
            checkIfDecimal = 0;
        }
        else if(number[x + 1] == 46) //for decimals
        {
            if(checkIfDecimal == 1)
            {
                divider = divider * 10;
            }
            else
            {
                divider = 10;
            }
            
            for(int y = 48; y <= 57; y++)
            {
                if(number[x + 2] == y)
                {
                    decimal = (y - 48)/divider;
                    term[x + 1] = term[x] + decimal;
                    number[x + 1] = ' ';
                    number[x + 2] = '.';
                    term[x] = 0;
                    position++;
                }
                else
                {
                }
            }
            checkIfDecimal = 1;
        }
        else if(number[x] == '.')
        {
            term[x] = term[x - 1];
            term[x - 1] = 0;
            number[x] = ' ';
            position++;
            checkIfDecimal = 0;
        }
        
        if(x == number.length() - 1)
        {
            termInEquation[0] = term[position - 1];
        }
        else
        {
        }    
    }
    
    
    cout.precision(11);
    
    cout << termInEquation[0] << endl;
    cout << position << endl;
    cout << number;
    
    cout << endl;
    
    system("PAUSE");
    return 0;
}
