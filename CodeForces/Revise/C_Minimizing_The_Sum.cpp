#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

// int solveRec(vector<int> &a, int index, int cnt, int k, vector<int> &b) {
    
//     if(index == a.size()) {
//         return 0;
//     }

//     if(cnt > k) {
//         return INT_MAX;
//     }

//     int ans = INT_MAX;

//     //converting
//     int con = 0;
    
//     if(index == 0 && a[1] < a[0]) {
//         b[0] = a[1];
//         con = b[0] + solveRec(a, index+1, cnt+1, k, b);
//         b[0] = a[0];
//     }

//     else {
//         int back = b[index];
//         b[index] = min(b[index-1], b[index+1]);
//         con = b[index] + solveRec(a, index+1, cnt+1, k, b);
//         b[index] = back;
//     }

//     //not converting
//     int notCon = 0;
//     notCon = a[index] + solveRec(a, index+1, cnt, k, b);

//     ans = min(con, notCon);

//     return ans;
// }


// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> a(n);
//     vector<int> b(n);

//     for(int i = 0; i<n; i++) {
//         cin >> a[i];
//         b[i] = a[i];
//     }

//     int ans = solveRec(a, 0, 0, k, b);

//     cout << ans << endl;
// }



int n, k;
int a[300005];
int dp[300005][12];

int solveMem(int ind, int left) {
    if(ind == n) 
    return 0;

    if(dp[ind][left] != -1) {
        return dp[ind][left];
    }

    int res = a[ind] + solveMem(ind+1, left);

    for(int i = 1; i<left+1; i++) {
        int mini = a[ind];

        if(i+ind >= n) {
            break;
        }

        for(int j = ind; j<ind+i+1; j++) {
            mini = min(mini, a[j]);
        }

        res = min(res, (mini*(i+1) + solveMem(ind+i+1, left-i)));
    }

    return dp[ind][left] = res;
}


void solve() {
    cin >> n >> k;

    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i<n+2; i++) {
        for(int j = 0; j<12; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = solveMem(0, k);

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