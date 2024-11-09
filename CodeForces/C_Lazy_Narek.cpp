#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

int solveMem(int i, int indi, vector<string> &v, string &str, vector<int> &freq, vector<vector<int>> &dp)
{
    if (i == v.size())
    return 0;

    if (dp[indi][i] != -1)
    return dp[indi][i];

    int ans = INT_MIN;
    ans = solveMem(i + 1, indi, v, str, freq, dp);

    int temp = indi;
    int sc = 0;

    for (int j = 0; j < v[i].length(); j++)
    {
        if (v[i][j] == str[temp])
        {
            sc += (temp == 4) * 10;
            ans = max({ans, sc - freq[i] + solveMem(i + 1, (temp + 1) % 5, v, str, freq, dp), sc - freq[i] + solveMem(i + 1, 0, v, str, freq, dp)});
            temp = (temp + 1) % 5;
        }
    }
    return dp[indi][i] = ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> v(n);

    for(int i = 0; i<n; i++)
    cin >> v[i];

    vector<int> freq(n);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;

        for (auto &c : v[i])
        cnt += (c == 'n' or c == 'a' or c == 'r' or c == 'e' or c == 'k');

        freq[i] = cnt;
    }

    string str = "narek";
    vector<vector<int>> dp(6, vector<int>(n + 3, -1));

    cout << solveMem(0, 0, v, str, freq, dp) << endl;
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