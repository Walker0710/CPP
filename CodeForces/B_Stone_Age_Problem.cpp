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
    long long q;

    cin >> n >> q;

    vector<long long> a(n);
    long long ans = 0;

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        ans = ans + a[i];
    }

    long long t2 = -1;
    long long t2_value = 0;

    unordered_map<long long, long long> t1;

    for (long long i = 0; i < n; i++)
    {
        t1[i] = 0;
    }

    for (long long i = 0; i < q; i++)
    {
        long long t;
        cin >> t;

        if (t == 1)
        {
            long long index, value;
            cin >> index >> value;
            index--;

            if (t1[index] > t2)
            {
                ans = ans + (value - a[index]);
            }

            else
            {
                ans = ans + (value - t2_value);
            }

            a[index] = value;
            t1[index] = i;
            cout << ans << endl;
        }

        else
        {
            long long value;
            cin >> value;

            t2 = i;
            t2_value = value;

            ans = n * value;

            cout << ans << endl;
        }
    }
}

int main()
{
    solve();

    return 0;
}