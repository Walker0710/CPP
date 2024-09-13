#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &arr, int k)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> ans;
    
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0], arr[i][1]}});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        pair<int, int> p = pq.top().second;
        ans.push_back(vector<int>{p.first, p.second});
        pq.pop();
    }
    return ans;
}