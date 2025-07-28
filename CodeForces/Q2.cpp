#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define loop(i, a, b) for (int i = a; i < b; i++)

vector<int> readvec(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

void printvec(const vector<int>& v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << nl;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n), c(n), d(n);

    loop(i, 0, n) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    ll total_moves = 0;

    loop(i, 0, n) {
        
        if (b[i] > d[i]) {
            total_moves += a[i];
            total_moves += b[i] - d[i];
        } 
        
        else if (a[i] > c[i]) {
            total_moves += a[i] - c[i];
        }
    }

    cout << total_moves << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    loop(i, 0, t) {
        solve();
    }

    return 0;
}
