#include <iostream>
#include <cstdlib>
#include <string.h>
#include <sstream>

using namespace std;

int main()
{
    double number;
    
    cin >> number;
    
    std::ostringstream os;
    os << number;
    std::string str = os.str();
    
    cout << str << endl;
    
    system("PAUSE");
    return 0;
}
