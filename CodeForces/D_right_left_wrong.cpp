#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <numeric> 

using namespace std;

// << ,
void solve()
{
    long long n;
    cin >> n;

    vector<long long> a(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    string b;
    cin >> b;

    long long l = 0;
    long long r = n - 1;

    long long ans = 0;

    while (l < r)
    {
        while (l < r && b[l] != 'L')
            l++;

        while (r > l && b[r] != 'R')
            r--;

        if (l < r) {
            long long sum = accumulate(a.begin() + l, a.begin() + r + 1, 0);
            ans += sum;

            l++;
            r--;
        }
    }

    cout << ans << endl;
}

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}



//2nd 
void solve()
{
    long long n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> prefix(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    prefix[0] = a[0];

    for(long long i = 1; i<n; i++) {
        prefix[i] = a[i] + prefix[i-1];
    }

    string b;
    cin >> b;

    long long l = 0;
    long long r = n - 1;

    long long ans = 0;

    while (l <= r)
    {
        if(b[l] == 'R') 
        l++;

        else {
            if(b[r] == 'L')
            r--;

            else {
                ans = ans + prefix[r];

                if(l > 0) {
                    ans = ans - prefix[l-1];
                }

                l++;
                r--;
            }
        }

    }

    cout << ans << endl;
}

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}