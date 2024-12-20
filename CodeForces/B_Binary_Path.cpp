#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

// void solve()
// {
//     int n;
//     cin >> n;

//     string one;
//     cin >> one;

//     string two;
//     cin >> two;

//     string ans;

//     for(int i = 1; i<=n; i++) {

//         string s = one.substr(0, i) + two.substr(i-1, n);
//         if (ans.empty() || ans > s) {               
//             ans = s;
//         }
//     }

//     int count = 0;

//     for(int i = 1; i<=n; i++) {

//         string s = one.substr(0, i) + two.substr(i-1, n);

//         if(s == ans) {
//             count++;
//         }
//     }

//     cout << ans << endl;
//     cout << count << endl;
// }

void solve()
{
    int n;
    cin >> n;

    string arr[2][n];

    for(int i = 0; i<2; i++) {
        string s;
        cin >> s;

        for(int j = 0; j<n; j++) {
            string x = "";
            x += s[j];
            arr[i][j] = x;
        }
    }

    string ans = arr[0][0];
    int ways = 1;
    int i = 0, j = 0, x = 1;

    while(j < n-1) {
        
        if(i == 0) {
            if(arr[i][j+1] == "1" && arr[i+1][j] == "0") {
                ans = ans + arr[i+1][j];
                i++;
                ways = x;
                x = 1;
            }

            else if(arr[i][j+1] == arr[i+1][j]) {
                ans = ans + arr[i][j+1];
                j++;
                x++;
            }

            else {
                ans = ans + arr[i][j+1];
                j++;
                x = 1;
            }
        }

        else {
            ans = ans + arr[i][j+1];
            j++;
        }
    }

    if(i == 0) {
        ans = ans + arr[1][n-1];
        ways = x;
    }

    cout << ans << endl;
    cout << ways << endl;
}



signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
