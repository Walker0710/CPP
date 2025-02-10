#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int i, int j, int row, int col, vector<vector<char>> &mat, int index, string target, vector<vector<int>> &visi) {
    if(index >= target.length()) {
        return 1;
    }

    visi[i][j] = 1; 

    int yoo = 0;

    if(i-1 >= 0 && visi[i-1][j] == 0 && mat[i-1][j] == target[index]) {
        yoo += solve(i-1, j, row, col, mat, index + 1, target, visi);
    }

    if(j+1 < col && visi[i][j+1] == 0 && mat[i][j+1] == target[index]) {
        yoo += solve(i, j+1, row, col, mat, index + 1, target, visi);
    }

    if(i+1 < row && visi[i+1][j] == 0 && mat[i+1][j] == target[index]) {
        yoo += solve(i+1, j, row, col, mat, index + 1, target, visi);
    }

    if(j-1 >= 0 && visi[i][j-1] == 0 && mat[i][j-1] == target[index]) {
        yoo += solve(i, j-1, row, col, mat, index + 1, target, visi);
    }

    visi[i][j] = 0;

    return yoo;
}

int findOccurrence(vector<vector<char>> &mat, string target) {
    int row = mat.size();
    int col = mat[0].size();
    int ans = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(target[0] == mat[i][j]) {
                vector<vector<int>> visi(row, vector<int>(col, 0)); 
                ans += solve(i, j, row, col, mat, 1, target, visi);
            }
        }
    }

    return ans;
}
