#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Pause()
{
    cout << "Press any key to continue...";
    cin.get();
}

void GetTerms(vector<double>& term, string equation, int lowerbound, int upperbound)
{
    fstream file;
    double holder;
    
    ofstream createFile("equation.txt");
    createFile << equation;
    createFile.close();
    
    file.open("equation.txt");
    
    while(file >> holder)
    {
        term.push_back(holder);
    }
    
    file.close();
    remove("equation.txt");
}

int main()
{
    string equation;
    double answer = 0;
    vector<double> term;
    
    getline(cin, equation);
    
    //Get terms after getting operation between terms
    GetTerms(term, equation, 0, equation.length() - 1);
    
    for(int x = 0; x <= term.size() - 1; x++)
    {
        cout << "Term[" << x << "] = " << term.at(x) << endl;
    }
    
    for(int x = 0; x <= term.size() - 1; x++)
    {
        answer += term.at(x);
    }
    
    cout << "\nAnswer = " << answer << endl;
    
    Pause();
    return 0;
}
