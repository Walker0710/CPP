#include<iostream>

using namespace std;

int main() {

    int row;
    cin>>row;

    for(int i = 0; i<row; i++) {

        int col;
        cin>>col;

        int* arr = new int [col];

        for(int i = 0; i<col; i++) {

            cin>> arr[i];
        }

        for(int i = 0; i<col; i++) {

            cout << arr[i];
        }

        cout<<endl;
    }


}