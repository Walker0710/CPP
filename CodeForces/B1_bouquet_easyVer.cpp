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
// without binary search
// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a.begin(), a.end());

//     int ans = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int budget = m;
//         int sum = 0;

//         for (int j = i; j < n && (a[j] - a[i] <= 1); j++)
//         {
//             if (budget >= a[j])
//             {
//                 sum += a[j];
//                 budget -= a[j];
//             }
//             else
//             {
//                 break;
//             }
//         }

//         ans = max(ans, sum);
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


//with binary search
// int lastOcc(vector<int> &a, int x)
// {
//     int s = 0, e = a.size() - 1;
//     int result = -1;

//     while (s <= e)
//     {
//         int mid = s + (e - s) / 2;

//         if (a[mid] == x)
//         {
//             result = mid;
//             s = mid + 1; // Move to the right half to find the last occurrence
//         }
//         else if (a[mid] > x)
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//     }

//     return result;
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a.begin(), a.end());

//     int ans = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int budget = m;
//         int sum = 0;

//         int j = i;
//         while (j < n && (a[j] - a[i] <= 1))
//         {
//             if (budget >= a[j])
//             {
//                 sum += a[j];
//                 budget -= a[j];
//             }
//             else
//             {
//                 break;
//             }
//             j++;
//         }

//         ans = max(ans, sum);
        
//         // Use `lastOcc` to skip all duplicates and similar elements
//         i = lastOcc(a, a[i]);
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

//yoo
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;
    long long sum = 0;

    for (long long l = 0, r = 0; l < n; ) {
        while(r<n && a[r]-a[l] <= 1 && sum + a[r] <= m) {
            sum += a[r];
            r++;
        }

        ans = max(ans, sum);
        sum -= a[l];
        l++;
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