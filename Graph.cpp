#include <iostream>
#include <cmath>

using namespace std;

void Pause()
{
    cout << "Press any key to exit...";
    cin.get();
}

double f(double x)
{
    return sin(x);
}

void Graph(double (*f)(double), double a, double b, int n)
{
    double step;
    double intervals = 0;
    step = (b - a)/(n - 1);
    
    cout << "x\t\ty" << endl;
    for(double x = a; x <= b; x += step)
    {
        cout << fixed;
        cout << x << "\t" << f(x) << endl;
        intervals++;
    }
    
    if(intervals == n - 1)
    {
        cout << fixed;
        cout << b << "\t" << f(b) << endl;
    }
    else
    {
    }
}
int main()
{
    double lowerbound;
    double upperbound;
    int intervals;
    cin >> lowerbound;
    cin >> upperbound;
    cin >> intervals;
    cin.ignore();
    
    Graph(f, lowerbound, upperbound, intervals);
    
    Pause();
    return 0;
}
