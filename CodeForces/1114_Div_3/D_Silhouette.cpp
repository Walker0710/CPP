#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        pq.push({b[i], i});
    }

    vector<int> a(n);

    int prev = 0;

    while (!pq.empty())
    {
        int shadow = pq.top().first;

        vector<int> indices;

        while (!pq.empty() && pq.top().first == shadow)
        {
            indices.push_back(pq.top().second);
            pq.pop();
        }

        if (prev == 0 && shadow != 0)
        {
            cout << -1 << '\n';
            return;
        }

        int value;

        if (pq.empty())
        {
            value = prev + 1;
        }
        else
        {
            int nextShadow = pq.top().first;

            int cnt = indices.size();

            int diff = nextShadow - shadow;

            if (diff <= 0 || diff % cnt != 0)
            {
                cout << -1 << '\n';
                return;
            }

            value = diff / cnt;

            if (value <= prev)
            {
                cout << -1 << '\n';
                return;
            }
        }

        for (int idx : indices)
        {
            a[idx] = value;
        }

        prev = value;
    }

    for (int x : a)
    {
        cout << x << ' ';
    }

    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}