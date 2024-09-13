#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool isMagic(vector<vector<int>>& grid, int r, int c) {

    vector<int> sumArr;
    unordered_set<int> digi;

    for(int i = r; i<r+3; i++) {

        int sum = 0;

        for(int j = c; j<c+3; j++) {

            if(grid[i][j] > 9 || grid[i][j] < 1) {

                return false;
            }

            digi.insert(grid[i][j]);
            sum = sum + grid[i][j];
        }

        sumArr.push_back(sum);
    }

    for(int i = c; i<c+3; i++) {

        int sum = 0;

        for(int j = r; j<r+3; j++) {

            sum = sum + grid[j][i];
        }

        sumArr.push_back(sum);
    }

    int sum2 = 0;
    sum2 =  grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
    sumArr.push_back(sum2);

    sum2 = grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2];
    sumArr.push_back(sum2);

    for(int i = 0; i<sumArr.size() - 1; i++) {

        if(sumArr[i] != sumArr[i+1]) {

            return false;
        }
    }

    int size = digi.size();

    if(size == 9) {

        return true;
    }

    return false;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {

    int row = grid.size();
    int col = grid[0].size();

    int count = 0;

    if(row < 3 || col < 3) {

        return count;
    }

    for(int i = 0; i<row - 2; i++) {

        for(int j = 0; j<col - 2; j++) {

            if(isMagic(grid, i, j)) {

                count++;
            }
        }
    }

    return count;
}