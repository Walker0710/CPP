#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n+1, 0);

    for(int i = 0; i<n; i++) {
        int yoo = 0;
        cin >> yoo;

        a[yoo]++;
    }

    int nene = 0;
    int you = 0;

    for(int i = 1; i<=n; i++) {
        if(a[i] == 0)
        nene++;

        if(a[i] == 2)
        you++;
    }
    
    int ans = 0;

    if(you > nene) {
        ans = you + n - 2*nene;
    }

    else {
        ans = you;
    }

    cout << ans << endl;
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