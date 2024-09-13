#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    map<int, bool> m;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            m[nums[i]] = true;
        }
    }

    for (int i = 1; i <= nums.size(); i++) {
        if (m.find(i) == m.end()) {
            return i;
        }
    }

    return nums.size() + 1;
}


//2nd 
int firstMissingPositive(vector<int>& nums) {
    
}