#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> spirallyTraverse(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int total = n*m;
    int count = 0;

    int startRow = 0;
    int lastRow = n-1;

    int startCol = 0;
    int lastCol = m-1;

    vector<int> ans;

    while(total > count) {

        for(int i = 0; i<=lastCol; i++) {
            ans.push_back(mat[startRow][i]);
        }

        startRow++;

        for(int i = 0; i<=lastRow; i++) {
            ans.push_back(mat[i][lastCol]);
        }


    } 
}