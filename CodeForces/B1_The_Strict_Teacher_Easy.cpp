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

    int pos1, pos2;
    cin >> pos1 >> pos2;

    int init;
    cin >> init;

    // case 1 extream

    if(init < pos1 && init < pos2) {
        int mini = min(pos1, pos2);
        cout << mini - 1 << endl;
    }

    else if (init > pos1 && init > pos2) {
        int maxi = max(pos1, pos2);
        cout << n - (maxi) << endl;
    }

    else {
        int yoo = abs(pos1 - pos2);
        cout << yoo/2 << endl;    
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