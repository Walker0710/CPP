#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    int c = 0;
    for(int i = 0; i<n; i++)
    {
        c += (a[i] % 2);
    }

    if (c % 2 == 0)
    {
        if (y % 2 == x % 2)
        cout << "Alice" << endl;
        
        else
        cout << "Bob" << endl;
    }
    else
    {
        if (y % 2 != x % 2)    
        cout << "Alice" << endl;
    
        
        else
        cout << "Bob" << endl;
    }
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