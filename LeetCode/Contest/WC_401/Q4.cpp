#include <bits/stdc++.h>

using namespace std;

// << ,

int maxTotalReward(vector<int> &rewards)
{
    sort(begin(rewards), end(rewards));
    int dp[50000] = {}, sz = rewards.size();

    for (int i = 0; i < sz; ++i)
    {
        if (i == 0 || rewards[i - 1] != rewards[i])
        {
            int lim = min(rewards[i], rewards.back() - rewards[i]);

            for (int x = 0; x < lim; ++x)
            {
                dp[rewards[i] + dp[x]] = rewards[i] + dp[x];
            }
        }
    }

    return rewards.back() + *max_element(begin(dp), begin(dp) + rewards.back());
}

int maxTotalReward(vector<int> &rewards)
{
    bitset<50000> dp, mask;
    dp[0] = true;
    sort(begin(rewards), end(rewards));

    int closest = rewards.back() - 1, mask_pos = 0;

    for (int i = 0; i + 1 < rewards.size(); ++i)
    {
        if (mask_pos < rewards[i])
        {
            while (mask_pos < rewards[i])
            {
                mask[mask_pos++] = true;
            }

            dp |= (dp & mask) << rewards[i];
        }
    }

    while (!dp[closest])
    {
        --closest;
    }
    
    return rewards.back() + closest;
}