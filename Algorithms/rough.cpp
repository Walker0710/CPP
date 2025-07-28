#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;
// int findTotalCost(int n, int k)
// {
//     if (k == 1)
//     {
//         return n % MOD;
//     }
//     vector<long long> powk(n + 1, 1);
//     for (int i = 1; i <= n; i++)
//         powk[i] = powk[i - 1] * k % MOD;
//     long long factk = 1;
//     for (int i = 2; i <= k; i++)
//         factk = factk * i % MOD;
//     auto P = [&](int L) -> long long
//     {
//         if (L < k)
//             return 0;
//         return factk * powk[L - k] % MOD;
//     };
//     auto B = [&](int L) -> long long
//     {
//         if (L < k)
//             return powk[L];
//         return (powk[L] - P(L) + MOD) % MOD;
//     };
//     vector<long long> dp(k + 1, 0), ndp(k + 1, 0);
//     dp[k] = 1;
//     long long answer = 0;

//     for (int len = 1; len <= n; ++len)
//     {
//         fill(ndp.begin(), ndp.end(), 0);
//         long long good = P(len);
//         long long all = powk[len];
//         long long bad = (all - good + MOD) % MOD;

//         if (len >= k)
//         {
//             long long chooseWays = dp[k] * factk % MOD;
//             answer = (answer + chooseWays) % MOD;

//             ndp[0] = (ndp[0] + chooseWays) % MOD;
//         }

//         long long nonChosenGood = 0;
//         if (len >= k)
//         {
//             long long goodTotal = good;
//             long long chooseWays = dp[k] * factk % MOD;
//             nonChosenGood = (goodTotal - chooseWays + MOD) % MOD;
//         }
//         else
//         {
//             nonChosenGood = good; // (actually 0 when len<k)
//         }
//         long long nonChosen = (bad + nonChosenGood) % MOD;

//         long long totalPrev = 0;
//         for (int d = 0; d <= k; ++d)
//             totalPrev = (totalPrev + dp[d]) % MOD;
//         long long expectedNonChosen = totalPrev * k % MOD;

//         for (int d = 0; d <= k; ++d)
//         {
//             long long ways = dp[d] * k % MOD;
//             if (len >= k && d == k)
//             {
//                 long long chooseFromThis = dp[k] * factk % MOD;
//                 ways = (ways - chooseFromThis + MOD) % MOD;
//             }
//             int nd = min(d + 1, k); // increment distance (cap at k)
//             ndp[nd] = (ndp[nd] + ways) % MOD;
//         }

//         dp.swap(ndp);
//     }

//     return (int)(answer % MOD);
// }

// long long findTotalCost(int n, int k) {
//     vector<long long> P(n+1), dp(n+1);
//     long long fact = 1;
//     for (int i = 1; i <= k; i++)
//         fact = fact * i % MOD;
//     P[0] = 1;
//     for (int i = 1; i <= n; i++) {
//         P[i] = P[i-1] * k % MOD;
//         if (i >= k) {
//             P[i] = (P[i] - P[i-k] * fact % MOD + MOD) % MOD;
//         }
//     }
//     for (int x = 0; x <= n; x++) {
//         if (x < k) {
//             dp[x] = 0;
//         } else {
//             long long s = 0;
//             for (int i = 0; i <= x - k; i++) {
//                 s = (s + P[i] * fact % MOD * (1 + dp[x - k - i]) % MOD) % MOD;
//             }
//             dp[x] = s;
//         }
//     }
//     return dp[n];
// }

// int findTotalCost(int n, int k) {
//     if (n < k) return 0;

//     // precompute factorial k! and powers of k
//     long long fact = 1;
//     for (int i = 1; i <= k; i++)
//         fact = fact * i % MOD;

//     vector<long long> powk(n+1, 1);
//     for (int i = 1; i <= n; i++)
//         powk[i] = powk[i-1] * k % MOD;

//     // A[i] = number of length-i sequences with NO perfect team
//     vector<long long> A(n+1, 0);
//     A[0] = 1;
//     for (int i = 1; i <= n; i++) {
//         A[i] = (k * A[i-1]) % MOD;
//         if (i >= k) {
//             // subtract those that close a perfect team at the end
//             A[i] = (A[i] - A[i-k] * fact) % MOD;
//             if (A[i] < 0) A[i] += MOD;
//         }
//     }

//     // now sum over positions i = 0 .. n-k
//     long long ans = 0;
//     for (int i = 0; i <= n-k; i++) {
//         // prefix [0..i-1] has no perfect: A[i]
//         // block [i..i+k-1] is perfect: *fact
//         // suffix free: *k^{n-k-i}
//         long long ways = A[i] * fact % MOD * powk[n-k-i] % MOD;
//         ans = (ans + ways) % MOD;
//     }
//     return int(ans);
// }

// check if subarray seq[l..r] is a permutation of 1..k
bool isPerfectTeam(const vector<int>& seq, int l, int r, int k) {
    if (r - l + 1 != k) return false;
    vector<int> count(k + 1, 0);
    for (int i = l; i <= r; ++i) {
        if (seq[i] < 1 || seq[i] > k || ++count[seq[i]] > 1)
            return false;
    }
    return true;
}

// count number of non-overlapping perfect teams using greedy scan
int countPerfectTeams(const vector<int>& seq, int k) {
    int n = seq.size(), count = 0;
    for (int i = 0; i <= n - k;) {
        if (isPerfectTeam(seq, i, i + k - 1, k)) {
            count++;
            i += k;
        } else {
            i++;
        }
    }
    return count;
}

int findTotalCost(int n, int k) {
    vector<int> seq(n);
    int total = 0;

    // try all sequences of length n with entries in 1..k
    function<void(int)> generate = [&](int pos) {
        if (pos == n) {
            int teams = countPerfectTeams(seq, k);
            total = (total + teams) % MOD;
            return;
        }
        for (int val = 1; val <= k; ++val) {
            seq[pos] = val;
            generate(pos + 1);
        }
    };

    generate(0);
    return total;
}

int main()
{
    int n, k;
    cin >> n >> k;
    // cout << bruteForceTotalCost(n, k) << endl;
    cout << findTotalCost(n, k) << endl;
    return 0;    
}