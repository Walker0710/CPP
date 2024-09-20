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

    vector<int> a(n);

    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    while(q--) {
        int l, k;
        cin >> l >> k;

        l--;  
        int maxIndex = -1;
        int value = a[l];  

        for (int i = l; i < n; ++i) {
            value = value & a[i];

            if (value < k) {
                break;
            }
            maxIndex = i; 
        }

        if(maxIndex == -1) {
            cout << maxIndex << " ";
            continue;
        }

        cout << maxIndex + 1 << " ";
    }

    cout <<endl;
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