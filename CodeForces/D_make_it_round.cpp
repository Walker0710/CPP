#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

void solve()
{
    int n, m;
    cin >> n >> m;
    int n0 = n;
    int cnt2 = 0, cnt5 = 0;
    int k = 1;
    while (n > 0 && n % 2 == 0)
    {
        n /= 2;
        cnt2++;
    }
    while (n > 0 && n % 5 == 0)
    {
        n /= 5;
        cnt5++;
    }
    while (cnt2 < cnt5 && k * 2 <= m)
    {
        cnt2++;
        k *= 2;
    }
    while (cnt5 < cnt2 && k * 5 <= m)
    {
        cnt5++;
        k *= 5;
    }
    while (k * 10 <= m)
    {
        k *= 10;
    }
    if (k == 1)
    {
        cout << n0 * m << endl;
    }
    else
    {
        k = (m / k)*k;
        cout << n0 * k << endl;
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