#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n, cur = 0;
    cin >> n;
    multiset<int> b;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    
    vector<int> ans(n);
    
    for(int i = 0; i < n; i++){
    
        auto it = b.lower_bound(1 - cur);
    
        if(it == b.end()) 
        return void(cout << -1 << '\n');
        
        cur += *it;
        b.erase(it);
        ans[i] = cur;
    }
    
    for(int i = 0; i < n; i++) 
    cout << ans[i] << " ";

    cout << endl;
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