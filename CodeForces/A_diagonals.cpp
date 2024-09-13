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
    int k;
    cin >> n;
    cin >> k;

    if (k == 0)
        cout << 0 << endl;

    else
    {
        int ans = 1;
        k = k - n;
        n--;

        while (k > 0)
        {
            if(k <= n) {
                ans++;
                break;
            }

            else if(k > n && k <= 2*n) {
                ans = ans + 2;
                break;
            }

            else {
                ans = ans + 2;
                k = k - 2*n;
                n--;
            }
        }

        cout << ans << endl;
    }
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