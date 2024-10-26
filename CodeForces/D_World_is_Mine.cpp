#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     map<int, int> cnt;

//     for(int i = 0; i<n; i++) {
//         int toPush;
//         cin >> toPush;

//         cnt[toPush]++;
//     }

//     int ans = 0;
//     int chance = 0;

//     for(auto it = cnt.begin(); it != cnt.end(); it++) {

//         if(chance >= it->second) {
//             chance = chance - it->second;
//         }

//         else {
//             ans++;
//             chance++;
//         }
//     } 
//     cout << ans << endl;
// }




int find1(vector<int> &v1, int ind, int tot, vector<vector<int>> &dp) {
    
    if(ind == v1.size())
    return 0;

    if(dp[ind][tot] != -1) {
        return dp[ind][tot];
    }

    if(tot - v1[ind] >= 0) {
        return dp[ind][tot] = max(1+find1(v1, ind+1, tot - v1[ind], dp), find1(v1, ind+1, tot+1, dp));
    }

    else 
    return dp[ind][tot] = find1(v1, ind+1, tot+1, dp);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> dp(n+2, vector<int> (n+2, -1));

    map<int, int> freq;
    vector<int> v1;

    for(int i = 0; i<n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    for(auto it:freq) {
        v1.push_back(it.second);
    }

    n = v1.size();
    int ans = find1(v1, 0, 0, dp);

    cout << v1.size() - ans << endl;
    return;
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
















