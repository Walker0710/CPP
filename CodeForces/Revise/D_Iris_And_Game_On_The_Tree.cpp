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
    vector<vector<int>> adj(n+1);

    for(int i = 0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string s;
    cin >> s;

    int c0 = 0, c1 = 0, c2 = 0;

    for(int i = 2; i<n+1; i++) {
        if(adj[i].size() == 1) {
            
            if(s[i-1] == '?') {
                c2++;
            }

            else if(s[i-1] == '0') {
                c0++;
            }

            else {
                c1++;
            }
        }
    }

    int cnt = count(all(s), '?') - c2 - (s[0] == '?');

    if(s[0] != '?') {
        int ans = (s[0] == '0') ? c1 : c0;
        ans += (c2 + 1)/2;
        cout << ans << endl; 
    }

    else {
        int ans = max(c1, c0);

        if(c1 == c0 && cnt%2) {
            ans += (c2 + 1)/2;
        }

        else {
            ans += c2/2;
        }

        cout << ans << endl;
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