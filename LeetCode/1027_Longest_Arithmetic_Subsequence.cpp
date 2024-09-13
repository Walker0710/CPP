#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

int solv(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (j >= arr.size() || i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int x = 0;
    int l = j + 1, r = arr.size() - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
    
        if (arr[mid] == 2*arr[j] - arr[i])
        {
            x = 1 + solv(j, mid, arr, dp);
            break;
        }
    
        else if (arr[mid] > arr[j] + arr[i])
        {
            r = mid - 1;
        }
    
        else
            l = mid + 1;
    }
    return dp[i][j] = x;
}

int longestArithSeqLength(vector<int>& arr) {

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < arr.size(); i++)
    {
        m[arr[i]] = i;
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (m.find(2*arr[j] - arr[i]) != m.end())
                ans = max(ans, 2 + solv(i, j, arr, dp));
        }
    }

    return ans;
}

int solveMem2(int index, int diff, vector<int> &A, unordered_map<int, int> dp[]) {

    if(index < 0)
    return 0;

    if(dp[index].count(diff))
    return dp[index][diff]; 

    int ans = 0;

    for(int j = index - 1; j>=0; j--) {

        if(A[index] - A[j] == diff) {

            ans = max(ans, 1 + solveMem2(j, diff, A, dp));
        }
    }

    return dp[index][diff] = ans;
}

int longestArithSeqLength(vector<int>& A) {

    int n = A.size();

    if(n <= 2)
    return n;

    int ans = 0;
    unordered_map<int, int> dp[n+1];

    for(int i = 0; i<n; i++) {

        for(int j = i+1; j<n; j++) {

            ans = max(ans, 2 + solveMem2(i, A[j] - A[i], A, dp));
        }
    }

    return ans;
}

int longestArithSeqLength(vector<int> &A) {

    int n = A.size();

    if(n <= 2)
    return n;

    unordered_map<int, int> dp[n+1];
    int ans = 0;

    for(int i = 1; i<n; i++) {

        for(int j = 0; j<i; j++) {

            int diff = A[i] - A[j];
            int cnt = 1;

            if(dp[j].count(diff))
            cnt = dp[j][diff];

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}
