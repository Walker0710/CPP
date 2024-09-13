#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

class compare {
	public:
	  bool operator()(pair<int, int> a, pair<int, int> b) {
	  	return a.second < b.second;
	  }
};

 string frequencySort(string s) {

	unordered_map<char, int> map;
	
    for(int i = 0; i<s.length(); i++) {
		map[s[i]]++;
	}	

	priority_queue<pair<char, int>, vector<pair<char, int>>, compare> maxHeap;

	for(const auto& numAndFre : map) {
	char alpha = numAndFre.first;
	int fre = numAndFre.second;

	maxHeap.push({alpha, fre});
	}

	string ans;

	while(!maxHeap.empty()) {
		pair<char, int> a = maxHeap.top();
        
        char yo = a.first;
        int freq = a.second;

        string toPush(freq, yo);
		maxHeap.pop();
		
        ans = ans + toPush;	
	}
	return ans;
}
