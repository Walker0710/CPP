#include<iostream>
#include<vector>

using namespace std;

int projectionArea(vector<vector<int>>& grid) {

    int n = grid.size();
    int sum = 0;

    for(int i = 0; i<n; i++) {

        int maxCol = INT32_MIN;
        int maxRow = INT32_MIN;

        for(int j = 0; j<n; j++) {

            int yoCol = grid[i][j];
            int yoRow = grid[j][i];

            if(yoRow > maxRow) {

                maxRow = yoRow;
            }

            if(yoCol > maxCol) {

                maxCol = yoCol;
            }
        }

        sum = sum + maxCol + maxRow;
    }

    int count = 0; 

    for(int i = 0; i<n; i++) {

        for(int j = 0; j<n; j++) {

            if(grid[i][j] != 0) {

                count++;
            }
        }
    }

    int ans = sum + count;

    return ans;
}