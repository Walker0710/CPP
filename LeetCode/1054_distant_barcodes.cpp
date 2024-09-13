#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

#pragma GCC optimize("O3", "unroll-loops")

class compare {
public:
    bool operator()(pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> m;
    for(int i : barcodes) {
        m[i]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxHeap;
    for(auto i : m) {
        maxHeap.push({i.first, i.second});
    }

    vector<int> ans;
    pair<int, int> prev = {-1, -1};

    while (!maxHeap.empty()) {
        auto curr = maxHeap.top();
        maxHeap.pop();

        ans.push_back(curr.first);

        if(prev.second > 0) {
            maxHeap.push(prev);
        }

        curr.second--;
        prev = curr;
    }

    return ans;
}