#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    int maxi = *max_element(all(a));

    int l, r;
    char sign;

    for(int i = 0; i<m; i++) {
        cin >> sign >> l >> r;

        if(sign == '+' && maxi >= l && maxi <= r) {
            maxi++;
        } 

        else if(sign == '-' && maxi >= l && maxi <= r) {
            maxi--;
        }

        cout << maxi  << endl;
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