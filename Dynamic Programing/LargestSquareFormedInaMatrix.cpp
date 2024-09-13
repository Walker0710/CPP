#include<iostream>
#include<vector>

using namespace std;

//only rec
int solve(vector<vector<int>> &mat, int i, int j, int &maxi) {

    if(i >= mat.size() || j >= mat[0].size())
    return 0;

    int right = solve(mat, i, j+1, maxi);
    int down = solve(mat, i+1, j, maxi);
    int diagonal = solve(mat, i+1, j+1, maxi);

    if(mat[i][j] == 1) {

        int ans = 1 + min(right, min(down, diagonal));
        maxi = max(maxi, ans);
        return maxi;
    }

    else {

        return 0;
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat) {

    int maxi = 0;
    return solve(mat, 0, 0, maxi);
}

//rec + memo
int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp) {

    if(i >= mat.size() || j >= mat[0].size())
    return 0;

    if(dp[i][j] != -1)
    return dp[i][j];

    int right = solveMem(mat, i, j+1, maxi, dp);
    int down = solveMem(mat, i+1, j, maxi, dp);
    int diagonal = solveMem(mat, i+1, j+1, maxi, dp);

    if(mat[i][j] == 1) {

        dp[i][j] = 1 + min(right, min(down, diagonal));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }

    else {

        return dp[i][j] = 0;
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat) {

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = 0;
    solveMem(mat, 0, 0, maxi, dp);
    return maxi;
}

//Tabulation
int solveTab(vector<vector<int>> &mat, int &maxi) {

    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for(int i = row - 1; i >= 0; i--) {

        for(int j = col - 1; j >= 0; j--) {

            int right = dp[i][j+1];
            int down = dp[i+1][j];
            int diagonal = dp[i+1][j+1];

            if(mat[i][j] == 1) {

                dp[i][j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, dp[i][j]); 
            }

            else {

                dp[i][j] = 0;
            }
        }
    }

    return 0; //kuch bhi return kar skte h 
}

int maxSquare(int n, int m, vector<vector<int>> mat) {

    int maxi = 0;
    solveTab(mat, maxi);
    return maxi;
}

//space optimization
int solveOpti(vector<vector<int>> &mat, int &maxi) {

    int row = mat.size();
    int col = mat[0].size();

    vector<int> curr(col + 1, 0);
    vector<int> next(col + 1, 0);

    for(int i = row - 1; i >= 0; i--) {

        for(int j = col - 1; j >= 0; j--) {

            int right = curr[j+1];
            int down = next[j];
            int diagonal = curr[j+1];

            if(mat[i][j] == 1) {

                curr[j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, curr[j]); 
            }

            else {

                curr[j] = 0;
            }
        }

        next = curr;
    }

    return 0; //kuch bhi return kar skte h 
}

int maxSquare(int n, int m, vector<vector<int>> mat) {

    int maxi = 0;
    solveOpti(mat, maxi);
    return maxi;
}

//HW isko O(1) space complex mee sovlve kar


