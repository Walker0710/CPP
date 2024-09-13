#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>
#include <unordered_set>

using namespace std;

// << ,

// void solve()
// {
//     int n;
//     int m;

//     cin >> n >> m;

//     vector<int> a(m);
//     for (int i = 0; i < m; i++)
//     {
//         cin >> a[i];
//     }

//     if (m == 1)
//         cout << 2 << endl;

//     else
//     {
//         sort(a.begin(), a.end());

//         vector<int> diff;
//         diff.push_back(n - (a[m - 1] - a[0] + 1));

//         for (int i = 0; i < m - 1; i++)
//         {
//             diff.push_back(a[i + 1] - a[i] - 1);
//         }

//         sort(diff.rbegin(), diff.rend());
//         int ans = 0;

//         while (diff[0] > 0)
//         {
//             for (int i = 0; i < m; i++)
//             {
//                 if (i == 0 && diff[i] > 1)
//                 {
//                     ans = ans + diff[i] - 1;
//                 }

//                 if (i == 0 && diff[i] == 1)
//                 {
//                     ans = ans + 1;
//                 }

//                 diff[i] = diff[i] - 4;
//             }

//             if (!diff.empty())
//                 diff.erase(diff.begin());
//         }

//         cout << n - ans << endl;
//     }
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

// 2nd approch
void solve()
{
    int n;
    int m;

    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> diff;
    diff.push_back(n - (a[m - 1] - a[0] + 1));

    for (int i = 0; i < m - 1; i++)
    {
        diff.push_back(a[i + 1] - a[i] - 1);
    }

    sort(diff.rbegin(), diff.rend());
    int safe = 0;
    int day = 0;

    for (int i = 0; i<diff.size(); i++) {
        int gap = diff[i];
        gap = gap - (day*2);

        if(gap <= 0)
        break;

        safe = safe + gap - 1;

        if(gap == 1)
        safe++;

        day = day + 2; 
    }
    cout << n -safe << endl;
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
