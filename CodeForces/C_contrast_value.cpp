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
//     cin >> n;

//     vector<int> a(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     bool flag = a[0] < a[1];
//     bool flag2 = false;
//     int count = 0;

//     for (int i = 0; i < n; i++)
//     {

//         while (i < n - 1 && a[i] == a[i + 1])
//         {
//             i++;
//             if (i == n - 2)
//                 flag2 = true;
//         }

//         if (!flag2)
//         {
//             while (flag && i < n - 1 && a[i] <= a[i + 1])
//             {
//                 i++;
//             }

//             while (!flag && i < n - 1 && a[i] >= a[i + 1])
//             {
//                 i++;
//             }

//             count++;

//             flag = !flag;
//         }
//     }

//     if (count == 0)
//         cout << 1 << endl;

//     else if (count == 1)
//         cout << 2 << endl;

//     else
//     {
//         cout << 2 * count - 1 << endl;
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
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    n = unique(a.begin(), a.end()) - a.begin();
    int ans = n;

    for (int i = 0; i+2 < n; i++) {
        if(a[i] < a[i+1] && a[i+1] < a[i+2])
        ans = ans - 1;

        if (a[i] > a[i+1] && a[i+1] > a[i+2])
        ans = ans - 1;
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