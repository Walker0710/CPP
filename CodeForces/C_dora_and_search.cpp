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
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int s = 0;
    int e = n - 1;
    int min = 1;
    int max = n;
    
    while (s <= e) {
        if (a[s] == min) {
            s++;
            min++;
        } else if (a[s] == max) {
            s++;
            max--;
        } else if (a[e] == min) {
            e--;
            min++;
        } else if (a[e] == max) {
            e--;
            max--;
        } else {
            break;
        }
    }

    if(s <= e)
    cout << s + 1 << " " << e + 1 << endl;
    
    else
    cout << -1 << endl;
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