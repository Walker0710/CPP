#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <string>
#include <functional>

using namespace std;

//first approch
int countDistinct(vector<int> &nums, int k, int p)
{
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j]%p == 0)
                count++;

            if (count <= k)
                ans++;
        }
    }
    return ans;
}

//second approch
struct VectorHash {
    std::size_t operator()(const std::vector<int>& v) const {
        std::size_t hash = 0;
        std::hash<int> hasher;
        for (int i : v) {
            hash ^= hasher(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

int countDistinct(vector<int> &nums, int k, int p) {
    std::unordered_set<std::vector<int>, VectorHash> map;

    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> toPush;
        int count = 0;

        for (int j = i; j < nums.size(); j++)
        {   
            toPush.push_back(nums[j]);

            if (nums[j]%p == 0)
                count++;

            if (count <= k)
                map.insert(toPush);
        }
    }
    return map.size();
}

