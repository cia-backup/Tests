#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h> //for trigonometric, exponential, logarithmic, etc. functions

using namespace std;

string EraseSpaces(string example)
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

int PreviousOperation(string str, int a)
{
    if(str[a] == 42)
    {
        return 42;
    }
    else if(str[a] == 43)
    {
        return 43;
    }
    else if(str[a] == 45)
    {
        return 45;
    }
    else if(str[a] == 47)
    {
        return 47;
    } 
    else
    {
    }   
}

double ReadEquation(string number, int lowerBound, int upperBound)
{
    double decimal; //only a placeholder
    double divider; //values of 10, 100, 1000, 10 000, etc. depending on place of decimal.
    int checkIfDecimal = 0;
    int position = 0; //including decimal point (for positioning)
    int numberOfTerms = 0;
    int previousOperation = 0; //including decimal point
    int numberOfGroups = 0;
    double term[number.length()]; // holder to get integers and decimal AND limits the array to its maximum value
    double termInEquation[2]; //0 for first term, 1 for 2nd, etc.
    
    int lowerBoundNew, upperBoundNew; // for groups
    
    for(int x = lowerBound; x <= upperBound; x++)
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
        else
        {
        }
        
        if((number[x + 1] == 42) || (number[x + 1] == 43) || (number[x + 1] == 45) || (number[x + 1] == 47) || (x == upperBound))
        {
            termInEquation[numberOfTerms] = term[position - 1];
            x++;
            position++;
            numberOfTerms++;
            
            if(numberOfTerms == 1)
            {
                previousOperation = PreviousOperation(number, x);
            }
            else if((numberOfTerms == 2) && (previousOperation == 43))
            {
                termInEquation[0] = termInEquation[0] + termInEquation[1];
                numberOfTerms = 1;
                
                previousOperation = PreviousOperation(number, x);
            }
            else if((numberOfTerms == 2) && (previousOperation == 42))
            {
                termInEquation[0] = termInEquation[0] * termInEquation[1];
                numberOfTerms = 1;
                
                previousOperation = PreviousOperation(number, x);
            }
            else if((numberOfTerms == 2) && (previousOperation == 45))
            {
                termInEquation[0] = termInEquation[0] - termInEquation[1];
                numberOfTerms = 1;
                
                previousOperation = PreviousOperation(number, x);
            }
            else if((numberOfTerms == 2) && (previousOperation == 47))
            {
                termInEquation[0] = termInEquation[0] / termInEquation[1];
                numberOfTerms = 1;
                
                previousOperation = PreviousOperation(number, x);
            }
        }
        else
        {
        }    
    }
    
    return termInEquation[0];
}

int main()
{
    string number;
    double answer;
    int lowerBound;
    int upperBound;
    
    cout << "\nInput Equation:\n\n\ty = ";
    getline(cin, number); //input one number
    
    number = EraseSpaces(number);
    
    double termInEquation[number.length()]; //0 for first term, 1 for 2nd, etc.
    
    lowerBound = 0;
    upperBound = number.length() - 1;
    
    answer = ReadEquation(number, lowerBound, upperBound);
    
    cout.precision(11);
    
    cout << "\t  = " << fixed << answer << endl;
    //cout << position << endl;
    
    cout << endl;
    
    system("PAUSE");
    return 0;
}
