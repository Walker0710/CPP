#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

// bool match(vector<int> &first, vector<int> &second, int n) {
    
//     int firAns = 0, secAns = -1;

//     for(int i = 0; i<=n; i++) {
//         if(first[i] == 0) {
//             firAns = i;
//             break;
//         }
//     }

//     for(int i = 0; i<=n; i++) {
//         if(second[i] == 0) {
//             secAns = i;
//             break;
//         }
//     }

//     return firAns == secAns;
// }

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     vector<int> first(n + 1, 0);
//     vector<int> second(n + 1, 0);

//     for (int i = 0; i < n; i++)
//     {
//         second[a[i]]++;
//     }

//     int ans = -1;

//     for (int i = 0; i < n; i++)
//     {
//         first[a[i]]++;
//         second[a[i]]--;

//         if(match(first, second, n)) {
//             ans = i;
//             break;
//         }
//     }

//     if(ans == -1) {
//         cout << -1 << endl;
//         return;
//     }

//     cout << 2 << endl;
//     cout << 1 << " " << ans + 1 << endl;
//     cout << ans + 2 << " " << n << endl;
// }


void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> prefix(n);
    vector<int> suffix(n);

    set<int> preMex, sufMex;
    int a = 0, b = 0;

    for(int i = 0; i<n; i++) {
        preMex.insert(arr[i]);

        while(preMex.count(a))
        a++;

        prefix[i] = a;
    }

    for(int i = n-1; i>=0; i--) {
        sufMex.insert(arr[i]);

        while(sufMex.count(b)) 
        b++;

        suffix[i] = b;
    }

    vector<pair<int, int>> ans;

    for(int i = 0; i<n-1; i++) {
        if(prefix[i] == suffix[i+1]) {
            ans.push_back({1, i+1});
            ans.push_back({i+2, n});
            break;
        }
    }

    if(!ans.size()) 
    cout << -1 << endl;

    else {
        cout << 2 << endl;

        for(auto &i : ans) {
            cout << i.first << " " << i.second << endl;
        }
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