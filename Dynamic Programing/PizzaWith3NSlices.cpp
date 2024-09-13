#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

//only rec
int solve(vector<int>& slices, int index, int n) {

    if(index >= slices.size() || n == 0)
    return 0;

    int include = slices[index] + solve(slices, index + 2, n-1);
    int exclude = 0 + solve(slices, index + 1, n);

    return max(include, exclude);
}

int maxSizeSlices(vector<int>& slices) {

    int k = slices.size();

    vector<int> first, second;

    for(int i = 0; i<k; i++) {

        if(i != k-1)
        first.push_back(slices[i]);

        if(i != 0)
        second.push_back(slices[i]);
    }

    return max(solve(first, 0, k/3), solve(second, 0, k/3));
}

//rec + mem
int solveMem(vector<int>& slices, int index, int n, vector<vector<int>> &dp) {

    if(index >= slices.size() || n == 0)
    return 0;

    if(dp[index][n] != -1)
    dp[index][n];

    int include = slices[index] + solveMem(slices, index + 2, n-1, dp);
    int exclude = 0 + solveMem(slices, index + 1, n, dp);

    dp[index][n] = max(include, exclude);
    return dp[index][n];
}

int maxSizeSlices(vector<int>& slices) {

    int k = slices.size();

    vector<vector<int>> dp1(k+1, vector<int>(k/3 + 1, -1));
    vector<vector<int>> dp2(k+1, vector<int>(k/3 + 1, -1));
    vector<int> first, second;

    for(int i = 0; i<k; i++) {

        if(i != k-1)
        first.push_back(slices[i]);

        if(i != 0)
        second.push_back(slices[i]);
    }

    return max(solveMem(first, 0, k/3, dp1), solveMem(second, 0, k/3, dp2));
}

//babbar's approch
int solveMem1(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>> &dp) {

    if(index > endIndex || n == 0)
    return 0;

    if(dp[index][n] != -1)
    dp[index][n];

    int include = slices[index] + solveMem1(index + 2, endIndex, slices, n-1, dp);
    int exclude = 0 + solveMem1(index + 1, endIndex, slices, n, dp);

    dp[index][n] = max(include, exclude);
    return dp[index][n];
}

int maxSizeSlices(vector<int>& slices) {

    int k = slices.size();

    vector<vector<int>> dp1(k, vector<int>(k, -1));
    int case1 = solveMem1(0, k-2, slices, k/3, dp1);

    vector<vector<int>> dp2(k, vector<int>(k, -1));
    int case2 = solveMem1(1, k-1, slices, k/3, dp2);

    return max(case1, case2);
}

//Tabluation
int solveTab(vector<int>& slices, int k) {

    vector<vector<int>> dp(k+1, vector<int>(k, 0));

    for(int index = k-2; index >= 0; index--) { // k-2 is lye liya h kyuki iss fn me jo slice h uska size k-1 h 

        for(int n = 1; n<=k/3; n++) {

            int include = slices[index] + dp[index + 2][n-1];
            int exclude = 0 + dp[index + 1][n];

            dp[index][n] = max(include, exclude);
        }
    }
    return dp[0][k/3];
}

int maxSizeSlices(vector<int>& slices) {

    int k = slices.size();
    vector<int> first, second;

    for(int i = 0; i<k; i++) {

        if(i != k-1)
        first.push_back(slices[i]);

        if(i != 0)
        second.push_back(slices[i]);
    }

    return max(solveTab(first, k), solveTab(second, k));
}

//space optimization
int solveTab(vector<int>& slices, int k) {

    vector<int> prev(k+1, 0);
    vector<int> curr(k+1, 0);
    vector<int> next(k+1, 0);

    for(int index = k-2; index >= 0; index--) { // k-2 is lye liya h kyuki iss fn me jo slice h uska size k-1 h 

        for(int n = 1; n<=k/3; n++) {

            int include = slices[index] + next[n-1];
            int exclude = 0 + curr[n];

            prev[n] = max(include, exclude);
        }

        next = curr;
        curr = prev;
    }

    return curr[k/3];
}

int maxSizeSlices(vector<int>& slices) {

    int k = slices.size();
    vector<int> first, second;

    for(int i = 0; i<k; i++) {

        if(i != k-1)
        first.push_back(slices[i]);

        if(i != 0)
        second.push_back(slices[i]);
    }

    return max(solveTab(first, k), solveTab(second, k));
}



