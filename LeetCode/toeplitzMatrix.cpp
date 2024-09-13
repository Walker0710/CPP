#include<iostream>
#include<vector>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {

    int row = matrix.size();
    int col = matrix[0].size();
    vector<pair<int, int>> strap;

    for(int i = 0; i < col; i++) {

        strap.push_back({0,i});
    }

    for(int i = 1; i < row; i++) {

        strap.push_back({i,0});
    }

    for(int i = 0; i<strap.size(); i++) {

        int r1 = strap[i].first;
        int c1 = strap[i].second;
        int r2 = strap[i+1].first;
        int c2 = strap[i+1].second;

        while(r1 >= 0 && r1<row && r2 >= 0 && r2<row && c2 >= 0 && c2<col && c1 >= 0 && c1 < col) {

            if(matrix[r1][c1] != matrix[r2][c2]) {

                return false;
            }

            r1++;
            c1++;
            r2++;
            c2++;
        }
    }

    return true;
}