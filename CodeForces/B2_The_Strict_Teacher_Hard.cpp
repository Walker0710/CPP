#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> b(m);
    int maxi = LLONG_MIN, mini = LLONG_MAX;

    for (int i = 0; i < m; i++) {
        cin >> b[i];
        maxi = max(maxi, b[i]);
        mini = min(mini, b[i]);
    }

    sort(b.begin(), b.end());

    while (q--) {
        int init;
        cin >> init;

        int left = mini;  
        int right = maxi; 

        auto it_right = upper_bound(b.begin(), b.end(), init);
        if (it_right != b.end()) {
            right = *it_right;
        }

        auto it_left = lower_bound(b.begin(), b.end(), init);
        if (it_left != b.begin()) {
            --it_left;
            left = *it_left;
        }

        if (init < mini) {
            cout << mini - 1 << endl;
        }
        
        else if (init > maxi) {
            cout << n - maxi << endl;
        } 
        
        else {
            int yoo = abs(right - left);
            cout << yoo / 2 << endl;
        }
    }
}

signed main() {

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
