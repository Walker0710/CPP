#include <bits/stdc++.h>

using namespace std;

// << ,

class compare {
public:
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second < b.second;
	}
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> rec;

    for(int i = 0; i<n; i++) {
        rec[nums[i]]++;
    }

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxHeap;

    for(auto paire : rec) {
        maxHeap.push({paire.first, paire.second});
    }

    vector<int> ans;

    for(int i = 0; i<k; i++) {
        int yoo = maxHeap.top().first;
        maxHeap.pop();

        ans.push_back(yoo);
    }

    return ans;
}