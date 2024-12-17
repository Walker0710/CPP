#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    int sum = (c+1)*(c+2)/2;

    int even = 0, odd = 0;

    for(auto &i:a) {
        sum = sum - (i+2)/2;
        sum = sum - (c - i + 1);

        odd = odd + i%2;
        even = even + (1 - i%2);

        if(i%2)
        sum = sum + odd;

        else 
        sum = sum + even;
    }

    cout << sum << endl;
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