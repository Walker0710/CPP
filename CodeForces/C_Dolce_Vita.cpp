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

// tle on 3
// void solve()
// {
//     int n;
//     int x;

//     cin >> n >> x;

//     vector<int> a(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a.begin(), a.end());

//     vector<int> pref(n);
//     pref[0] = a[0];

//     for (int i = 1; i < n; i++)
//     {
//         pref[i] = pref[i - 1] + a[i];
//     }

//     int finalAns = 0;
//     int day = 0;

//     while (pref[0] + day <= x)
//     {
//         int st = 0;
//         int en = n - 1;
//         int ans = 0;

//         while (st <= en)
//         {
//             int mid = st + (en - st) / 2;

//             if (pref[mid] + day * (mid + 1) <= x)
//             {
//                 ans = mid + 1;
//                 st = mid + 1;
//             }

//             else
//             {
//                 en = mid - 1;
//             }
//         }

//         if (ans == 0)
//             break;

//         finalAns = finalAns + ans;
//         day++;
//     }

//     cout << finalAns << endl;
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
//  << ,



void solve()
{
    long long n;
    long long x;

    cin >> n >> x;

    vector<long long> a(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;
    long long day = 0;

    for(long long i = 1; i<n; i++) {
        a[i] = a[i] + a[i-1];
    }

    for(long long i = n-1; i>=0; i--) {
        a[i] = a[i] + (i+1)*day;

        if((x - a[i]) >= 0) {
            long long days = ((x-a[i])/(i+1)) + 1;
            ans = ans + days*(i+1);
            day = day + days;
        }
    }

    cout << ans << endl;
}

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}