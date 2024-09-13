#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

//brut force 
bool carPooling(vector<vector<int>> &trips, int capacity)
{
    unordered_map<int, int> mp;
    for (auto i : trips)
    {
        for (int j = i[1]; j < i[2]; j++)
        {
            mp[j] += i[0];
            if (mp[j] > capacity)
                return false;
        }
    }
    return true;
}

//
bool carPooling(vector<vector<int>> &trips, int capacity) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for(auto i : trips) {
        pair<int, int> toPush = {i[1], i[0]};
        minHeap.push({i[1], i[0]});
        minHeap.push({i[2], -i[0]});
    }

    int number = 0;

    while(!minHeap.empty()) {
        number += minHeap.top().second;
        minHeap.pop();

        if(number > capacity)
        return false;
    }
    return true;
}