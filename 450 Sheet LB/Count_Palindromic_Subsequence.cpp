#include <bits/stdc++.h>

using namespace std;

// << ,

int countPSRecursive(string &s, int i, int j, vector<vector<int>> &dp) {
    if (i > j) return 0;  
    if (i == j) return 1; 

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if (s[i] == s[j]) {
        dp[i][j] = countPSRecursive(s, i + 1, j, dp) + countPSRecursive(s, i, j - 1, dp) + 1;
    }

    else {
        dp[i][j] = countPSRecursive(s, i + 1, j, dp) + countPSRecursive(s, i, j - 1, dp) - countPSRecursive(s, i + 1, j - 1, dp);
    }

    return dp[i][j];
}

int countPS(string &s) {
    vector<vector<int>> dp(s.length()+1, vector<int> (s.length()+1, -1));
    return countPSRecursive(s, 0, s.length() - 1, dp);
}

int countPS(string &s) {
    
    int n = s.length();
    vector<vector<int>> dp(s.length()+1, vector<int> (s.length()+1, 0));

    for(int i = 0; i<s.length(); i++) {
        dp[i][i] = 1;
    }

    for(int i = n-1; i>=0; i++) {
        for(int j = 0; j<n; j++) {

            if(s[i] == s[j]) {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            }

            else {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
    }

    return dp[0][n-1];
}

// correct way
int countPS(string &s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }

    return dp[0][n - 1];
}
