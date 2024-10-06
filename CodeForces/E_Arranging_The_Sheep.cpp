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

    string a;
    cin >> a;

    vector<int> rec;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '*')
        rec.push_back(i);
    }

    if (rec.size() == 0 || rec.size() == 1)
    {
        cout << 0 << endl;
        return;
    }

    int midIndex = rec[rec.size() / 2];

    int ans = 0;
    int counter = 1;
    for (int i = (rec.size()/2) + 1; i < rec.size(); i++)
    {
        ans += rec[i] - midIndex - counter;
        counter++;
    }

    counter = 1;
    for (int i = (rec.size()/2) - 1; i >= 0; i--)
    {
        ans += midIndex - rec[i] - counter;
        counter++;
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