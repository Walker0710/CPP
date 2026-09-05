#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int yoo = 0;

    for (int i = 1; i < n - 1; i++) {
        if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
            if(s[i-1] == s[i+1]) {
                yoo = 2;
                break;
            }

            else {
                yoo = 1;
            }
        }
    }

    int cnt = 0;
    int i = 0;

    while (i < n) {
        cnt++;
        i++;

        while (i < n && s[i] == s[i - 1]) {
            i++;
        }
    }

    cout << cnt - yoo << endl;
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