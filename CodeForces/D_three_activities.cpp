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

vector<int> largest3(const vector<int> &a)
{

    vector<int> index(3, -1);

    for (int i = 0; i < a.size(); ++i)
    {

        if (index[0] == -1 || a[i] > a[index[0]])
        {
            index[2] = index[1];
            index[1] = index[0];
            index[0] = i;
        }

        else if (index[1] == -1 || a[i] > a[index[1]])
        {
            index[2] = index[1];
            index[1] = i;
        }

        else if (index[2] == -1 || a[i] > a[index[2]])
        {
            index[2] = i;
        }
    }
    return index;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        cin >> c[i];

    int ans = 0;

    vector<int> largA = largest3(a);
    vector<int> largB = largest3(b);
    vector<int> largC = largest3(c);

    for (int x : largA)
    {
        for (int y : largB)
        {
            for (int z : largC)
            {
                if (x != y && x != z && y != z)
                {
                    ans = max(ans, a[x] + b[y] + c[z]);
                }
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
