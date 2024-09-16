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

// que glat smja tha
// void solve()
// {
//     int n;
//     cin >> n;

//     string str;
//     cin >> str;

//     int ans = 0;
//     int s = 0;
//     int e = n - 1;

//     while (s <= e)
//     {
//         if (str[s] == str[e])
//         {
//             s++;
//             e--;
//         }

//         else
//         {
//             if (str[s] == str[e - 1])
//             {
//                 ans++;
//                 e--;
//             }

//             else if (str[s + 1] == str[e])
//             {
//                 ans++;
//                 s++;
//             }

//             else
//             {
//                 ans = ans + 2;
//                 s++;
//                 e--;
//             }
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

// correct way

// << ,
void solve()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    unordered_set<char> set;

    for(int i = 0; i<n; i++) {
        set.insert(str[i]);
    }

    int ans = INT_MAX;

    for (char toErase : set) {
        int s = 0;
        int e = n-1;
        int tempAns = 0;

        while (s <= e) {
            if(str[s] == str[e]) {
                s++;
                e--;
            }

            else {
                if(str[s] == toErase) {
                    tempAns++;
                    s++;
                }

                else if(str[e] == toErase) {
                    tempAns++;
                    e--;
                }

                else {
                    tempAns = INT_MAX;
                    break;
                }
            }
        }

        ans = min(ans, tempAns);
    }

    if(ans == INT_MAX)
    cout << -1 << endl;

    else
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