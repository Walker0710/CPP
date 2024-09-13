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

// 1st approch
// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> x(n);
//     vector<int> y(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> x[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cin >> y[i];
//     }

//     vector<int> diff(n);

//     for (int i = 0; i < n; i++)
//     {
//         diff[i] = y[i] - x[i];
//     }

//     sort(diff.begin(), diff.end());

//     int ans = 0;

//     for (int s = 0; diff[s] < 0; s++)
//     {
//         int grp = 0;
//         int e = n - 1;

//         while (s < e)
//         {
//             int sum = diff[s] + diff[e];

//             while (s < e && diff[e] >= 0 && sum < 0) {
//                 e--;
//                 sum = sum + diff[e];
//             }

//             if(sum >= 0)
//             grp++;
            
//             s++;
//             e--;
//         }

//         ans = max(ans, grp);
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



//2nd approch
void solve() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    vector<int> diff(n);

    for (int i = 0; i < n; i++) {
        diff[i] = y[i] - x[i];
    }

    sort(diff.begin(), diff.end());

    int s = 0, e = n - 1;
    int ans = 0;

    while (s < e) {
        
        if (diff[s] + diff[e] >= 0) {
            ans++;
            s++;
            e--;
        } 
        
        else {
            s++;
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}