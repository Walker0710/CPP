#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(b.second == a.second) {
        return a.first < b.first;
    }

    else {
        return a.second < b.second;
    }
}

// int solveRec(int index, vector<pair<int, int>> m, int l, int a, int b, int first) {
//     if(index > m.size()) {
//         return 0;
//     }

//     if(l < a + b) {
//         return INT_MIN;
//     }

//     //include 
//     int inc = 0;
    
//     if(first == -1)
//     inc = 1 + solveRec(index+1, m, l, m[index].first, 0, index);

//     else 
//     inc = 1 + solveRec(index+1, m, l, a+m[index].first, m[index].second - m[first].second, first); 

//     //exclude
//     int exc = solveRec(index+1, m, l, a, b, first);

//     int ans = max(inc, exc);
//     return ans;
// }

// void solve()
// {
//     int n, l;
//     cin >> n >> l;

//     vector<pair<int, int>> m;

//     for(int i = 0; i<n; i++) {
//         int a, b;
//         cin >> a >> b;

//         m.push_back({a, b});
//     }

//     sort(m.begin(), m.end(), cmp);
//     int ans = solveRec(0, m, l, 0, 0, -1) - 1;

//     cout << ans << endl; 
// }

void solve()
{
    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> m;

    for(int i = 0; i<n; i++) {
        int a, b;
        cin >> a >> b;

        m.push_back({a, b});
    }

    sort(m.begin(), m.end(), cmp);
    int ans = 0;

    for(int i = 0; i<n; i++) {
        priority_queue<int> q;
        int sum = 0; 

        for(int j = i; j < n; j++) {
            q.push(m[j].first);
            sum = sum + m[j].first;

            while(!q.empty() && sum + m[j].second - m[i].second > l) {
                sum = sum - q.top();
                q.pop();
            }

            ans = max(ans, (int)q.size());
        }
    }

    cout << ans << endl;
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



