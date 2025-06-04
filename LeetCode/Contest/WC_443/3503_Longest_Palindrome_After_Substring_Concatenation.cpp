#include <bits/stdc++.h>

using namespace std;

// << ,

bool checkPal(string &s, int l, int r)
{
    for (; l < r; ++l, --r)
        if (s[l] != s[r])
            return false;

    return true;
}

vector<int> longestPalindromes(string &s)
{
    int n = s.size();
    vector<int> res(n + 1, 0);

    for (int i = 0; i < n; ++i)
        for (int j = n - 1; i <= j && res[i] < 2; --j)
            res[i] = checkPal(s, i, j) ? j - i + 1 : 1;

    return res;
}

int longestPalindrome(string s, string t)
{
    reverse(begin(t), end(t));
    vector<int> s_pal = longestPalindromes(s), t_pal = longestPalindromes(t);

    int m = s.size(), n = t.size(), res = 0;
    int dp[1001][1001] = {};

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (s[i] == t[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;

            else
                dp[i + 1][j + 1] = 0;
            res = max(res, 2 * dp[i + 1][j + 1] + max(s_pal[i + (s[i] == t[j])], t_pal[j + (s[i] == t[j])]));
        }

    return res;
}