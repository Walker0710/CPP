#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

bool check(int mid, int node, int parent, unordered_map<int, list<int>> &adj, vector<int> &a)
{

    if (mid >= 1e10)
    {
        return false;
    }

    int extraVal = mid - a[node];
    if (extraVal < 0)
    {
        extraVal = 0;
    }

    bool flag = true;
    int cnt = 0;

    for (auto child : adj[node])
    {
        if (child != parent)
        {
            flag &= check(extraVal + mid, child, node, adj, a);
            cnt++;
        }
    }
    if (a[node] < mid && cnt == 0)
    {
        return false;
    }

    return flag;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int, list<int>> adj;

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;

        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    int s = 0;
    int e = 1e10;
    int ans = 0;
    int preSum = a[1];
    a[1] = 0;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        bool flag = true;
        for (auto child : adj[1])
        {
            flag &= check(mid, child, 1, adj, a);
        }

        if (flag)
        {
            ans = max(mid, ans);
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }

    ans = ans + preSum;
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