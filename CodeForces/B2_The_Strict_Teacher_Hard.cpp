#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> b(m);
    int maxi, mini = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];

        maxi = max(maxi, b[i]);
        mini = min(mini, b[i]);
    }

    while (q--)
    {
        int init;
        cin >> init;

        int left = n;
        int right = 0;

        for(int i = 0; i<m; i++) {
            if(b[i] > init) {
                right = min(right, b[i]);
            }

            if(b[i] < init) {
                left = max(left, b[i]);
            }
        }

        // case 1 extream
        if (init < mini) 
        {
            cout << mini - 1 << endl;
        }

        else if (init > maxi)
        {
            cout << n - (maxi) << endl;
        }

        else
        {
            int yoo = abs(right - left);
            cout << yoo / 2 << endl;
        }
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