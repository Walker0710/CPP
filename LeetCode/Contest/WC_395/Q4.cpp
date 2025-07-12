#include <bits/stdc++.h>

using namespace std;

// << ,

bool check(vector<int> &nums, int mid)
{

    int n = nums.size();
    unordered_set<int> st;

    int l = 0;
    int ans = 0;

    for (int r = 0; r < n; r++)
    {

        st.insert(nums[r]);

        while (st.size() > mid)
        {
            st.erase(nums[l]);
            l++;
        }

        ans++;
    }

    return ans;
}

int medianOfUniquenessArray(vector<int> &nums)
{
    int st = 0;
    int en = 1000000000;
    int n = nums.size();

    while (st < en)
    {
        int mid = st + (en - st) / 2;
        int cnt = check(nums, mid);

        if (cnt <= n / 2)
        {
            st = mid;
        }

        else
        {
            en = mid - 1;
        }
    }

    return st;
}



long long countAtMostK(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    int n = nums.size();
    int left = 0;
    long long res = 0;

    for (int right = 0; right < n; ++right)
    {
        freq[nums[right]]++;

        while ((int)freq.size() > k)
        {
            freq[nums[left]]--;

            if (freq[nums[left]] == 0)
            freq.erase(nums[left]);
            
            left++;
        }

        res += (right - left + 1);
    }

    return res;
}

int medianOfUniquenessArray(vector<int> &nums)
{
    int n = nums.size();
    long long totalSubarrays = 1LL* n * (n + 1) / 2;
    int low = 1;
    int high = n; 
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long cnt = countAtMostK(nums, mid);

        if (cnt >= (totalSubarrays + 1) / 2)
        {
            ans = mid;
            high = mid - 1;
        }
        
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}