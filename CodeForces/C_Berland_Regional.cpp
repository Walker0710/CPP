#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,
bool compare(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.first < p2.first)
        return true;

    if (p1.first == p2.first)
        return p1.second > p2.second;

    return false;
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> p(n + 1);
    int sum = 0;

    for (int i = 1; i < n + 1; i++)
        cin >> p[i].first;

    for (int i = 1; i < n + 1; i++)
        cin >> p[i].second;

    sort(p.begin() + 1, p.end(), compare);

    vector<int> presum(n+1, 0);
    map<int, int> mp;

    for (int i = 1; i < n + 1; i++)
    {
        presum[i] = presum[i - 1] + p[i].second;

        if (mp.find(p[i].first) == mp.end())
        {
            mp[p[i].first] = i;
        }
    }

    p[0].first = p[1].first;
    p[0].second = 0;

    for (int k = 1; k < n + 1; k++)
    {
        int i = 1, ans = 0, j = 1 + k;
        while (j <= n)
        {
            if (p[j - 1].first != p[i].first)
            {
                j = mp[p[j - 1].first];
                i = j;
                j = i + k;
            }
            else
            {
                ans += presum[j - 1] - presum[i - 1];
                i += k, j += k;
            }
        }
        if (i <= n && j - 1 <= n && p[j - 1].first == p[i].first)
        {
            ans += presum[j - 1] - presum[i - 1];
        }
        cout << ans << " ";
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