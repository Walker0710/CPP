#include<iostream>

using namespace std;

int printFibTerm(int n1, int n2, int term)
{
    if(term == 0)
    {
        return -1;
    }
    if(term == 1)   
    {
        return n1;
    }
    printFibTerm(n2, n1 + n2, term - 1);
}

int main()
{
    int terms;
    cin >> terms;
    // printFibSeries(0, 1, terms);
    cout << printFibTerm(0, 1, terms) << endl;
}
