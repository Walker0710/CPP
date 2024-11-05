#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,
// int solveRec(vector<int> &yoo, int ind, int prevInd, int d) {
    
//     if(ind == yoo.size()) {
//         return 0;
//     }
    
//     if(ind - prevInd - 1 >= d+1) {
//         return INT_MAX;
//     }

//     //inc
//     int inc = yoo[ind] + 1 + solveRec(yoo, ind+1, ind, d);

//     //exc
//     int exc = solveRec(yoo, ind+1, prevInd, d);

//     int ans = min(inc, exc);    

//     return ans;
// }

// void solve()
// {
//     int n, m, k, d;
//     cin >> n >> m >> k >> d;

//     vector<vector<int>> mat(n, vector<int> (m, 0));

//     for(int i = 0; i<n; i++) {
//         for(int j = 0; j<m; j++) {
//             cin >> mat[i][j];
//         }
//     }

//     vector<int> rec(n);

//     for(int i = 0; i<n; i++) {

//         vector<int> yoo = mat[i];

//         int ind = 1;
//         int prevInd = 0;

//         rec[i] = solveRec(yoo, ind, prevInd, d);
//     }

//     int sum = 0;

//     for(int i = 0; i<k; i++) {
//         sum += rec[i];
//     }

//     int ans = sum;

//     for(int i = 0; i<n - k; i++) {
//         sum = sum + rec[i+k] - rec[i];
//         ans = min(sum, ans);
//     }

//     cout << ans << endl;
// }

int solveRow(vector<int>& yoo, int d) {
    int m = yoo.size();
    vector<int> dp(m, INT_MAX);

    dp[0] = yoo[0] + 1; // Start with the first support

    for (int i = 1; i < m; i++) {
        for (int j = max(0LL, i - d); j < i; j++) {
            dp[i] = min(dp[i], dp[j] + yoo[i] + 1);
        }
    }

    return dp[m - 1]; // Minimum cost to place support on the last cell
}

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> rec(n);

    for (int i = 0; i < n; i++) {
        rec[i] = solveRow(mat[i], d);
    }

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += rec[i];
    }

    int ans = sum;

    for (int i = 0; i < n - k; i++) {
        sum = sum + rec[i + k] - rec[i];
        ans = min(sum, ans);
    }

    cout << ans << endl;
}


signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}