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

    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int s = 0;
    int e = 1e9;
    int ans = 0;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        set<int> rec;
        bool np = true;
        bool nop = false;

        for(int i = 0; i<n; i++) {
            np = false;

            for(int j = 0; j<m; j++) {
                
                if(a[j][i] >= mid) {
                    np = true;

                    if(rec.count(j))
                    nop = true;

                    rec.insert(j);
                }
            }

            if(!np)
            break;
        }

        if(np && nop) {
            ans = mid;
            s = mid + 1;
        }

        else {
            e = mid - 1;
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