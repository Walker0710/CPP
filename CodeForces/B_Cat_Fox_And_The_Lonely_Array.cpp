#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,
bool isSet(int x, int bit) {
    return ((x >> bit) & 1) == 1; 
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    bool flag = false;

    for(int i = 0; i<n; i++) {
        if(a[i] != 0)
        flag = true;
    }

    if(!flag) {
        cout << 1 << endl;
        return ;
    }

    vector<vector<int>> arr(31);

    for(int i = 0; i<n; i++) {
        for(int j = 30; j>=0; j--) {
            if(isSet(a[i], j)) {
                arr[j].push_back(i);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i<=30; i++) {
        
        if(arr[i].size() == 0) 
        continue;

        ans = max(ans, arr[i][0] + 1);

        for(int j = 1; j<arr[i].size(); j++) {
            ans = max(ans, arr[i][j] - arr[i][j-1]);
        }

        ans = max(ans, n-arr[i][arr[i].size() - 1]);
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