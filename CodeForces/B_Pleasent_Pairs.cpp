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

void solve()
{
    long long n;
    cin >> n;

    vector<pair<long long, long long>> a(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    long long ans = 0;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = i+1; j < n; j++)
        {
            long long value = a[i].first*a[j].first;  

            if (value > 2 * n)
            {
                break;
            }

            if(value == a[i].second + a[j].second) {
                ans++;
            }
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