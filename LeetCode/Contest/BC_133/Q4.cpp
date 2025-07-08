#include <bits/stdc++.h>

using namespace std;

// << ,

int dp[301][402];
int n;
map<int, int> m;
int mod = 1e9 + 7;

int solve(int i, int c) // i is current (inserting value or index) and c is current inversions till i-1th index.
{
    if (i == n)
    return 1;
    
    if (c > 400)
    return 0; // constrain

    if (dp[i][c] != -1)
    return dp[i][c];

    int sum = 0;
    
    for (int j = c; j <= c + i; j++) // j is inversion count till ith length
    {
        if (m.find(i) != m.end())
        {
            if (j != m[i])
            continue; // if current index is present in requiremnt so it should match the inversion count
        }

        sum = (sum % mod + solve(i + 1, j) % mod) % mod;
    }

    return dp[i][c] = sum;
}

int numberOfPermutations(int n1, vector<vector<int>> &r)
{
    n = n1;
    memset(dp, -1, sizeof(dp));
    
    for (auto i : r)
    m[i[0]] = i[1]; 

    if (m.find(0) != m.end() && m[0] != 0)
    return 0; 

    return solve(1, 0);
}