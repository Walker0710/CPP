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

#define ll long long

// << ,

//first approch
void solve()
{
    priority_queue<ll> odd;                             // max heap
    priority_queue<ll, vector<ll>, greater<ll>> even; // min heap

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        ll toPush;
        cin >> toPush;

        if (toPush % 2 == 1)
            odd.push(toPush);

        else
            even.push(toPush);
    }

    ll ans = 0;
    bool flag = false;

    while (!odd.empty() & !even.empty())
    {
        ll oddFr = odd.top();
        odd.pop();

        ll evenFr = even.top();
        even.pop();

        if (oddFr > evenFr)
        {
            odd.push(oddFr + evenFr);
            odd.push(oddFr);
            ans++;
        }

        else
        {
            odd.push(oddFr + evenFr);
            even.push(evenFr);
            ans++;
        }
    }

    cout << ans << endl;
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

//2nd approch
ll solve2(vector<ll> &even, vector<ll> &odd)
{
    ll n1 = even.size();
    ll n2 = odd.size();
    ll max = odd.back();

    if (max < even[0])
    {
        return (n1 + 1);
    }

    ll ans = 0;
    
    for (ll i = 0; i < n1; i++)
    {
        if (even[i] > max)
        {
            return (n1 + 1);
        }
        else
        {
            ans++;
            max += even[i];
        }
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> odd, even;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x % 2)
        {
            odd.push_back(x);
        }
        else
        {
            even.push_back(x);
        }
    }
    if (odd.size() == 0 || even.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    ll ans = solve2(even, odd);
    cout << ans << endl;
}
 
int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}