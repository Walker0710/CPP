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
// void solve()
// {
//     int n;
//     cin >> n;
//     int k;
//     cin >> k;

//     vector<int> brigde(n);
//     for (int i = 0; i < n; i++)
//         cin >> brigde[i];

//     int ans = INT_MAX;

//     for (int i = 1; i <= k; i++)
//     {
//         int prev = -1;
//         int curr = -1;
//         int maxi = 0;

//         for (int j = 0; j < n; j++)
//         {
//             if (curr == -1 && brigde[i] == i)
//             {
//                 curr = j;
//             }

//             if (brigde[j] == i && curr != -1)
//             {
//                 maxi = max(maxi, curr - prev - 1);
//                 curr = j;
//             }
//             prev = curr;
//         }

//         maxi = max(maxi, n - curr - 1);
//         ans = min(ans, maxi / 2);
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

// optimise
void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> pos(k+1, 0);
    vector<vector<int>> ans(k+1, {n});

    for(int i = 0; i<n; i++) {
        int dist = i-pos[a[i]];
        ans[a[i]].pop_back();
        ans[a[i]].push_back(dist);
        ans[a[i]].push_back(n-i-1);
        pos[a[i]] = i+1;
    }

    int an = n;

    for(int i = 1; i<=k; i++) {
        sort(ans[i].rbegin(), ans[i].rend());

        if(ans.size() > 1)
        an = min(an, max(ans[i][0]/2, ans[i][1]));

        else 
        an = min(an, ans[i][0]/2);
    }

    cout << an << endl;
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