#include <bits/stdc++.h>

using namespace std;

// << ,

int dp[501][501];  // Memoization table

int solve(string &s, int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    if (dp[l][r] != -1) return dp[l][r];

    // Option 1: Remove s[l] alone, then solve for the rest
    int ans = 1 + solve(s, l + 1, r);

    // Option 2: Try to match s[l] with any s[k] where k > l and s[k] == s[l]
    for (int k = l + 1; k <= r; ++k) {
        if (s[k] == s[l]) {
            // We can delete s[l+1...k-1] first, then combine s[l] and s[k]
            ans = min(ans, solve(s, l + 1, k - 1) + solve(s, k, r));
        }
    }

    return dp[l][r] = ans;
}

int minDeletions(string s) {
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, s.size() - 1);
}

int main() {
    string s;
    cin >> s;
    cout << minDeletions(s) << endl;
    return 0;
}
