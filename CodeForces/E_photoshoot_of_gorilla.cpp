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

void solve()
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    ll k;
    cin >> k;
    ll w;
    cin>>w;

    vector<ll> contriOf(n * m);

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll sRow=max(0ll,i-k+1);
            ll sCol=max(0ll,j-k+1);

            ll eRow=min(i,n-k);
            ll eCol=min(j,m-k);

            contriOf.push_back((eRow-sRow+1)*(eCol-sCol+1));
        }
    }

    sort(contriOf.begin(),contriOf.end());
    reverse(contriOf.begin(),contriOf.end());

    vector<ll> height(w);

    for (ll i = 0; i < w; i++)
    {
        cin>>height[i];
    }

    sort(height.begin(),height.end());
    reverse(height.begin(),height.end());
    ll ans=0;

    for(ll i=0;i<w;i++)
    {
        ans+=(height[i]*contriOf[i]);
    }

    cout<<ans<<endl;
}
 
int main() {
    long long t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

