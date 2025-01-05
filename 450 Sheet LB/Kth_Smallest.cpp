#include <bits/stdc++.h>

using namespace std;

// << ,

int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 0; i<arr.size(); i++) {
        q.push(arr[i]);
    }

    for(int i = 0; i<k-1; i++) {
        q.pop();
    }

    return q.top();
}