#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int row = matrix.size();
    int col = matrix[0].size();

    int r = 0;
    int c = col-1;

    while(r < row && c >= 0) {

        if(matrix[r][c] == target) {

            return true;
        }

        else if(matrix[r][c] < target) {

            r++;
        }

        else {

            c--;
        }
    }

    return false;
        
    }
