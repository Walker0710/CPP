#include <bits/stdc++.h>

using namespace std;

// << ,

class SlidingMedian
{
    multiset<int> low, high;
    long long firstHalfSum, secondHalfSum;

    void balance()
    {
        // adjust the sizes
        // while left half is greater than right half
        while (low.size() > high.size() + 1)
        {
            // take max of left and insert it in right half
            int leftMax = *low.rbegin();
            low.erase(low.find(leftMax));
            firstHalfSum -= leftMax;

            high.insert(leftMax);
            secondHalfSum += leftMax;
        }
        // while right half is greater than left half
        while (low.size() < high.size())
        {
            // take right min and insert it in left half
            int rightMin = *high.begin();
            high.erase(high.begin());
            secondHalfSum -= rightMin;

            low.insert(rightMin);
            firstHalfSum += rightMin;
        }
    }

public:
    SlidingMedian()
    {
        low.clear();
        high.clear();
        firstHalfSum = secondHalfSum = 0;
    }

    void insert(int x)
    {
        if (low.empty() || x <= *low.rbegin())
        {
            low.insert(x);
            firstHalfSum += x;
        }
        else
        {
            high.insert(x);
            secondHalfSum += x;
        }
        balance();
    }

    void remove(int x)
    {
        if (low.find(x) != low.end())
        {
            low.erase(low.find(x));
            firstHalfSum -= x;
        }
        else if (high.find(x) != high.end())
        {
            high.erase(high.find(x));
            secondHalfSum -= x;
        }
        balance();
    }

    int getMedian()
    {
        if (low.empty())
            return -1;
        return *low.rbegin();
    }

    long long getCost()
    {
        int mid = getMedian();
        int l = low.size();
        int r = high.size();

        return 1LL * (1LL * l * mid - firstHalfSum) + (secondHalfSum - 1LL * r * mid);
    }
};

class Solution
{
    vector<long long> cost;
    int n;
    int window;
    long long dp[100005][16];

    long long calc(int ind, int k)
    {
        if (ind >= cost.size())
        {
            return (k == 0 ? 0LL : (long long)1e18);
        }

        long long &res = dp[ind][k];
        
        if (res != -1)
            return res;
        
            // if we skip from here
        long long ans = calc(ind + 1, k);
        
        // if we select this subarray
        if (k > 0)
            ans = min(ans, cost[ind] + calc(ind + window, k - 1));

        return res = ans;
    }

public:
    long long minOperations(vector<int> &nums, int x, int k)
    {
        // size of window is x
        n = nums.size();
        window = x;
        SlidingMedian sm;

        for (int i = 0; i < x; i++)
            sm.insert(nums[i]);
            
        cost.push_back(sm.getCost());

        for (int i = x; i < n; i++)
        {
            sm.insert(nums[i]);
            sm.remove(nums[i - x]);
            cost.push_back(sm.getCost());
        }

        memset(dp, -1LL, sizeof(dp));
        // dp, starting from zero we find where to do the operations
        return calc(0, k);
    }
};