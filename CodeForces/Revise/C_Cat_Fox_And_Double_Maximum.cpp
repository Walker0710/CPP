#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

static bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.first > b.first;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 0; i<n; i++) {
        cin >> p[i];
    }

    vector<int> q(n);
    vector<pair<int, int>> v;
    set<int> s;

    for(int i = 1; i<=n; i++) {
        s.insert(i);
    }

    int curr = -1;
    for(int i = 0; i<n; i++) {
        if(p[i] == 1) {
            curr = i;
        }
    }

    for(int i = 0; i<n; i++) {
        if(i%2 != curr%2) {
            q[i] = n - p[i] + 2;
            s.erase(q[i]);
        }

        else {
            v.push_back({p[i], i});
        }
    }

    sort(v.begin(), v.end(), comp);
    int j = 0;

    for(auto i:s) {
        q[v[j++].second] = i;
    }

    for(int i = 0; i<n; i++) {
        cout << q[i] << " ";
    }

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