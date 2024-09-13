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

// tle
// can be optimize by using 1d vector to store the last element only
// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);

//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     sort(a.begin(), a.end());

//     vector<vector<int>> rec;

//     for (int i = 0; i < n; i++)
//     {

//         int ele = a[i];
//         bool flag = false;

//         for (int j = 0; j < rec.size(); j++)
//         {
//             if (rec[j].back() == ele - 1)
//             {
//                 rec[j].push_back(ele);
//                 flag = true;
//                 break;
//             }
//         }

//         if (!flag)
//         {
//             vector<int> a;
//             a.push_back(ele);
//             rec.push_back(a);
//         }
//     }

//     int size = rec.size();

//     cout << size << endl;
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

// 2nd
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    set<int> b;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
        b.insert(a[i]);
        b.insert(a[i] + 1);
    }
    int last = 0;
    int res = 0;
    for (auto x : b)
    {
        int c = cnt[x];
        res += max(0, c - last);
        last = c;
    }
    cout << res << endl;
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