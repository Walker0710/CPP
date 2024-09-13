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
    int a;
    cin >> a;

    string s = to_string(a);

    if ((s.length() > 3 && s[0] == '1' && s[1] == '0' && s[2] != '0') || (s.length() == 3 && s[0] == '1' && s[1] == '0' && s[2] >= '2')) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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