#include<iostream>
#include<vector>

using namespace std;

void Reverse(char string[], int n) {

    int s = 0;
    int e = n-1;

    while(e>s) {

    swap(string[s],string[e]);

    s++;
    e--;
}

}

int main() {

    char string[6] = {'a','n','k','u','s','h'};

    Reverse(string,6);

    for(int i = 0; i<6; i++) {

        cout<<string[i]<<" ";
    }




}