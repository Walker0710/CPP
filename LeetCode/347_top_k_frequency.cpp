#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

class compare
{
public:
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second < b.second;
	}
};

vector<int> topKFrequent(vector<int> &nums, int k)
{

	unordered_map<int, int> map;

	for (int i = 0; i < nums.size(); i++)
	{
		map[nums[i]]++;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxHeap;

	for (const auto &numAndFre : map)
	{
		int num = numAndFre.first;
		int fre = numAndFre.second;

		maxHeap.push({num, fre});
	}

	vector<int> ans(k);

	for (int i = 0; i < k; i++)
	{
		pair<int, int> a = maxHeap.top();
		maxHeap.pop();
		ans.push_back(a.first);
	}
	return ans;
}
