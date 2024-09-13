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
#include <numeric>

using namespace std;

// << ,

// void solve()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> dec(m, vector<int> (n));

//     for(int i = 0; i<n; i++) {
//         for(int j = 0; j<m; j++) {
//             cin >> dec[j][i];
//         }
//     }

//     int ans = 0;

//     for(int i = 0; i<m; i++) {
//         sort(dec[i].begin(), dec[i].end());

//         int sum = accumulate(dec[i].begin(), dec[i].end(), 0);

//         for(int j = 0; j<n; j++) {
//             sum = sum - dec[i][j];

//             ans = ans + (sum - dec[i][j]*(n-j-1));
//         }
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

    vector<int> dec[m];

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            int x;
            cin >> x;

            dec[j].push_back(x);
        }
    }

    for(int i = 0; i<m; i++) 
    sort(dec[i].begin(), dec[i].end());

    int ans = 0;

    for(int i = 0; i<m; i++) {

        vector<int> res(n, 0);
        res[n-1] = dec[i][n-1];

        for(int j = n-2; j>=0; j--) {
            res[j] = res[j+1] + dec[i][j];
        }

        for(int j = 0; j<n-1; j++) {
            int cnt = res[j+1] - (n-1-j)*dec[i][j];
            ans = ans + cnt;
        }
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