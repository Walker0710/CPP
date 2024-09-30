#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int n;
    int m;
    cin >> n >> m;
    
    vector<int> a(m);
    for(int i = 0; i<m; i++) {
        cin >> a[i];
    }

    map<int, int> rec;

    for(int i = 1; i<=n; i++) {
        rec[i] = 0;
    }

    for(auto x : a) {
        rec[x]++;
    }

    int ans = 0; 
    int s = 0;
    int e = 2*m;

    while (s <= e)
    {
        int mid = s + (e-s)/2;

        int possib = false;
        int left = 0;
        int help = 0;

        for(int i = 1; i<=n; i++) {
            if(mid > rec[i]) {
                help = help + (mid - rec[i])/2;
            }

            else {
                left = left + rec[i] - mid;
            }
        }

        possib = (help >= left);

        if(possib) {
            ans = mid;
            e = mid - 1;
        }

        else {
            s = mid + 1;
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