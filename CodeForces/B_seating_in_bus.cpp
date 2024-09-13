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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i<n; i++) {
        int toPush;
        cin >> toPush;

        a[i] = toPush;
    }

    unordered_map<int, bool> rec;
    rec[a[0]] = true;
 
    int i = 1;
    bool flag = false;

    while(i < n) {
        int seat = a[i];

        if(rec[seat - 1] == false && rec[seat + 1] == false) {
            flag = true;
            break;
        }

        rec[seat] = true;
        i++;
    }

    if(flag) {
        cout << "NO" << endl;
    }

    else {
        cout << "YES" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}