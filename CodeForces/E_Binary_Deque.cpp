#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>
#include <unordered_set>

using namespace std;

// << ,

// int solveRec(vector<int> &a, int i, int j, int sum, int s)
// {
//     if (sum == s)
//     {
//         return 0;
//     }

//     int ans = INT_MAX;

//     ans = 1 + min(solveRec(a, i+1, j, sum - a[i], s), solveRec(a, i, j-1, sum - a[j], s));

//     return ans;
// }

// void solve()
// {
//     int n;
//     int s;

//     cin >> n >> s;

//     int sum = 0;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         sum = sum + a[i];
//     }

//     if (sum < s)
//         cout << -1 << endl;

//     else
//     {
//         cout << solveRec(a, 0, n - 1, sum, s) << endl;
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// trying meme
int solveMem(vector<int> &a, int i, int j, int sum, int s, vector<vector<int>> &dp)
{
    if (sum == s)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    ans = 1 + min(solveMem(a, i + 1, j, sum - a[i], s, dp), solveMem(a, i, j - 1, sum - a[j], s, dp));

    return dp[i][j] = ans;
}

void solve()
{
    int n;
    int s;

    cin >> n >> s;

    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }

    if (sum < s)
        cout << -1 << endl;

    else
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        cout << solveMem(a, 0, n - 1, sum, s, dp) << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

// using BS as suggested in que
//  << ,

void solve()
{
    int n;
    int s;

    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> prefixSum(n);
    prefixSum[0] = a[0];

    for (int i = 0; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    if (prefixSum[n - 1] < s)
    {
        cout << -1 << endl;
    }

    else
    {
        int st = 0;
        int en = n - 1;
        int ans = 0;

        while (st < en)
        {
            int mid = st + (en - st) / 2;

            if ((st > 0 && prefixSum[mid] - prefixSum[st - 1] == s) || (st == 0 && prefixSum[mid] == s))
            {
                ans = ans + min(mid - st, en - mid);
                break;
            }

            if ((st > 0 && prefixSum[mid] - prefixSum[st - 1] > s) || (st == 0 && prefixSum[mid] > s))
            {
                en = mid;
            }

            if ((st > 0 && prefixSum[mid] - prefixSum[st - 1] < s) || (st == 0 && prefixSum[mid] < s))
            {
                st = mid + 1;
            }
        }

        cout << ans <<endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}