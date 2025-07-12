#include <bits/stdc++.h>

using namespace std;

// << ,

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    if (hand.size() % groupSize != 0)
        return false;

    unordered_map<int, int> count;
    for (int num : hand)
        count[num]++;

    sort(hand.begin(), hand.end());
    for (int num : hand)
    {
        if (count[num] > 0)
        {
            for (int i = num; i < num + groupSize; i++)
            {
                if (count[i] == 0)
                    return false;
                count[i]--;
            }
        }
    }
    return true;
}

bool isPossibleDivide(vector<int> &nums, int k)
{
    if (nums.size() % k != 0)
    return false;

    unordered_map<int, int> count;
 
    for (int num : nums)
    count[num]++;

    sort(nums.begin(), nums.end());

    for (int num : nums)
    {
        if (count[num] > 0)
        {
            for (int i = num; i < num + k; i++)
            {
                if (count[i] == 0)
                return false;
                
                count[i]--;
            }
        }
    }

    return true;
}