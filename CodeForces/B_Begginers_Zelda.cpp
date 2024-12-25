#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

void solve()
{
    int n;
    cin >> n;

    unordered_map<int, int> freq;

    for(int i = 0; i<n-1; i++) {
        int one, two;
        cin >> one >> two;

        freq[two]++;
        freq[one]++;
    } 

    int cnt = 0;

    for(const auto& pair : freq) {
        if(pair.second == 1) 
        cnt++;
    }

    cout << (cnt+1)/2 << endl;
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