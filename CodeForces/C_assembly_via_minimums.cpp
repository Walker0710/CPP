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

int lastOcc(vector<int> &a, int x)
{
    int s = 0, e = a.size() - 1;
    int result = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (a[mid] == x)
        {
            result = mid;
            s = mid + 1;
        }
        else if (a[mid] > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return result;
}

void solve()
{
    int n;
    cin >> n;

    int size = (n * (n - 1)) / 2;
    vector<int> a(size);

    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> ans;
    int index = 0;
    int num = n-1;

    while (index < size) {
        ans.push_back(a[index]);
        index = index + num;
        num--;
    }

    ans.push_back(1e9);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
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