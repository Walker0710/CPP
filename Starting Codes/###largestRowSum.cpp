#include<iostream>

using namespace std;

int LargestRowSum(int arr[][3], int row, int col) {

    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int row=0; row<3; row++) {

        int sum = 0;

        for(int col = 0; col<3; col++) {

            sum = sum + arr[row][col];
        }

        if(sum > maxi) {

            maxi = sum;
            rowIndex = row;
        }
    }

    cout << "the maximum sum is " << maxi << endl;
    return rowIndex;
}