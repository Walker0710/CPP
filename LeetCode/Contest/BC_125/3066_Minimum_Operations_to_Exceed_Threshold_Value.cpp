#include <bits/stdc++.h>

using namespace std;

// << ,

#define ll long long

int minOperations(vector<int> &nums, int k)
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (auto x : nums)
    {
        pq.push(x);
    }

    ll cnt = 0;

    while (pq.size() >= 2)
    {
        if (pq.top() >= k)
        {
            return cnt;
        }

        ll one = pq.top();
        pq.pop();

        ll two = pq.top();
        pq.pop();

        pq.push(min(one, two) * 2 * 1LL + max(one, two));

        cnt++;
    }

    return cnt;
}