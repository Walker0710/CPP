#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;

    string s;
    cin >> s;

    vector<string> v1;
    string s2 = "";
    set<char> st1, st2;

    for(int j = 0; j<k; j++) {
        st1.insert(j + 'a');
    }

    st2 = st1;
    int cnt1 = 0;
    int f1 = 0;

    for(int i = s.size() - 1; i>=0; i--) {
        if(st1.find(s[i]) != st1.end()) {
            st1.erase(s[i]);
        }

        s2 = s2 + s[i];
        f1 = 0;

        if(st1.size() == 0) {
            reverse(all(s2));
            f1 = 1;
            v1.push_back(s2);
            st1 = st2;
            cnt1++;
        }
    }

    reverse(all(v1));

    if(cnt1 >= n) {
        cout << "YES" << endl;
        return ;
    }

    string res = "";
    res = res + *st1.begin();

    for(int j = 0; j<v1.size(); j++) {
        res = res + v1[j][0];
    }

    while(res.size() < n) {
        res = res + "a";
    }

    cout << "NO" << endl;
    cout << res << endl;

    return ;
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