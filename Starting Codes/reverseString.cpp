#include<iostream>

using namespace std;

void ReverseString(char string[], int n)  {

    int s = 0;
    int e = n-1;

    while(s<e) {

        swap(string[s],string[e]);
        s++;
        e--;

    }
}

void printString(char string[], int n) {

    for(int i = 0; i<n; i++) {

        cout<<" "<<string[i];
    }
}

int main() {

    char string[5] = {'a','b','c','d','e'};

    ReverseString(string,5);

    printString(string,5);

    return 0;

    
}
