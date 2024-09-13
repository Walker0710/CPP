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

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        int toPush;
        cin >> toPush;

        a[i] = toPush;
    }

    int m;
    cin >> m;

    vector<string> b(m);

    for (int i = 0; i < m; i++)
    {
        string toPush;
        cin >> toPush;

        b[i] = toPush;
    }

    for(int i = 0; i < m; i++) {

        string s = b[i];
        bool flag = true;

        if(s.length() == n) {
            unordered_map<int, set<char>> forA;
            unordered_map<char, set<int>> forB;

            for(int j = 0; j<n; j++) {
                forA[a[j]].insert(s[j]);
                forB[s[j]].insert(a[j]);

                if(forA[a[j]].size() > 1 || forB[s[j]].size() > 1) {
                    flag = false;
                    break;
                }
            }
        }

        else {
            flag = false;
        }

        if(flag) {
            cout<<"YES"<<endl;
        }

        else {
            cout<<"NO"<<endl;
        }
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


