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

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        int toPush;
        cin >> toPush;
        a[i] = toPush;
    }

    int arr1 = 0;
    int arr2 = -1;
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr2 == -1)
        {
            if (a[i] > a[arr1])
            {
                arr2 = i;
            }

            else
            {
                arr1 = i;
            }
        }

        else
        {
            if (a[i] > a[arr1] && a[i] > a[arr2])
            {
                if (a[arr1] > a[arr2])
                {
                    arr2 = i;
                }

                else
                {
                    arr1 = i;
                }
                ans++;
            }

            else if (a[i] < a[arr1] && a[i] < a[arr2])
            {
                if (a[arr1] > a[arr2])
                {
                    arr2 = i;
                }

                else
                {
                    arr1 = i;
                }
            }

            else if ((a[i] > a[arr1] && a[i] < a[arr2]) || a[i] == a[arr2])
            {
                arr2 = i;
            }

            else
            {
                arr1 = i;
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