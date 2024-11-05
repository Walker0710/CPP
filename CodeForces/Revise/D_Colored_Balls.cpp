#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

#define MOD 998244253

// << ,

//wrong ans on 10th test case
void solveRec(vector<int> &a, int index, int sum, int maxi, int &ans)
{

    if (index >= a.size())
    {
        if ((sum + 1) / 2 > maxi)
            ans = (ans + ((sum + 1) / 2) % MOD) % MOD;

        else
            ans = (ans + (maxi) % MOD) % MOD;

        return;
    }

    // exclude
    solveRec(a, index + 1, sum, maxi, ans);

    // include
    solveRec(a, index + 1, sum + a[index], max(maxi, a[index]), ans);
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int index = 0;
    int sum = 0;
    int maxi = INT_MIN;

    int ans = 0;

    solveRec(a, index, sum, maxi, ans);

    cout << ans << endl;
}


// 2nd
void solve()
{
    int n;
    cin >> n;

    int ans = 0;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> cnt(5001, 0);
    vector<vector<int>> dp(5001, vector<int> (5001, 0));

    dp[a[0]][a[0]]++;
    cnt[a[0]]++;

    for(int i = 1; i<n; i++) {
        
        for(int j = 5000; j>a[i]; j--) {
            dp[j][a[i]] = dp[j][a[i]] + cnt[j-a[i]];
            dp[j][a[i]] = dp[j][a[i]]%MOD;
        }

        for(int j = 5000; j>a[i]; j++) {
            cnt[j] = cnt[j] + cnt[j - a[i]];
            cnt[j] = cnt[j]%MOD;
        }

        dp[a[i]][a[i]]++;
        cnt[a[i]]++;
    }

    for(int i = 1; i<=5000; i++) {
        for(int j = 1; j<=i; j++) {
            if(j<=i/2) {

                ans = ans + ((i+1)/2)*dp[i][j];
                ans = ans%MOD;
            }

            else {
                ans = ans + j*dp[i][j];
                ans = ans%MOD;
            }
        }
    }

    cout << ans << endl;
}

signed main()
{
    solve();

    return 0;
}