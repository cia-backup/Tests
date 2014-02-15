#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double f(double x)
{
    return exp(-x) - x;
}

double df(double x)
{
    return -exp(-x) - 1;
}

void NewtonRaphson(double (*f)(double), double (*df)(double), double root, int maxIterations)
{
    double answer;
    do
    {
        root = root - f(root)/df(root);
        answer = f(root);
    }while((answer >= pow(10, -10)) || (answer <= -pow(10, -10)));
    
    cout.precision(11);
    cout << "x = " << root << endl;
}

int main()
{
    double variable;
    double answer;
    int iterations;
    cin >> variable;
    
    NewtonRaphson(f, df, variable, 20);
    
    cout << "Exit...";
    getch();
    return 0;
}
