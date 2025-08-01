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
    int n, q;
    cin >> n >> q;
    
    vector<long long> pref;
    pref.push_back(0);

    vector<int> prefmax;
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
    
        pref.push_back(pref.back() + x);
        if (i == 0)
        {
            prefmax.push_back(x);
        }
    
        else
        {
            prefmax.push_back(max(prefmax.back(), x));
        }
    }
    
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        
        int ind = upper_bound(prefmax.begin(), prefmax.end(), k) - prefmax.begin();
        cout << pref[ind] << " ";
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