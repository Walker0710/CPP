#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

// tle on 7
// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     unordered_map<int, vector<pair<int, int>>> a;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int c;
//             cin >> c;

//             a[c].push_back({i, j});
//         }
//     }

//     int ans = 0;

//     for (auto it = a.begin(); it != a.end(); it++)
//     {
//         vector<pair<int, int>> yoo = it->second;

//         for (int i = 0; i < yoo.size(); i++)
//         {
//             for (int j = i + 1; j < yoo.size(); j++)
//             {
//                 ans = ans + abs(yoo[i].first - yoo[j].first) + abs(yoo[i].second - yoo[j].second);
//             }
//         }
//     }

//     cout << ans << endl;
// }

void solve()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> fir;
    unordered_map<int, vector<int>> sec;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int c;
            cin >> c;

            fir[c].push_back(i + 1);
            sec[c].push_back(j + 1);
        }
    }

    int ans = 0;

    for (auto it = fir.begin(); it != fir.end(); it++)
    {
        vector<int> yoo = it->second;
        int vecSize = yoo.size();
        sort(all(yoo));

        int sum = 0;
        for (int i = 0; i < vecSize; i++)
        {
            sum = sum + yoo[i];
        }

        for (int i = 0; i < vecSize; i++)
        {
            sum = sum - yoo[i];
            ans = ans + (sum - (vecSize - i - 1)*yoo[i]);
        }
    }

    for (auto it = sec.begin(); it != sec.end(); it++)
    {
        vector<int> yoo = it->second;
        int vecSize = yoo.size();
        sort(all(yoo));

        int sum = 0;
        for (int i = 0; i < vecSize; i++)
        {
            sum = sum + yoo[i];
        }

        for (int i = 0; i < vecSize; i++)
        {
            sum = sum - yoo[i];
            ans = ans + (sum - (vecSize - i - 1)*yoo[i]);
        }
    }

    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
