#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>

using namespace std;

// << ,

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     vector<int> rec(4, 0);

//     for (int i = 0; i < 4 * n; i++)
//     {
//         if (s[i] == '?')
//         continue;

//         rec[s[i] - 'A']++;
//     }

//     int ans = 0;

//     for (int i = 0; i < 4; i++)
//     {
//         if (rec[i] <= n)
//         ans += rec[i];

//         else        
//         ans += n;
//     }

//     cout << ans << endl;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }


void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> rec(4, 0);

    for (int i = 0; i < 4 * n; i++)
    {
        if (s[i] == '?')
        continue;

        rec[s[i] - 'A']++;
    }

    long long ans = 0;

    for (int i = 0; i < 4; i++)
    {
        if (rec[i] <= n)
            ans += rec[i];
        else        
            ans += n;
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}