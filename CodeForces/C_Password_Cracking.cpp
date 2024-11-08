#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

bool getResonse(string &s) {
    bool res;
    cout << "? " << s << endl;
    cin >> res;
    return res;
}

void solve()
{
    int n;
    cin >> n;

    string s = "0";

    bool res = getResonse(s);

    if(!res) {
        s = "1";
    }

    while(s.size() < n) {
        s += '0';
        res = getResonse(s);

        if(!res) {
            s.pop_back();
            s += '1';

            res = getResonse(s);

            if(!res) {
                s.pop_back();
                break;
            }
        }
    }

    while (s.size() < n) {

        s = '0' + s;
        res = getResonse(s);

        if(!res) {
            s = s.substr(1);
            s = '1' + s;
        }
    }

    cout << "! " << s << endl;
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