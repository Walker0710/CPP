#include<iostream> 

using namespace std;

int main() {

    int row;
    cin>>row;

    int **arr = new int[row];

    for(int i = 0; i<row; i++) {

        int col;
        cin>>col;

        arr[i] = new int[col];

        for(int j = 0; j<col; j++) {

            cin>> arr[row][col];
        }

        cout<<endl;

        for(int j = 0; j<col; j++) {

            cout<< arr[row][col]<<" ";
        }
    }


}