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

int solve2(vector<vector<int>> &matrix, int i, int j, int k) {

    if(i == matrix.size() || j == matrix[0].size()) {
        k--;
        return 0;
    }

    int ans = 0;

    ans = 1 + min(solve2(matrix, i+1, j, k), solve2(matrix, i, j+1, k));
}

void solve() {
    int k;
    cin >> k;

    int a;
    cin >> a;
    int b;
    cin >> b;

    vector<vector<int>> matrix(a, vector<int> (b, 0));

    int ans = solve2(matrix, 0, 0, k);


}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}