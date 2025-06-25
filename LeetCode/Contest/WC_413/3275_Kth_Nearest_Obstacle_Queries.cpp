#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> resultsArray(vector<vector<int>> &queries, int k)
{
    int n = queries.size();
    priority_queue<int> pq;
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        int dist = abs(queries[i][0]) + abs(queries[i][1]);

        if (pq.size() < k)
        {
            pq.push(dist);
            if (pq.size() == k)
                ans[i] = pq.top();
        }
        else
        {
            if (dist < pq.top())
            {
                pq.pop();
                pq.push(dist);
            }
            ans[i] = pq.top(); 
        }
    }

    return ans;
}