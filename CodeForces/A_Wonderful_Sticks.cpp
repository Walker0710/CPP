#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n, k;
    cin >> n;

    string s;
    cin >> s;

    int l = 1;
    int r = n;

    vector<int> arr(n);
    
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '<')
        {
            arr[i + 1] = l++;
        }
        else
        {
            arr[i + 1] = r--;
        }
    }

    arr[0] = l;

    for (auto ele : arr)
    {
        cout << ele << " ";
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