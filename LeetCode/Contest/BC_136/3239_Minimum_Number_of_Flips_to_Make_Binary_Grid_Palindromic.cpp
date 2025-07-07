#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();

    int ans = 0;

    for(int i = 0; i<n; i++) {
        vector<int> row = grid[i];

        int p = 0;
        int q = m-1;

        while (p < q) 
        {
            if(row[p] != row[q]) {
                ans++;
            }

            p++;
            q--;
        }
    }

    return ans;
}

int minFlips(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> trans(m, vector<int> (n, -1));

    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {

            trans[i][j] = grid[j][i];
        }
    }

    return min(solve(trans), solve(grid));
}