#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

// tle on 12
//  void solve()
//  {
//      int n;
//      cin >> n;

//     vector<int> a(n);

//     for(int i = 0; i<n; i++) {
//         cin >> a[i];
//     }

//     int q;
//     cin >> q;

//     while(q--) {
//         int l, k;
//         cin >> l >> k;

//         l--;
//         int maxIndex = -1;
//         int value = a[l];

//         for (int i = l; i < n; ++i) {
//             value = value & a[i];

//             if (value < k) {
//                 break;
//             }
//             maxIndex = i;
//         }

//         if(maxIndex == -1) {
//             cout << maxIndex << " ";
//             continue;
//         }

//         cout << maxIndex + 1 << " ";
//     }

//     cout <<endl;
// }

// signed main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

//

bool isPossible(int l, int r, int mid, vector<vector<int>> &pref)
{

    int curr = 0;

    for (int i = 0; i < 32; i++)
    {
        int ss = pref[mid][i];
        if (l != 0)
            ss -= pref[l - 1][i];
        if (ss == mid - l + 1)
            curr += (1 << i);
    }

    return curr >= r;
}

int binarySearch(int l, int r, vector<int> &a, int n, vector<vector<int>> &pref)
{

    int low = l;
    int high = n - 1;

    int ans = -1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;
        if (isPossible(l, r, mid, pref))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans == -1 ? ans : ans + 1;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int q;
    cin >> q;

    vector<vector<int>> pref(n, vector<int>(32, 0));
    for (int i = 0; i < n; i++)
    {

        int v = a[i];
        int p = 0;
        while (v > 0)
        {
            if (v % 2 != 0)
                pref[i][p] += 1;
            v /= 2;
            p++;
        }

        if (i != 0)
        {
            for (int j = 0; j < 32; j++)
                pref[i][j] += pref[i - 1][j];
        }
    }

    for (int i = 0; i < q; i++)
    {

        int l, r;
        cin >> l >> r;

        --l;

        int ind = binarySearch(l, r, a, n, pref);

        cout << ind << " ";
    }

    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}