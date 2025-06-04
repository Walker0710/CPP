#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> minCosts(vector<int> &cost)
{
    int n = cost.size();
    vector<int> answer = {};
    int minimum = cost[0];

    for (int i = 0; i < n; ++i)
    {
        if (minimum > cost[i])
        {
            minimum = cost[i];
        }
        answer.push_back(minimum); 
    }
    return answer;
}