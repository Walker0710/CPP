#include <bits/stdc++.h>

using namespace std;

// << ,

int maximumLength(vector<int> &nums)
{
    long long ans = 0;
    map<int, int> freq;

    for (auto n : nums)
    freq[n]++;

    for (auto [k, f] : freq)
    {
        long long t = k;
        int count = 0;

        if (t == 1)
        {
            count += freq[t];
            freq[t] = 0;
        }

        while (t < INT_MAX && freq[t] > 0)
        {
            count += 2;

            if (freq[t] == 1)
            break;

            freq[t] = 0;
            t = t * t;
        }

        if (count % 2 == 0)
        count--;

        ans = max(ans, (long long)count);
    }

    return ans;
}



int maximumLength(vector<int> &nums)
{

    sort(nums.rbegin(), nums.rend());
    map<int, int> mp;

    for (auto ele : nums)
        mp[ele]++;

    int ans;

    if (mp[1] > 0)
        ans = (mp[1] % 2 ? mp[1] : mp[1] - 1);

    else
        ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] == 1) || (i > 0 && nums[i] == nums[i - 1]))
            continue;

        int temp = 1;
        int st = sqrt(nums[i]);
        int curr = nums[i];

        while (curr == st * st)
        {
            if (mp.find(st) != mp.end())
            {
                if (mp[st] > 1)
                {
                    temp += 2;
                    curr = st;
                    st = sqrt(st);
                }

                else
                    break;
            }

            else
                break;
        }

        ans = max(ans, temp);
    }

    return ans;
}