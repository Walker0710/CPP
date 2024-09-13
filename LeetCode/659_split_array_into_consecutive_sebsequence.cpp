#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& nums) {

    unordered_map<int, int> map, map1;

    for(int i = 0; i<nums.size(); i++) {
        map[nums[i]]++;
    }

    for(auto i : nums) {
        
        if(map[i] == 0)
        continue;

        map[i]--;

        if(map1[i-1] > 0) {
            map1[i-1]--;
            map1[i]++;
        }

        if(map[i+1] != 0 && map[i+2] != 0) {
            map[i+1]--;
            map[i+2]--;
            map1[i+2]++;
        }

        else {
            return false;
        }
    }
    return true;
}
