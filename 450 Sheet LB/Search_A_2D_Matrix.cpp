#include <bits/stdc++.h>

using namespace std;

// << ,

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int s = 0;
    int e = n*m - 1;

    while(s <= e) {
        int mid = (e+s)/2;

        int row = mid/m;
        int col = mid%m;

        if(matrix[row][col] == target) {
           return true; 
        }

        else if(matrix[row][col] > target) {
            s = mid + 1;
        } 

        else {
            e = mid - 1;
        }
    }

    return false;
}