#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    int min_cards = accumulate(all(a), (int)0);
    int maxi = *max_element(all(a));

    int m = n;
    int max_cards = min_cards + k;

    while(m > 1) {
        int temp = max_cards/m;

        if(m*temp >= min_cards && temp >= maxi) {
            cout << m << endl;
            return ;
        }

        m--;
    }

    cout << 1 << endl;
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