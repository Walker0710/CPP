#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    KthLargest(int k, vector<int>& nums): k(k){
    
        for(int x: nums) {
            
            pq.push(x);
            
            if (pq.size()> k) 
            pq.pop();
        }
    }

    int add(int val) {
        
        pq.push(val);
        
        if (pq.size()> k) 
        pq.pop();   
        
        return pq.top();      
    }
};