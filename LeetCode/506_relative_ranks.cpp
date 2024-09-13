#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

class compare {
	public:
	  bool operator()(pair<int, int> a, pair<int, int> b) {
	  	return a.first < b.first;
	  }
};

vector<string> findRelativeRanks(vector<int>& score) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxHeap;

    for(int i = 0; i<score.size(); i++) {
        pair<int, int> a = {score[i], i};
        maxHeap.push(a);
    }

    vector<string> ans(score.size());
    int rank = 1;

    while(!maxHeap.empty()) {
        pair<int, int> yo = maxHeap.top();
        maxHeap.pop();
        int index = yo.second;

        if(rank == 1) {
            ans[index] = "Gold Medal";
        }

        else if(rank == 2) {
            ans[index] = "Silver Medal";
        }
        
        else if(rank == 3) {
            ans[index] = "Bronze Medal";
        }

        else {
            ans[index] = to_string(rank);
        }
        rank++;
    }

    return ans;
}