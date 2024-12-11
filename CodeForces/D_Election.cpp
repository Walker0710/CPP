#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n, c;
    cin >> n >> c;

    vector<int> a(n, 0);
    int maxi = 0, maxindex = 0;
    a[0] += c;

    for (int i = 0; i < n; i++)
    {
        int toPush;
        cin >> toPush;

        a[i] += toPush;

        if(a[i] > maxi) {
            maxindex = i;
            maxi = a[i];
        }
    }

    vector<int> prefix(n);
    prefix[0] = a[0];

    for (int i = 1; i < n; i++)
    prefix[i] = a[i] + prefix[i - 1];

    vector<int> ans(n);
    ans[maxindex] = 0;

    for(int i = 0; i<n; i++) {
        
        if(i == maxindex) 
        continue;

        if(i == 0) {
            if(a[i] == maxi) {
                ans[i] = 0;
            }

            else {
                ans[i] = 1;
            }
        }

        if(prefix[i] >= maxi) {
            ans[i] = i;
        } 

        else
        ans[i] = i+1;
    }

    for(int i = 0; i<n; i++) {
        cout << ans[i] << " ";
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



