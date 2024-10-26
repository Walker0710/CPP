#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

int solveRec(vector<int> &a, int index, int dk, int k) {
    
    if(index == a.size()) {
        return 0;
    }

    if(dk > k && index != a.size()) {
        return INT_MAX;
    }

    //converting
    int con = 0;

    if(index == 0 && a[0] > a[1]) {
        con = a[1] + solveRec(a, index+1, dk+1, k);
    }

    else {
        con = 
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    int ans = solveRec(a, 0, 0, k);
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