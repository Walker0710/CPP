#include<iostream>

using namespace std;

int main() {

    int row;
    cin>>row;

    int col;
    cin>>col;

    char** arr = new char *[col];

    for(int i = 0; i < row; i++) {

        arr[i] = new char[col];
    }

    for(int i = 0; i < row; i++) {

        for(int j = 0; j < col; j++) {

            cin>>arr[j];
        }

        cout<<endl;
    }

    






}