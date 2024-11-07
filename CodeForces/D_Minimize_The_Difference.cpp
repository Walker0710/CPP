#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

bool chkMax(vector<int> a, int mid) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > mid) {
            if (i == a.size() - 1) {
                return false;
            }
            int excess = a[i] - mid;
            a[i] = mid;
            a[i + 1] += excess;
        }
    }
    return true;
}

bool chkMin(vector<int> a, int mid) {
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] < mid) {
            if (i == 0) {
                return false;
            }
            int deficit = mid - a[i];
            a[i] = mid;
            a[i - 1] -= deficit;
        }
    }
    return true;
}


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int maxi = LLONG_MIN, mini = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
    }

    int s = 0, e = maxi;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (chkMax(a, mid)) {
            maxi = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    s = mini;
    e = maxi;  
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (chkMin(a, mid)) {
            mini = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    cout << maxi - mini << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
