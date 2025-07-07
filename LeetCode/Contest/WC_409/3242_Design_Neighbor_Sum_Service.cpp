#include <bits/stdc++.h>

using namespace std;

// << ,

class NeighborSum {
public:
    vector<vector<int>> mat;
    int n = 0;

    NeighborSum(vector<vector<int>>& grid) {
        mat = grid;
        n = grid.size();
    }

    pair<int, int> search(int val) {
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j] == val) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
    
    int adjacentSum(int value) {
        pair<int, int> ind = search(value);
        
        int i = ind.first;
        int j = ind.second;

        int sum = 0;

        if(i-1 >= 0 && i-1 < n) {
            sum = sum + mat[i-1][j];
        }

        if(i+1 >= 0 && i+1 < n) {
            sum = sum + mat[i+1][j];
        }

        if(j-1 >= 0 && j-1 < n) {
            sum = sum + mat[i][j-1];
        }

        if(j+1 >= 0 && j+1 < n) {
            sum = sum + mat[i][j+1];
        }

        return sum;
    }
    
    int diagonalSum(int value) {
        pair<int, int> ind = search(value);
        
        int i = ind.first;
        int j = ind.second;

        int sum = 0;

        if(i-1 >= 0 && i-1 < n && j-1 >= 0 && j-1 < n) {
            sum = sum + mat[i-1][j-1];
        }

        if(i-1 >= 0 && i-1 < n && j+1 >= 0 && j+1 < n) {
            sum = sum + mat[i-1][j+1];
        }

        if(i+1 >= 0 && i+1 < n && j-1 >= 0 && j-1 < n) {
            sum = sum + mat[i+1][j-1];
        }

        if(i+1 >= 0 && i+1 < n && j+1 >= 0 && j+1 < n) {
            sum = sum + mat[i+1][j+1];
        }

        return sum;
    }
};