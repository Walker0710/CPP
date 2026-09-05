#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    vector<int> yoo;
    yoo.push_back(a);
    yoo.push_back(b);
    yoo.push_back(c);
    
    sort(yoo.begin(), yoo.end());

    int ans = 0;

    while(true) {
        if(yoo[0] == yoo[1] || yoo[1] == yoo[2] || yoo[0] == yoo[2]) {
            break;
        }

        else {
            yoo[2]--;
            yoo[0]++;
            ans++;
        }

        sort(yoo.begin(), yoo.end());
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