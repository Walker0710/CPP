// #include <bits/stdc++.h>

// using namespace std;

// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// #define int long long

// // << ,

// void solve()
// {
//     int n, k, x;
//     cin >> n >> k >> x;

//     vector<int> a(n);

//     for(int i = 0; i<n; i++) {
//         cin >> a[i];
//     }

//     sort(all(a));

//     vector<int> pFix(n);
//     pFix[0] = a[0];

//     for(int i = 1; i<n; i++) {
//         pFix[i] = a[i] + pFix[i-1];
//     }

//     int ans = 0;

//     for(int i = 0; i<=x; i++) {
//         int accSum = pFix[n - i - 1];
//         int kSum = pFix[n - i - 1] - pFix[n - i - 1 - k];

//         ans = max(ans, accSum - 2*kSum);
//     }

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




#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    vector<int> pFix(n);
    pFix[0] = a[0];

    for (int i = 1; i < n; i++) {
        pFix[i] = a[i] + pFix[i - 1];
    }

    int ans = INT_MIN;

    for (int i = 0; i <= k; i++) { 
        int accSum = (n - i - 1 >= 0) ? pFix[n - i - 1] : 0; 
        int kSum = 0;

        if (n - i - 1 - x >= 0) {
            kSum = pFix[n - i - 1] - pFix[n - i - 1 - x];
        } 
        
        else if (n - i - 1 >= 0) {
            kSum = pFix[n - i - 1]; 
        }

        ans = max(ans, accSum - 2 * kSum);
    }

    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
