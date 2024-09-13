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

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    int ans = 0;

    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int currR = i, currC = j;
            int prevC = currC;
            int sum = a[currR][currC];

            currC = n - currR - 1;
            currR = prevC;
            sum += a[currR][currC];

            prevC = currC;
            currC = n - currR - 1;
            currR = prevC;
            sum += a[currR][currC];
            
            prevC = currC;
            currC = n - currR - 1;
            currR = prevC;
            sum += a[currR][currC];
            
            ans += min(sum, 4 - sum);
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

