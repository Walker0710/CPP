#include <bits/stdc++.h>

using namespace std;

// << ,
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() > curr)
        s.pop();

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();
    vector<int> yoo = nextSmallerElement(prices, prices.size());

    vector<int> ans;

    for(int i = 0; i<n; i++) {
        
        if(yoo[i] == -1) {
            ans.push_back(prices[i]);
        }

        else {
            ans.push_back(prices[i] - yoo[i]);
        }
    }

    return ans;
}
