#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

//rec only
// int solveRec(vector<pair<int, int>> &ch, int x, int ind, int sum)
// {
//     if (ind == ch.size())
//         return 0;

//     int ans = 0;

//     if (sum - ch[ind].first >= 0)
//     {
//         ans = max(ch[ind].second + solveRec(ch, x, ind + 1, sum - ch[ind].first + x), solveRec(ch, x, ind + 1, sum + x));
//     }

//     else
//     {
//         ans = solveRec(ch, x, ind + 1, sum + x);
//     }

//     return ans;
// }

// void solve()
// {
//     int m, x;
//     cin >> m >> x;

//     vector<pair<int, int>> ch;

//     for (int i = 0; i < m; i++)
//     {
//         int c, h;
//         cin >> c >> h;

//         ch.push_back({c, h});
//     }

//     int ind = 0;
//     int sum = 0;
//     int ans = solveRec(ch, x, ind, sum);

//     cout << ans << endl;
// }


//meme
// int solveMem(vector<pair<int, int>> &ch, int x, int ind, int sum, unordered_map<string, int> &memo)
// {
//     if (ind == ch.size())
//     return 0;

//     string key = to_string(ind) + "_" + to_string(sum);

//     if (memo.find(key) != memo.end())
//     return memo[key];

//     int ans = 0;

//     if (sum - ch[ind].first >= 0)
//     {
//         ans = max(ch[ind].second + solveMem(ch, x, ind + 1, sum - ch[ind].first + x, memo), solveMem(ch, x, ind + 1, sum + x, memo));
//     }

//     else
//     {
//         ans = solveMem(ch, x, ind + 1, sum + x, memo);
//     }

//     memo[key] = ans;
//     return ans;
// }

// void solve()
// {
//     int m, x;
//     cin >> m >> x;

//     vector<pair<int, int>> ch;
//     unordered_map<string, int> memo;

//     for (int i = 0; i < m; i++)
//     {
//         int c, h;
//         cin >> c >> h;

//         ch.push_back({c, h});
//     }

//     int ind = 0;
//     int sum = 0;
//     int ans = solveMem(ch, x, ind, sum, memo);

//     cout << ans << endl;
// }


// signed main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }



signed main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	
    for (int tn = 0; tn < t; tn++)
	{
		int m, x;
		cin >> m >> x;
		vector<int> c(m), h(m);
		for (int i = 0; i < m; i++)
			cin >> c[i] >> h[i];

		int tot = accumulate(h.begin(), h.end(), 0);

		vector<vector<long long> > dp(m + 1, vector<long long>(tot + 1, -1));
		dp[0][0] = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j <= tot; j++)
			{
				if (dp[i][j] != -1)
				{
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + x);
					if (dp[i][j] >= c[i] && j + h[i] <= tot)
						dp[i + 1][j + h[i]] = max(dp[i + 1][j + h[i]], dp[i][j] - c[i] + x);
				}
			}
		}
		for (int i = tot; i >= 0; i--)
		{
			if (dp[m][i] != -1)
			{
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}