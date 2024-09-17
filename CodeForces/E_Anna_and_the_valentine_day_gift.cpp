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

using ll = long long;

ll noZero(ll n) {
    ll c = 0;
    while(n > 0) {

        if(n%10 != 0)
        break;

        c++;
        n = n/10;
    }

    return c;
}

ll noDigit(ll n) {
    ll c = 0;
    while(n > 0) {
        c++;
        n = n/10;
    }

    return c;
}

void solve()
{
    ll n;
    ll m;

    cin >> n >> m;
    vector<ll> a(n);

    for(ll i = 0; i<n; i++) {
        cin >> a[i];
    }

    vector<pair<ll, ll>> yoo(n);

    for(ll i = 0; i<n; i++) {
        ll ele = a[i];

        yoo[i].first = noZero(ele);
        yoo[i].second = noDigit(ele);
    }

    sort(yoo.rbegin(), yoo.rend());

    ll ansCount = 0;

    for(ll i = 0; i<n; i++) {
        if(i%2 == 0) {
            ansCount = ansCount + (yoo[i].second - yoo[i].first);
        } 

        else {
            ansCount = ansCount + yoo[i].second;
        }
    }

    if(ansCount >= m+1) 
    cout << "Sasha" << endl;

    else {
        cout << "Anna" << endl;
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
