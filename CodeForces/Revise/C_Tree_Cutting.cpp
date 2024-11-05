#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

vector<int> adj[100005];  

int dfs(int node, int parent, int treeSz, int &cuts) {
    int sz = 1;

    for (auto &i : adj[node]) {
        if (i != parent) {
            sz += dfs(i, node, treeSz, cuts);
        }
    }

    if (sz >= treeSz) {
        sz = 0;
        cuts++;
    }

    return sz;
}

bool ok(int treeSz, int n, int k) {
    int cuts = 0;
    dfs(1, -1, treeSz, cuts);  
    return cuts > k;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();  
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int left = 0, right = n, ans = 0;

    while (left <= right) {

        int mid = (left + right) / 2;
        
        if (ok(mid, n, k)) {
            ans = mid;
            left = mid + 1;
        } 
        
        else {
            right = mid - 1;
        }
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

