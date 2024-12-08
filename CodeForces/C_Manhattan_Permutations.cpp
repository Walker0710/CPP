// #include <bits/stdc++.h>

// using namespace std;

// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// #define int long long

// // << ,

// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     int maxK = 0;
//     int rev = n;

//     for(int i = 1; i<=n; i++) {
//         maxK += abs(rev - i);
//         rev--;
//     }

//     if(k%2 == 1 && k > maxK) {
//         cout << "NO" << endl; 
//     }

//     else {
//         cout << "YES" << endl;

//         int first = 1;
//         int last = n;

//         vector<int> v(n);

//         for(int i = 0; i<n; i++) {
//             v[i] = i+1;
//         }

//         while(k > 0) {
            
//             if(k >= 2*(last - first)) {

//                 swap(v[first - 1], v[last - 1]);
//                 k -= 2*(last - first);
//                 first++;
//                 last--;
//             }

//             else {
//                 last--;
//             }
//         }

//         for(int i = 0; i<n; i++) {
//             cout << v[i] << " ";
//         }

//         cout << endl;
//     }
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




#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    if(k%2) {
        cout << "NO" << endl;
        return ;
    }

    vector<int> a(n+1);

    for(int i = 1; i < n+1; i++) {
        a[i] = i;
    }

    k = k/2;
    int x = n-1;

    for(int i = 1; i<n+1; i++) {
        if(k <= x) {
            swap(a[i], a[i+k]);
            k = 0;
            break;
        }

        swap(a[i], a[i+x]);
        k -= x;
        x -= 2;

        if(x <= 0) {
            break;
        }
    }

    if(k > 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    for(int i = 1; i<n+1; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
