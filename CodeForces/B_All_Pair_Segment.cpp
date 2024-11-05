#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long
#define vec(v) vector<int> v

// << ,

// void solve()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<int> x(n);
    
//     for(int i = 0; i<n; i++) {
//         cin >> x[i];
//     }

//     unordered_map<int, int> ansTypes;

//     for(int i = 0; i<n-1; i++) {

//         int left = (i*(i+1))/2;
        
//         int yoo = n-2 - i;
//         int right = (yoo*(yoo+1))/2;

//         int all = ((n-1)*(n))/2;

//         ansTypes[all - left - right] += x[i+1] - x[i] + 1; 
//     }

//     while(q--) {
//         int que;
//         cin >> que;

//         int ans = ansTypes[que];

//         cout << ans << " ";
//     }

//     cout << endl;
// }


void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    
    for(int i = 0; i<n; i++) {
        cin >> x[i];
    }

    unordered_map<int, int> map;

    for(int i = 0; i<n; i++) {

        if(i == n-1) {
            map[i]++;
        }

        else {
            int totalSeq = (n-i-1) + (i*(n-i));
            map[totalSeq]++;

            int rem = x[i+1] - x[i] - 1;
            int secSeq = (n-i-1) + ((i) * (n-i-1));
            map[secSeq] += rem; 
        }

    }

    while(q--) {
        int que;
        cin >> que;

        cout << map[que] << " ";
    }

    cout << endl;
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}