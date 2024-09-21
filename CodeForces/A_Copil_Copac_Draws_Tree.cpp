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
    cin >> n;

    vector<pair<int, int>> a(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        int fs;
        int sc;

        cin >> fs >> sc;
        a[i] = {fs, sc};
    }

    unordered_set<int> rec;
    rec.insert(1);
    int ans = 0;

    while (rec.size() != n)
    {
        ans++;

        for (int i = 0; i < n - 1; i++)
        {
            auto pair = a[i];

            if (rec.find(pair.first) != rec.end() && rec.find(pair.second) != rec.end())
            {
                continue;
            }

            if (rec.find(pair.first) != rec.end() || rec.find(pair.second) != rec.end())
            {
                if (rec.find(pair.first) != rec.end())
                {
                    rec.insert(pair.second);
                }

                else
                {
                    rec.insert(pair.first);
                }
            }
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
