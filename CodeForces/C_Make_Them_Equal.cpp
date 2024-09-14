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
    int n;
    cin >> n;

    char c;
    cin >> c;

    string s;
    cin >> s;

    bool isAll = true;
    int lastIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
            lastIndex = i;

        if (s[i] != c)
            isAll = false;
    }

    if (isAll)
        cout << 0 << endl;

    else if (lastIndex >= n / 2)
    {
        cout << 1 << endl;
        cout << lastIndex+1 << endl;
    }

    else {
        cout << 2 << endl;
        cout << n-1 <<" "<< n << endl;
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