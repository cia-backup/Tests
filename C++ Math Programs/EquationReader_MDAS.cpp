#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>

using namespace std;

char OperationBetween(string number, int x)
{
    if(number[x + 1] == 42)
    {
        return '*';
    }
    else if(number[x + 1] == 43)
    {
        return '+';
    }
    else if(number[x + 1] == 45)
    {
        return '-';
    }
    else if(number[x + 1] == 47)
    {
        return '/';
    }
    else if(number[x + 1] == '^')
    {
        return '^';
    }
    else if(x == number.length() - 1)
    {
        return '_';
    }
    else
    {
        return '%';
    }
}

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

double ReadEquation(string number, int lowerBound, int upperBound, double variable)
{
    double answer = 0;
    double decimal; //only a placeholder
    double divider; //values of 10, 100, 1000, 10 000, etc. depending on place of decimal.
    double term[number.length()]; // holder to get integers and decimal
    double termInEquation[number.length()]; //0 for first term, 1 for 2nd, etc.
    double pi = 3.1415926535897932384626433832795;
    char operationBetween[number.length()]; 
    int checkIfDecimal = 0;
    int numberOfTerms = 0;
    int firstTermNegative = 0;
    int numberOfOpenP = 0;
    int numberOfCloseP = 0;
    int lowerBoundNew;
    int upperBoundNew;
    int function = 0;
    
    string inf = "1/0";
    
    for(int x = lowerBound; x <= upperBound; x++)
    {
        //if first term is negative
        if((x == lowerBound) && (number[x] == '-'))
        {
            firstTermNegative = 1;
            x++;
        }
        else
        {
        }
        
        for(int y = 48; y <= 57; y++)
        {
            if(number[x] == y)
            {
                term[x] = y - 48;
                number[x] = ' '; 
            }
            else
            {
            }
        }
        
        if((number[x + 1] >= 48) && (number[x + 1] <= 57) && (number[x] != '(')) // for integers with more than one digit
        {
            for(int y = 48; y <= 57; y++)
            {
                if(number[x + 1] == y)
                {
                    term[x + 1] = 10*term[x] + (y - 48);
                    number[x + 1] = ' ';
                    term[x] = 0;
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
            checkIfDecimal = 0;
        }
        else if((number[x] == 'p') && (number[x + 1] == 'i'))
        {
            term[x + 1] = pi;
            number[x] = ' ';
            number[x + 1] = ' ';
        }
        else if(number[x] == 'e')
        {
            term[x] = exp(1);
            number[x] = ' ';
        }
        else if(number[x] == 'x')
        {
            term[x] = variable;
            number[x] = ' ';
        }
        else
        {
        }
        
        if(number[x] == '(')
        {
            lowerBoundNew = x + 1; //after parenthesis is the new lowerbound
            numberOfOpenP++;
            
            if(x >= lowerBound + 3)
            {
                if((number[x - 3] == 'c') && (number[x - 2] == 'o') && (number[x - 1] == 's'))
                {
                    if(number[x - 4] == 'a')
                    {
                        function = 4;
                    }
                    else
                    {
                        function = 1;
                    }
                }
                else if((number[x - 3] == 's') && (number[x - 2] == 'i') && (number[x - 1] == 'n'))
                {
                    if(number[x - 4] == 'a')
                    {
                        function = 5;
                    }
                    else
                    {
                        function = 2;
                    }
                }
                else if((number[x - 3] == 't') && (number[x - 2] == 'a') && (number[x - 1] == 'n'))
                {
                    if(number[x - 4] == 'a')
                    {
                        function = 6;
                    }
                    else
                    {
                        function = 3;
                    }
                }
                else if((number[x - 3] == 'l') && (number[x - 2] == 'o') && (number[x - 1] == 'g'))
                {
                    function = 7;
                }
                else
                {
                }
            }
            else
            {
                function = 0;
            }
            
            for(x = lowerBoundNew; x <= upperBound; x++)
            {
                if(number[x] == ')')
                {
                    numberOfCloseP++;
                }
                else if(number[x] == '(')
                {
                    numberOfOpenP++;
                }
                else
                {
                }
                
                if(numberOfOpenP == numberOfCloseP)
                {
                    upperBoundNew = x - 1; //before parenthesis is the new upperbound
                    numberOfOpenP = 0;
                    numberOfCloseP = 0;
                    break; //no need for loop and to close loop   
                }
                else
                {
                }
            }
            
            termInEquation[numberOfTerms] = ReadEquation(number, lowerBoundNew, upperBoundNew, variable);
            
            if(function == 0)
            {
            }
            else if(function == 1)
            {   
                if((termInEquation[numberOfTerms] == pi/2) || (termInEquation[numberOfTerms] == -pi/2) || (termInEquation[numberOfTerms] == 3*(pi/2)) || (termInEquation[numberOfTerms] == -3*(pi/2)))
                {
                    termInEquation[numberOfTerms] = 0;
                }
                else
                {
                    termInEquation[numberOfTerms] = cos(termInEquation[numberOfTerms]);
                }
            }
            else if(function == 2)
            {
                if((termInEquation[numberOfTerms] == pi) || (termInEquation[numberOfTerms] == -pi) || (termInEquation[numberOfTerms] == 0))
                {
                    termInEquation[numberOfTerms] = 0;
                }
                else
                {
                    termInEquation[numberOfTerms] = sin(termInEquation[numberOfTerms]);
                }
            }
            else if(function == 3)
            {
                if((termInEquation[numberOfTerms] == pi) || (termInEquation[numberOfTerms] == -pi) || (termInEquation[numberOfTerms] == 0))
                {
                    termInEquation[numberOfTerms] = 0;
                }
                else if((termInEquation[numberOfTerms] == pi/2) || (termInEquation[numberOfTerms] == -pi/2) || (termInEquation[numberOfTerms] == 3*(pi/2)) || (termInEquation[numberOfTerms] == -3*(pi/2)))
                {
                    termInEquation[numberOfTerms] = ReadEquation(inf, 0, inf.length() - 1, variable);
                    
                    if((operationBetween[numberOfTerms - 1] == '/') && (numberOfTerms >= 1))
                    {
                        termInEquation[numberOfTerms - 1] = 1;
                        termInEquation[numberOfTerms] = 1;
                    }
                    else
                    {
                    }
                }
                else
                {
                    termInEquation[numberOfTerms] = tan(termInEquation[numberOfTerms]);
                }
            }
            else if(function == 4)
            {
                termInEquation[numberOfTerms] = acos(termInEquation[numberOfTerms]);
            }
            else if(function == 5)
            {
                termInEquation[numberOfTerms] = asin(termInEquation[numberOfTerms]);
            }
            else if(function == 6)
            {
                termInEquation[numberOfTerms] = atan(termInEquation[numberOfTerms]);
            }
            else if(function == 7)
            {
                termInEquation[numberOfTerms] = log10(termInEquation[numberOfTerms]);
            }
            else
            {
            }
            
            if(number[x + 1] == 'x')
            {
                operationBetween[numberOfTerms] = OperationBetween(number, x + 1);
                termInEquation[numberOfTerms] = termInEquation[numberOfTerms]*variable;
                x = x + 2;
                numberOfTerms++;
            }
            else if(number[x + 1] == 'e')
            {
                operationBetween[numberOfTerms] = OperationBetween(number, x + 1);
                termInEquation[numberOfTerms] = termInEquation[numberOfTerms]*exp(1);
                x = x + 2;
                numberOfTerms++;
            }
            else if((number[x + 1] == 'p') && (number[x + 2] == 'i'))
            {
                operationBetween[numberOfTerms] = OperationBetween(number, x + 2);
                termInEquation[numberOfTerms] = termInEquation[numberOfTerms]*pi;
                x = x + 3;
                numberOfTerms++;
            }
            else
            {
                operationBetween[numberOfTerms] = OperationBetween(number, x);
                x++;
                numberOfTerms++;
            }
        }
        else if((number[x + 1] == 42) || (number[x + 1] == 43) || (number[x + 1] == 45) || (number[x + 1] == 47) || 
                (number[x + 1] == '^') || 
                (number[x + 1] == 'x') || ((number[x + 1] == 'p') && (number[x + 2] == 'i')) || 
                (number[x + 1] == 'e') ||
                (x == upperBound))
        {
            termInEquation[numberOfTerms] = term[x];            //Find term
            
            if(number[x + 1] == 'x')
            {
                if(number[x + 2] == '^')
                {
                    operationBetween[numberOfTerms] = '*';
                    termInEquation[numberOfTerms + 1] = variable;
                    operationBetween[numberOfTerms + 1] = '^';
                    x = x + 2;
                    numberOfTerms = numberOfTerms + 2;
                }
                else
                {
                    operationBetween[numberOfTerms] = OperationBetween(number, x + 1);
                    termInEquation[numberOfTerms] = termInEquation[numberOfTerms]*variable;
                    x = x + 2;
                    numberOfTerms++;
                }
            }
            else if(number[x + 1] == 'e')
            {
                if(number[x + 2] == '^')
                {
                    operationBetween[numberOfTerms] = '*';
                    termInEquation[numberOfTerms + 1] = exp(1);
                    operationBetween[numberOfTerms + 1] = '^';
                    x = x + 2;
                    numberOfTerms = numberOfTerms + 2;
                }
                else
                {
                    operationBetween[numberOfTerms] = OperationBetween(number, x + 1);
                    termInEquation[numberOfTerms] = termInEquation[numberOfTerms]*exp(1);
                    x = x + 2;
                    numberOfTerms++;
                }
            }
            else if((number[x + 1] == 'p') && (number[x + 2] == 'i'))
            {
                operationBetween[numberOfTerms] = OperationBetween(number, x + 2);
                termInEquation[numberOfTerms] = termInEquation[numberOfTerms]*pi;
                x = x + 3;
                numberOfTerms++;
            }
            else
            {
                operationBetween[numberOfTerms] = OperationBetween(number, x); //Find operation between terms
                x++;
                numberOfTerms++;
            }
            
        }
        else
        {
        }
    }
    
    if((firstTermNegative == 1) && (operationBetween[0] != '^'))
    {
        termInEquation[0] = 0 - termInEquation[0];
    }
    else
    {
    }
    //find all negative
    for(int x = 0; x <= numberOfTerms - 1; x++)
    {
        if((operationBetween[x] == '-') && (operationBetween[x + 1] != '^'))
        {
            termInEquation[x + 1] = 0 - termInEquation[x + 1];
            operationBetween[x] = '+';
        }
        else
        {
        }
    }
    //find all exponents, multiplication/division
    for(int x = 0; x <= numberOfTerms - 1; x++)
    {
        if(operationBetween[x] == '^')
        {
            termInEquation[x + 1] = pow(termInEquation[x], termInEquation[x + 1]);
            //how to handle negative before the base of the exponential function
            if(((x >= 1) && (operationBetween[x - 1] == '-')) || ((firstTermNegative == 1) && (x == 0)))
            {
                termInEquation[x + 1] = 0 - termInEquation[x + 1];
            }
            else
            {
            }
            
            termInEquation[x] = 0;
            operationBetween[x] = '+';
        }
        else if((operationBetween[x + 1] == '^') && (operationBetween[x] == '*'))
        {
            termInEquation[x + 2] = termInEquation[x] * pow(termInEquation[x + 1], termInEquation[x + 2]);
            termInEquation[x] = 0;
            termInEquation[x + 1] = 0;
            operationBetween[x] = '+';
            operationBetween[x + 1] = '+';
        }
        else if((operationBetween[x + 1] == '^') && (operationBetween[x] == '/'))
        {
            termInEquation[x + 2] = termInEquation[x] / pow(termInEquation[x + 1], termInEquation[x + 2]);
            termInEquation[x] = 0;
            termInEquation[x + 1] = 0;
            operationBetween[x] = '+';
            operationBetween[x + 1] = '+';
        }
        else if(operationBetween[x] == '*')
        {
            termInEquation[x + 1] = termInEquation[x] * termInEquation[x + 1];
            termInEquation[x] = 0;
            operationBetween[x] = '+';
        }
        else if(operationBetween[x] == '/')
        {
            termInEquation[x + 1] = termInEquation[x] / termInEquation[x + 1];
            termInEquation[x] = 0;
            operationBetween[x] = '+';
        }
        else
        {
            //do nothing
        }
    }
    //for debugging process
    /*for(int x = 0; x <= numberOfTerms - 1; x++)
    {
        cout << termInEquation[x] << endl;
        cout << operationBetween[x] << endl; 
    }
    cout << number << endl;*/
    //sum of all terms
    for(int x = 0; x <= numberOfTerms - 1; x++)
    {
        answer = answer + termInEquation[x];
    }
    
    return answer; 
}

int main()
{
    string number;
    double variable;
    int unknown = 0;
    double answer;
    
    cout << "Trigonometric Functions (x is in radians, pi = 3.14159):\n\t cos(x)\n\t sin(x)\n\t tan(x)\n\tacos(x)\n\tasin(x)\n\tatan(x)\n";
    cout << "Exponential Functions (e = 2.7182818):\n\t exp(x)\n\t log(x)\n";
    
    cout << "\nInput Equation:\n\n\ty = ";
    
    getline(cin, number); //input one equation
    
    number = eraseSpaces(number);
    
    for(int x = 0; x <= number.length() - 1; x++)
    {
        if(number[x] == 'x')
        {
            unknown = 1;
            break;
        }
        else
        {
        }
    }
    
    if(unknown == 1)
    {
        cout << "x = ";
        cin >> variable;
    }
    else
    {
    }
    
    answer = ReadEquation(number, 0, number.length() - 1, variable);
    
    cout.precision(11);
    /*for(int x = 0; x <= numberOfTerms - 1; x++)
    {
        cout << termInEquation[x] << endl;
        cout << operationBetween[x] << endl; 
    }
    cout << number << endl;*/

    cout << "\ty = " << answer << endl;
    cout << endl;
    
    system("PAUSE");
    return 0;
}
