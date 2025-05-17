#include <bits/stdc++.h>

using namespace std;

// << ,

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> maxHeap;

    for (auto i : stones)
    {
        maxHeap.push(i);
    }

    while (maxHeap.size() > 1)
    {
        int first = maxHeap.top();
        maxHeap.pop();

        int second = maxHeap.top();
        maxHeap.pop();

        if (first > second)
            maxHeap.push(first - second);
    }

    if (maxHeap.size() == 1)
        return maxHeap.top();

    return 0;
}