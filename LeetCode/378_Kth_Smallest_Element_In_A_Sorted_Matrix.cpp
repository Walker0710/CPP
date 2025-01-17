#include <bits/stdc++.h>

using namespace std;

// << ,

int kthSmallest(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    for (int i = 0; i < n; i++)
        pq.push({mat[i][0], {i, 0}});

    for (int i = 0; i < k - 1; i++)
    {
        auto top = pq.top();
        pq.pop();

        int row = top.second.first;
        int col = top.second.second;

        if (col + 1 < n)
        {
            pq.push({mat[row][col + 1], {row, col + 1}});
        }
    }

    return pq.top().first;
}